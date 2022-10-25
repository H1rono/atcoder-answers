struct BIT {
    length: usize,
    data: Vec<usize>,
}

impl BIT {
    fn new(length: usize) -> Self {
        Self {
            length,
            data: vec![0; length + 1],
        }
    }

    // data[index] += value, 0-indexed
    fn add(&mut self, index: usize, value: usize) {
        let mut i = index as isize + 1;
        while i <= self.length as isize {
            self.data[i as usize] += value;
            i += i & -i;
        }
    }

    // sum(data[..index]), 0-indexed
    fn sum(&self, index: usize) -> usize {
        let mut s = 0;
        let mut i = index as isize;
        while i > 0 {
            s += self.data[i as usize];
            i -= i & -i;
        }
        s
    }
}

fn main() {
    proconio::input! {
        n: usize,
        a: [usize; n]
    }
    let mut ans = 0;
    let mut bit = BIT::new(n);
    for i in 0..n {
        ans += if bit.sum(a[i]) == 0 { 1 } else { 0 };
        bit.add(a[i] - 1, 1);
    }
    println!("{}", ans);
}
