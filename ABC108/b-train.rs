use std::f64::consts::PI;
use std::io;
use std::ops::{Add, AddAssign, Sub, SubAssign};

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Vector2D {
    x: f64,
    y: f64,
}

impl Vector2D {
    pub fn new(x: f64, y: f64) -> Self {
        Self { x, y }
    }

    pub fn mul(&self, rhs: f64) -> Self {
        Self {
            x: self.x * rhs,
            y: self.y * rhs,
        }
    }

    pub fn mul_mut(&mut self, rhs: f64) -> &mut Self {
        self.x *= rhs;
        self.y *= rhs;
        self
    }

    pub fn div(&self, rhs: f64) -> Self {
        Self {
            x: self.x / rhs,
            y: self.y / rhs,
        }
    }

    pub fn div_mut(&mut self, rhs: f64) -> &mut Self {
        self.x /= rhs;
        self.y /= rhs;
        self
    }

    pub fn abs_square(&self) -> f64 {
        self.x * self.x + self.y * self.y
    }

    pub fn abs(&self) -> f64 {
        self.abs_square().sqrt()
    }

    pub fn argument(&self) -> f64 {
        self.y.atan2(self.x)
    }

    pub fn rotate(&self, angle: f64) -> Self {
        let (s, c) = angle.sin_cos();
        let rotated_x = Self::new(self.x * c, self.x * s);
        let rotated_y = Self::new(-self.y * s, self.y * c);
        rotated_x + rotated_y
    }
}

impl Add for Vector2D {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self {
            x: self.x + rhs.x,
            y: self.y + rhs.y,
        }
    }
}

impl AddAssign for Vector2D {
    fn add_assign(&mut self, rhs: Self) {
        self.x += rhs.x;
        self.y += rhs.y;
    }
}

impl Sub for Vector2D {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self {
            x: self.x - rhs.x,
            y: self.y - rhs.y,
        }
    }
}

impl SubAssign for Vector2D {
    fn sub_assign(&mut self, rhs: Self) {
        self.x -= rhs.x;
        self.y -= rhs.y;
    }
}

impl From<(f64, f64)> for Vector2D {
    fn from((x, y): (f64, f64)) -> Self {
        Self { x, y }
    }
}

fn main() {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let s: Vec<f64> = s
        .trim()
        .split_whitespace()
        .map(|x| x.parse())
        .collect::<Result<Vec<_>, _>>()
        .unwrap();
    let (p1, p2) = (Vector2D::new(s[0], s[1]), Vector2D::new(s[2], s[3]));
    let p3 = (p2 - p1).rotate(PI / 2.0) + p2;
    let p4 = p1 - p2 + p3;
    println!(
        "{} {} {} {}",
        p3.x.round(),
        p3.y.round(),
        p4.x.round(),
        p4.y.round()
    );
}
