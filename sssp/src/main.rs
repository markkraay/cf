use std::collections::{
    VecDeque, HashSet
};
use std::io;
use std::cmp::min;

pub fn int(s: &String) -> i32 {
    s.trim().parse().unwrap()
}

pub fn char(s: &String) -> usize {
    s.chars().into_iter().nth(0).unwrap() as usize - ('a' as usize)
}

fn main() {
    let stdin = io::stdin();
    let mut s1 = String::new();
    let mut s2 = String::new();
    let mut temp = String::new();
    stdin.read_line(&mut s1).unwrap();
    stdin.read_line(&mut s2).unwrap();
    stdin.read_line(&mut temp).unwrap();
    let mut n = int(&temp);
    // Generate the cost matrix
    let mut cost = vec![vec![i32::MAX; 26]; 26];
    while n > 0 {
        temp.clear();
        stdin.read_line(&mut temp).unwrap();
        let temp: Vec<String> = temp.split_whitespace().map(String::from).collect();
        let c1 = char(&temp[0]);
        let c2 = char(&temp[1]);
        let weight = int(&temp[2]);
        cost[c1][c2] = min(cost[c1][c2], weight); 
        cost[c2][c1] = min(cost[c2][c1], weight);
        n -= 1;
    }

    
    for c in (0..=26) {
        unorder
    }
    println!("{:?}", cost);
    // Run Dijkstra's on the cost matrix to find the SSSP from one char to another char



    // For each character, find
}