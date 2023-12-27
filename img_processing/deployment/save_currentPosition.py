import os
import json

def save_position(predicted_label):
    # Load existing data if the file exists
    if os.path.exists("fill_percent_data.json"):
        with open("fill_percent_data.json", "r") as json_file:
            fill_percent_data = json.load(json_file)

    fill_percent_data["current_position"] = predicted_label 

    with open("fill_percent_data.json", "w") as json_file:
        json.dump(fill_percent_data, json_file)

    print(" - Updated the current position of bin to json")

if __name__ == "__main__":
    save_position("plastic")
