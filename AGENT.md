# AGENT.md

## Project Snapshot
- Repository: `El-cmd/get_next_line`
- Default branch: `master`
- Detected stack: C
- Notable root entries: `get_next_line.c`, `get_next_line.h`, `get_next_line_bonus.c`, `get_next_line_bonus.h`, `get_next_line_utils.c`, `get_next_line_utils_bonus.c`, `readme.md`
- Source mix: .c:4, .h:2, .md:1

## Working Guidelines
- Keep changes scoped to the requested behavior and follow the style already present in the touched files.
- Check `README.md`, `Makefile`, package scripts, and Docker files before introducing new commands or tooling.
- Preserve the existing C/C++ layout and Makefile conventions; avoid committing binaries, object files, or local test outputs.
- Do not commit local secrets, `.env` files, generated dependency folders, build artifacts, or editor metadata.

## Setup
- `No explicit dependency install command is defined in the repository.`

## Run
- `No canonical run command is defined; inspect README/Makefile/package scripts first.`

## Validate
- `Run the most relevant local build or smoke test before pushing changes.`
