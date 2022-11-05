fn main() {
    proconio::input! {
        n: usize, m: usize,
        roads: [(usize, usize); m]
    }
    let mut graph: Vec<_> = (0..n).map(|_| vec![]).collect();
    for (a, b) in roads {
        let a = a - 1;
        let b = b - 1;
        graph[a].push(b);
        graph[b].push(a);
    }
    for mut cities in graph.into_iter() {
        cities.sort();
        let init = cities.len().to_string();
        let line = cities.into_iter().fold(init, |mut line, i| {
            let push = format!(" {}", i + 1);
            line.push_str(&push);
            line
        });
        println!("{}", line);
    }
}
