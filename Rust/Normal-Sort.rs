use std::io;
fn main() {

    loop { // it needs to be in a loop just trust me it all works nicer this way
        
        // Get size of vector

        println!("How many numbers do you want?");

        let mut vector_size: String = String::new();

        io::stdin()
            .read_line(&mut vector_size)
            .expect("enter a number");

        let vector_size: isize = match vector_size.trim().parse() {
            Ok(num) => num,
            Err(_) => continue
        };

        // Get the user input and store it in the vector of integers

        println!("Enter the numbers to be sorted one at a time.");

        let mut stored_numbers: Vec<isize> = vec![];

        for i in 0..vector_size {

            let mut integer = String::new();

            io::stdin()
                .read_line(&mut integer)
                .expect("Type something");

            let integer: isize = match integer.trim().parse() {
                Ok(num) => num,
                Err(_) => continue
            };

            stored_numbers.push(integer);

        }

        // Print the sorted vector

        if is_sorted(stored_numbers.clone()) {
            println!("{:?}: This is sorted.", stored_numbers.clone());
        } else {
            println!("This still needs to be sorted.");
        }

        break

    }

}

fn is_sorted (vec_of_int: Vec<isize>) -> bool {
    return true
}
