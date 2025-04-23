# E-store Project

This project simulates an online store where customers can browse and purchase items. The project has various components representing customers, items, inventory management, and the store's operations.

## Setting Up the Python Path

Before running the project, make sure to set the `PYTHONPATH` to the `src` directory. This ensures that Python can find and import the modules correctly.

1. Open a terminal.
2. Navigate to the project directory at the same level of the `src` folder.

For example:

```bash
cd /mnt/data/riccardo/laboratorio_di_programmazione/lezioni/lezione_2/esercizi_1_e_2_lezione_2/e_store_project/
```


3. Set the `PYTHONPATH` environment variable:

```bash
export PYTHONPATH=$(pwd)/src
```

4. Now you can run the project by executing:

```bash
python3 src/e_store/main.py
```

or the server version with:

```bash
python3 src/e_store/server.py
```
