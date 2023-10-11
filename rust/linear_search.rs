use clap::Parser;

#[derive(Parser)]
struct Cli {
    /// The item to look for
    item: i32,
    /// The array to search in
    array: Vec<i32>,
}

fn linear_search(array: &[i32], item: i32) -> bool {
    for n in array {
        if *n == item {
            return true;
        }
    }

    return false;
}

fn main() {
    let args = Cli::parse();
    if linear_search(&args.array, args.item) {
        println!("Found it!");
    } else {
        println!("Not found...");
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_found() {
        assert_eq!(linear_search(&[1, 2, 3, 4, 5], 2), true);
    }

    #[test]
    fn test_not_found() {
        assert_eq!(linear_search(&[1, 2, 3, 4, 5], 10), false);
    }

    #[test]
    fn test_empty_list() {
        assert_eq!(linear_search(&[], 10), false);
    }
}
