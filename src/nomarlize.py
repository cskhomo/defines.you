from json import load, dump
from pprint import pprint

storage = "../data/common.json"

with open(storage) as raw:
    raw = load(raw)

normal = dict()

for term in raw:
    normal[list(term.keys())[0].lower()] = list(term.values())[0]

pprint(normal)

with open(storage, "w") as normalised:
    dump(normal, normalised, indent=4)