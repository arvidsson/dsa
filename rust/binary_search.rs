use clap::Parser;

#[derive(Parser)]
struct Cli {
    /// The item to look for
    item: i32,
    /// The array to search in
    array: Vec<i32>,
}

fn binary_search(array: &[i32], item: i32) -> bool {
    println!("Searching for {} in {:?}", item, array);

    if array.len() == 0 {
        return false;
    }

    let mut left = 0;
    let mut right = array.len() - 1;

    while left <= right {
        let middle = (left + right) / 2 as usize;
        if array[middle] < item {
            left = middle + 1;
        } else if array[middle] > item {
            right = middle - 1;
        } else {
            return true;
        }
    }

    return false;
}

fn main() {
    let args = Cli::parse();
    if binary_search(&args.array, args.item) {
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
        assert_eq!(binary_search(&[1, 2, 3, 4, 5], 2), true);
    }

    #[test]
    fn test_not_found() {
        assert_eq!(binary_search(&[1, 2, 3, 4, 5], 10), false);
    }

    #[test]
    fn test_empty_list() {
        assert_eq!(binary_search(&[], 10), false);
    }
}
