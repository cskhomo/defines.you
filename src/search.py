from json import load, dump
from generate import store
from pprint import pprint

common = "../data/common.json"

def user_input():
    user_answer = input("search:")
    return user_answer

def search():
    user_term = user_input()

    with open(common) as known_terms:
        known_terms = load(known_terms)
        
    for term in known_terms:
        if user_term == term:
            print(known_terms[term]["definition"])
            store({term: known_terms[term]})
            
search()