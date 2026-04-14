from dotenv import load_dotenv
from os import getenv
from groq import Groq

load_dotenv()
API_KEY = getenv("API_KEY")
client = Groq(api_key=API_KEY)

def getCompletion(word):
    
    schema = {
        "word": { 
            "definition": "string", 
            "example": "string"
            }
        }

    chat_completion = client.chat.completions.create(
        
        messages=[
            {
                'role': 'user',
                'content': f'generate the tech definition of: {word} in this schema: {schema}. Example should not have jargon'
            },
        
            {
                'role': 'assistant',
                'content': '```json'
            }
            ],
        
        stop='```',
        
        model = 'llama-3.3-70b-versatile'
    )
    
    return chat_completion.choices[0].message.content

print(getCompletion("polymorphism"))