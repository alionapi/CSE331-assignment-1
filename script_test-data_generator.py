import random
import os

#  this to generate and save data to a file
def generate_data_file(filename, data):
    with open(filename, "w") as f:
        f.write(" ".join(map(str, data)))

# here to create partially sorted data
def partially_sorted_data(size):
    sorted_part = sorted(random.randint(1, 1000000) for _ in range(size // 2))
    random_part = [random.randint(1, 1000000) for _ in range(size // 2)]
    return sorted_part + random_part

# creating a folder to store the files
os.makedirs("data", exist_ok=True)

sizes = {
    "1000": 1000,
    "10000": 10000,
    "100000": 100000,
    "1000000": 1000000
}

# Generate files for each size and data type
for label, size in sizes.items():
    # random data
    random_data = [random.randint(1, 1000000) for _ in range(size)]
    generate_data_file(f"data_files/random_{label}.txt", random_data)
    
    # sorted ascending
    ascending_data = sorted(random_data)
    generate_data_file(f"data_files/sorted_{label}.txt", ascending_data)
    
    # reversed
    descending_data = sorted(random_data, reverse=True)
    generate_data_file(f"data_files/reversed_{label}.txt", descending_data)
    
    # partially sorted
    partial_data = partially_sorted_data(size)
    generate_data_file(f"data_files/partial_{label}.txt", partial_data)
    
    print(f"Generated files for {label}: random, sorted, reversed, partially sorted.")

