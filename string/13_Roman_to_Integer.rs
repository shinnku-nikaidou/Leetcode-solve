struct Solution();

pub fn get_value(c: char) -> Option<i32> {
    match c {
        'I' => Some(1),
        'V' => Some(5),
        'X' => Some(10),
        'L' => Some(50),
        'C' => Some(100),
        'D' => Some(500),
        'M' => Some(1000),
        _ => None,
    }
}

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut ans = 0;
        let mut last = 0;
        for c in s.chars() {
            if last >= get_value(c).unwrap() || last == 0 {
                ans += last;
                last = get_value(c).unwrap();
            } else {
                ans += get_value(c).unwrap() - last;
                last = 0;
            }
        }
        ans += last;
        ans
    }
}

fn main() {
    println!("{}", Solution::roman_to_int("III".to_string()));
}
