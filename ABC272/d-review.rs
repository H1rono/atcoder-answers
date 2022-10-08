use std::collections::VecDeque;

#[derive(Clone, Copy)]
struct Point {
    x: i64,
    y: i64,
}

impl Point {
    fn new(x: i64, y: i64) -> Self {
        Self { x, y }
    }

    fn mag_sq(&self) -> i64 {
        self.x * self.x + self.y * self.y
    }

    fn add(&self, other: &Self) -> Self {
        Self { x: self.x + other.x, y: self.y + other.y }
    }
}

fn main() {
    proconio::input! {
        n: usize, m: i64
    }
    let mut mag_m_points = Vec::new();
    let mut reg_point = |point: Point| {
        mag_m_points.push(point);
        if point.x != point.y {
            mag_m_points.push(Point::new(point.y, point.x));
        }
    };
    for x in 0 .. n as i64 {
        for y in x .. n as i64 {
            let p = Point::new(x, y);
            if p.mag_sq() != m {
                continue;
            }
            reg_point(p);
            reg_point(Point::new(-p.x,  p.y));
            reg_point(Point::new(-p.x, -p.y));
            reg_point(Point::new( p.x, -p.y));
        }
    }
    let mut dists: Vec<_> = (0..n)
        .map(|_| vec![-1; n])
        .collect();
    dists[0][0] = 0;
    let mut que = VecDeque::new();
    que.push_back(Point::new(0, 0));
    while let Some(p) = que.pop_front() {
        let ndist = dists[p.x as usize][p.y as usize] + 1;
        for dp in &mag_m_points {
            let np = p.add(dp);
            if (0 <= np.x && np.x < n as i64)
            && (0 <= np.y && np.y < n as i64)
            && dists[np.x as usize][np.y as usize] < 0
            {
                dists[np.x as usize][np.y as usize] = ndist;
                que.push_back(np);
            }
        }
    }
    for row in &dists {
        print!("{}", row[0]);
        for &v in &row[1..] {
            print!(" {}", v);
        }
        println!();
    }
}
