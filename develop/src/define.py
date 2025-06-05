from dotenv import load_dotenv
from os import getenv
from groq import Groq
from json import dumps, loads
from pprint import pprint


def define_term(word: str) -> dict:

    client = init_client()
    prompt = generate_prompt(word)

    chat_completion = client.chat.completions.create(
        messages=[
            {"role": "user", "content": prompt}
        ],
        model="llama-3.1-8b-instant"
    )

    content = chat_completion.choices[0].message.content.strip()
    
    return loads(content)


def init_client():

    load_dotenv()
    API_KEY = getenv('KEY')

    return Groq(api_key=API_KEY)


def generate_prompt(word: str) -> str:

    schema = {
        word: {
            "definition": "string",
            "example": "string"
        }
    }

    json_schema = dumps(schema, indent=2)

    return f"""
    Generate a concise technical definition and usage example for the word: "{word}".
    Respond strictly in this JSON format:{json_schema}
    Do not include any explanation or formatting. Only return raw JSON.
    For the example only Use plain English and avoid technical jargon.
    """

pprint(define_term("API"))