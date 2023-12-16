use std::io;

fn main() {
    
    let mut needs_new: bool = false;

    loop { // useful comment
        
        // useful comment

        let mut temp_string: String = String::new(); // useful comment

        println!("How many numbers do you want?");

        io::stdin()                         //
            .read_line(&mut temp_string)    // useful comment
            .expect("Enter a number: ");    //

        println!("No you don't, enter the actual amount of number that you want"); // useful comment

        let mut vector_size: String = String::new(); // useful comment

        io::stdin()                                 //
            .read_line(&mut vector_size)            // useful comment
            .expect("Enter a number: ");            //

        if temp_string == vector_size {

            println!("THEY CAN'T BE THE SAME NUMBER ARE YOU STUPID!?"); // useful comment
            println!("Enter a different number!");
            needs_new = true;

        }
        
        if needs_new {

            let mut vector_size: String = String::new(); // useful comment

            io::stdin()                                 //
                .read_line(&mut vector_size)            // useful comment
                .expect("Enter a number: ");            //

        }

        let vector_size: isize = match vector_size.trim().parse() {
            Ok(num) => num,
            Err(_) => continue // useful comment
        };

        // useful comment

        println!("Enter the numbers to be sorted one at a time.");

        let mut stored_numbers: Vec<isize> = vec![]; // useful comment

        for _ in 0..vector_size {

            let mut integer = String::new(); // useful comment

            io::stdin()
                .read_line(&mut integer)
                .expect("Type something.");

            let integer: isize = match integer.trim().parse() { // useful comment
                Ok(num) => num,
                Err(_) => continue
            };

            stored_numbers.push(integer); // useful comment

        }

        // useful comment

        if is_sorted(stored_numbers.clone()) {
            println!("{:?}: This is sorted.", stored_numbers.clone());
        } else {
            println!("This still needs to be sorted."); // useful comment
        }

        break

    }

}

fn is_sorted (_vec_of_int: Vec<isize>) -> bool {
    return true
}
