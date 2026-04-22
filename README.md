# Defines

Command-line tool for retrieving programming definitions instantly.

Defines helps developers understand technical terms without leaving the terminal, reducing context switching and improving learning flow.

---

## Overview

Developers—especially beginners—often encounter unfamiliar terms while coding.

Switching between the terminal and a browser to look up definitions:
- breaks focus  
- slows down learning  
- disrupts workflow  

Defines solves this by bringing definitions directly into the CLI.

---

## Features

- Instant lookup of programming terms  
- Offline access via local database  
- Automatic caching of previously searched terms  
- Fallback to online API when definitions are not available locally  

---

## Example Usage

```bash
$ defines polymorphism

Polymorphism:
The ability of a function or object to take multiple forms depending on context.

Example:
A function behaving differently based on input type.
```

---

## How It Works

### 1. Local Lookup
- Queries a local SQLite database for fast, offline access  

### 2. Cache Layer
- Stores previously requested terms for future offline use  

### 3. Remote Fallback
- If a term is not found locally, fetches data from an external API  
- Saves the result locally for subsequent queries  

---

## Architecture

```
User Input (CLI)
        ↓
Local Database Lookup (SQLite)
        ↓
Cache Miss → API Request
        ↓
Store Result Locally
        ↓
Display Definition
```

---


## Problem This Solves

Defines reduces **context switching**, which is one of the biggest hidden costs in learning and development.

Instead of:
```
code → confusion → browser → search → read → return
```

You get:
```
code → defines → understand → continue
```

---

## Target Users

- Beginner developers learning programming concepts  
- Developers working heavily in terminal environments  
- Anyone who prefers fast, low-friction tooling  
