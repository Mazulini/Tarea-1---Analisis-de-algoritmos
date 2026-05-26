#!/bin/bash
# run_experiments.sh
# Uso: ./run_experiments.sh <runs> <lower> <upper> <step>

# ─── Validación de argumentos ─────────────────────────────────────────────────
if [ "$#" -ne 4 ]; then
    echo "Uso: $0 <runs> <lower> <upper> <step>"
    exit 1
fi

RUNS=$1
LOWER=$2
UPPER=$3
STEP=$4

# ─── Configuración ────────────────────────────────────────────────────────────
METHODS=("classic" "strassen" "hybrid")
TYPES=("int" "double" "long" "triangular")
OUTPUT_DIR="results"

# ─── Correr cada combinación método × tipo ────────────────────────────────────
for METHOD in "${METHODS[@]}"; do
    for TYPE in "${TYPES[@]}"; do
        EXE="${METHOD}_${TYPE}"
        TYPE_DIR="${OUTPUT_DIR}/${TYPE}"
        mkdir -p "$TYPE_DIR"

        OUTPUT_FILE="${TYPE_DIR}/${METHOD}_${LOWER}_${UPPER}_${STEP}.csv"

        echo "▶ Corriendo $EXE..."
        echo "  Salida → $OUTPUT_FILE"

        ./"${EXE}" "$OUTPUT_FILE" "$RUNS" "$LOWER" "$UPPER" "$STEP"

        if [ $? -eq 0 ]; then
            echo "  ✔ $EXE terminó correctamente"
        else
            echo "  ✘ $EXE falló (código de error: $?)"
        fi

        echo ""
    done
done

echo "═══════════════════════════════════════════"
echo "  Experimentos completados."
echo "  Resultados en: $OUTPUT_DIR/<tipo>/"
echo "═══════════════════════════════════════════"