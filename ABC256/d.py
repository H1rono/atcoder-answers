from dataclasses import dataclass


@dataclass(frozen=True)
class Section:
    left: int
    right: int

    def __contains__(self, other):
        if isinstance(other, Section):
            return self.left <= other.left and other.right <= self.right
        return (self.left <= other < self.right)

    def crosses(self, other):
        return (
            self.left <= other.left <= self.right
            or self.left <= other.right <= self.right
        )

    def merge(self, other):
        return Section(
            min(self.left, other.left),
            max(self.right, other.right)
        )

    def __gt__(self, other):
        return other.right < self.left

    def __lt__(self, other):
        return self.right < other.left

sections = []

def index_section(sec):
    ng, ok = -1, len(sections)
    while ok - ng > 1:
        mid = (ok + ng) // 2
        if sections[mid] < sec:
            ng = mid
        else:
            ok = mid
    return ok


def add_section(sec: Section):
    i = index_section(sec)
    if i == len(sections) or sec < sections[i]:
        sections.insert(i, sec)
        return
    nsec = sec.merge(sections[i])
    sections[i] = nsec
    while i + 1 < len(sections) and nsec.crosses(sections[i + 1]):
        nsec = sections[i + 1]
        sections.pop(i + 1)

n = int(input())

for i in range(n):
    l, r = map(int, input().split())
    add_section(Section(l, r))

for sec in sections:
    print(sec.left, sec.right)
