import os 
from dotenv import load_dotenv

from groq import Groq

from typing import Any

# get auth
load_dotenv()
API_KEY = os.getenv('KEY')

client = Groq(
    api_key=API_KEY 
)

schema = { 
  'word': {
      'definition': 'string',
      'example': 'string'
  }
}


def getCompletion(word: str) -> str | Any:
    #
    chat_completion = client.chat.completions.create(
        messages=[
            {
                'role': 'user',
                'content': f'generate the tech definition of: {word}, using this schema: {schema}.'
            },
            {
                'role': 'assistant',
                'content': '```json'
            }
            ],
        stop='```',
        model = 'llama3-8b-8192'
    )
    return chat_completion.choices[0].message.content