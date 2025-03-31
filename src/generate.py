from json import dump

def store(term):
    with open("../data/cache.json", "a") as previous_terms:
        dump(term, previous_terms, indent=4)