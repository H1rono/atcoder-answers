use std::{
    collections::{HashSet, VecDeque},
    ops::{Add, AddAssign, Sub, SubAssign},
};

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
struct Point {
    x: i32,
    y: i32,
}

impl Point {
    pub fn new(x: i32, y: i32) -> Self {
        Self { x, y }
    }
}

impl Add for Point {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self::new(self.x + rhs.x, self.y + rhs.y)
    }
}

impl AddAssign for Point {
    fn add_assign(&mut self, rhs: Self) {
        self.x += rhs.x;
        self.y += rhs.y;
    }
}

impl Sub for Point {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self::new(self.x - rhs.x, self.y - rhs.y)
    }
}

impl SubAssign for Point {
    fn sub_assign(&mut self, rhs: Self) {
        self.x -= rhs.x;
        self.y -= rhs.y;
    }
}

fn push_p(que: &mut VecDeque<(usize, Point)>, dist_max: &[Point], goal: Point, i: usize, p: Point) {
    let Point { x, y } = dist_max[i];
    if (goal.x - p.x).abs() <= x || (goal.y - p.y).abs() <= y {
        que.push_back((i + 1, p));
    }
}

fn main() {
    proconio::input! {
        n: usize, x: i32, y: i32,
        nums: [i32; n]
    }
    let goal = Point::new(x, y);
    let mut dist_max: Vec<_> = (0..n)
        .rev()
        .scan(Point::new(0, 0), |state, i| {
            *state += if i % 2 == 0 {
                Point::new(nums[i], 0)
            } else {
                Point::new(0, nums[i])
            };
            Some(*state)
        })
        .collect::<Vec<_>>();
    dist_max.reverse();
    let mut que = VecDeque::new();
    let mut seen: Vec<_> = (0..n).map(|_| HashSet::new()).collect();
    let p0 = Point::new(nums[0], 0);
    push_p(&mut que, &dist_max, goal, 0, p0);
    while let Some((i, p0)) = que.pop_front() {
        if seen[i - 1].contains(&p0) {
            continue;
        }
        seen[i - 1].insert(p0);
        if i == n {
            if p0 == goal {
                println!("Yes");
                return;
            }
            continue;
        }
        let dp = if i % 2 == 0 {
            // ----> x
            Point::new(nums[i], 0)
        } else {
            // ----> y
            Point::new(0, nums[i])
        };
        push_p(&mut que, &dist_max, goal, i, p0 + dp);
        push_p(&mut que, &dist_max, goal, i, p0 - dp);
    }
    println!("No");
}
