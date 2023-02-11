enum IndexDir {
    Go(u32),
    Back(u32),
}

fn main() {
    let mut line = String::new();
    let stdin = std::io::stdin();
    stdin.read_line(&mut line).unwrap();
    let (n, _m) = {
        let v = line
            .trim()
            .split_ascii_whitespace()
            .map(|s| s.parse::<u32>().unwrap())
            .collect::<Vec<_>>();
        (v[0], v[1])
    };
    line.clear();
    stdin.read_line(&mut line).unwrap();
    let re_s = line
        .trim()
        .split_ascii_whitespace()
        .map(|s| s.parse::<u32>().unwrap() as usize)
        .collect::<Vec<_>>();
    let mut stream = (1..=n).map(IndexDir::Go).collect::<Vec<_>>();
    for i in re_s.iter().rev() {
        match stream[*i] {
            IndexDir::Go(idx) => stream[*i] = IndexDir::Back(idx),
            _ => unreachable!(),
        }
    }
    let mut res: Vec<Vec<u32>> = vec![];
    for ki in stream {
        let i = match ki {
            IndexDir::Go(i) => {
                res.push(vec![]);
                i
            }
            IndexDir::Back(i) => i,
        };
        res.last_mut().unwrap().push(i);
    }
    let ans = res
        .into_iter()
        .flat_map(|v| v.into_iter().rev().collect::<Vec<_>>())
        .map(|i| i.to_string())
        .collect::<Vec<_>>()
        .join(" ");
    println!("{}", ans);
}
