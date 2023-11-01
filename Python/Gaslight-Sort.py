import sys

BUFFER_LENGTH = 12

def get_user_numbers(message):
    valid = False
    converted_number = 0
    while not valid:
        input_text = input(message)
        
        try:
            converted_number = int(input_text)
            if converted_number > sys.maxsize or converted_number < -sys.maxsize:
                print("Number too big bozo")
            else:
                valid = True
        except ValueError:
            print("Enter an actual number bozo")

    return converted_number

def insert_numbers(array_of_nums, total_inputs):
    how_many_more = total_inputs
    for a in range(total_inputs):
        print(f"Enter a number for index {a} ({how_many_more} positions left)")
        array_of_nums[a] = get_user_numbers("Enter the number for the index\n-> ")
        print()

def is_sorted(array):
    return True

if __name__ == "__main__":
    num_ints = 0
    while num_ints <= 0:
        num_ints = get_user_numbers("How many integers do you want\n-> ")
        if num_ints <= 0:
            print("Number has to be greater than zero bozo")

    print(num_ints)

    needs_to_be_sorted = [0] * num_ints
    insert_numbers(needs_to_be_sorted, num_ints)

    for p in range(num_ints):
        print(f"index {p} is {needs_to_be_sorted[p]}")

    if is_sorted(needs_to_be_sorted):
        print("This is sorted")
    else:
        print("Still sorted he he")
