CREATE TABLE IF NOT EXISTS "terms"(
    "id" INTEGER PRIMARY KEY,
    "word" TEXT UNIQUE NOT NULL,
    "definition" TEXT NOT NULL,
    "example" TEXT NOT NULL
);