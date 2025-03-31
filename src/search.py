from json import load

def user_input():
    user_answer = input("search:")
    return user_answer

def search():
    user_term = user_input()

    with open("../data/common.json", "r") as common_terms:
        terms = load(common_terms)

    for term in terms:
        if user_term == term["term"]:
            print(term["definition"])

search()

