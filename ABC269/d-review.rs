use std::{io, collections};

struct UnionFind {
    parents: Vec<usize>,
    sizes: Vec<usize>,
}

impl UnionFind {
    fn new(length: usize) -> UnionFind {
        let mut uf = UnionFind { parents: vec![0; length], sizes: vec![0; length] };
        for i in 0..length {
            uf.parents[i] = i;
        }
        uf
    }

    fn root(&mut self, u: usize) -> usize {
        if self.parents[u] == u {
            return u;
        }
        let r = self.root(self.parents[u]);
        self.parents[u] = r;
        r
    }

    fn equiv(&mut self, u: usize, v: usize) -> bool {
        self.root(u) == self.root(v)
    }

    fn unite(&mut self, u: usize, v: usize) {
        let u_root = self.root(u);
        let v_root = self.root(v);
        if u_root == v_root {
            return;
        }
        self.parents[u_root] = v_root;
        self.sizes[v_root] += self.sizes[u_root];
        self.sizes[u_root] = 0;
    }
}

#[derive(Eq, Hash, PartialEq, Clone, Copy)]
struct Point(i32, i32);

fn main() {
    let cin = io::stdin();
    let n: usize = {
        let mut s = String::new();
        cin.read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };
    let mut points: Vec<Point> = vec![];
    let mut indices: collections::HashMap<Point, usize> = collections::HashMap::new();
    for i in 0..n {
        let p: Point = {
            let mut s = String::new();
            cin.read_line(&mut s).unwrap();
            let v: Vec<i32> = s
                .trim()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect();
            Point(v[0], v[1])
        };
        points.push(p);
        indices.insert(p, i);
    }
    let mut uf = UnionFind::new(n);
    for (i, p) in points.iter().enumerate() {
        for (dx, dy) in vec![
            (-1, -1), (-1, 0), (0, -1), (0, 1), (1,1)
        ] {
            let np = Point(p.0 + dx, p.1 + dy);
            if let Some(j) = indices.get(&np) {
                uf.unite(i, *j);
            }
        }
    }
    let roots: collections::HashSet<usize> = (0..n)
        .into_iter()
        .map(|i| uf.root(i))
        .collect();
    println!("{}", roots.len());
}
