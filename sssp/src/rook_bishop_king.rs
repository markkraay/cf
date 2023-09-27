use std::collections::{
    VecDeque, HashSet
};
use std::io;

type Position = (i32, i32);
type Move = (i32, i32);

pub fn valid_position(pos: &Position) -> bool {
    pos.0 >= 0 && pos.0 < 8 && pos.1 >= 0 && pos.1 < 8
}

pub fn find_shortest_path(start: Position, target: Position, moves: &Vec<Move>) -> u32 {
	let mut visited: HashSet<Position> = HashSet::new();
	let mut q = VecDeque::new();
    q.push_back((start, 0));
	while !q.is_empty() {
		let (p, depth) = q.pop_front().unwrap();
        if p == target {
            return depth
        }
        for (dx, dy) in moves {
            let new_position = (p.0 + dx, p.1 + dy);
            if !visited.contains(&new_position) && valid_position(&new_position) {
                q.push_back((new_position, depth + 1));
                visited.insert(new_position);
            }
        }
	}
    0
}

fn main() {
    let mut input = String::new();
    let stdin = io::stdin();
    stdin.read_line(&mut input).unwrap();
    let words: Vec<String> = input.split_whitespace().map(String::from).collect();
    let start: Position = (words[0].parse().unwrap(), words[1].parse().unwrap());
    let target: Position = (words[2].parse().unwrap(), words[3].parse().unwrap());

    let king = vec![(1,0), (-1,0), (0,1), (0,-1), (1,1), (-1,-1), (1,-1), (-1,1)];

    let mut knight = 0;
    if ((start.0 - target.0).abs() + (start.1 - target.1).abs()) % 2 == 0 { // Can get move the bishop to get to the location
        // Check if it is along the diagonal, in which case we only need to move once
        if (start.1 - target.1).abs() == (start.0 - target.0).abs() { knight = 1; } else { knight = 2; }
    }

    println!("{} {} {}", 
        (start.0 != target.0) as i32 + (start.1 != target.1) as i32,
        knight,
        find_shortest_path(start, target, &king),
    );
}