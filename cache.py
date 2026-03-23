# from groq import Groq
# from typing import Any

from dotenv import load_dotenv
from os import getenv

load_dotenv()

API_KEY = getenv("API_KEY")

print(API_KEY)

# client = Groq(
#     api_key=API_KEY 
# )

# def getCompletion(word: str) -> str | Any:

#     chat_completion = client.chat.completions.create(
        
#         messages=[
#             {
#                 'role': 'user',
#                 'content': f'generate the tech definition of: {word}, using this schema: {schema}.'
#             },
        
#             {
#                 'role': 'assistant',
#                 'content': '```json'
#             }
#             ],
        
#         stop='```',
        
#         model = 'llama3-8b-8192'
#     )
    
#     return chat_completion.choices[0].message.content