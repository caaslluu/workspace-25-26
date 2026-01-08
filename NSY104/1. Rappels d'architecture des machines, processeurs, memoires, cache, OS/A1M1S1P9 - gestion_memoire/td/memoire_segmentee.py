
# Exercice 3 : Mémoire paginée et segmentée

PAGE_SIZE = 4096

# Tables des pages (extraites de l'énoncé)
process_a = {
    "S1A": {1: 4, 2: 5},
    "S2A": {1: None, 2: 10, 3: None},
    "S3A": {1: 6}
}

process_b = {
    "S1B": {1: None, 2: 11, 3: 2, 4: None},
    "S2B": {1: 15, 2: None}
}

# Fonctions pour chaque question

def question_2():
    # Traduction de <S1A, page 1, 12>
    frame = process_a["S1A"][1]
    if frame is None:
        return "Défaut de page"
    else:
        return (frame - 1) * PAGE_SIZE + 12

def question_3():
    # Traduction de <S2B, page 2, 10>
    frame = process_b["S2B"].get(2)
    if frame is None:
        return "Défaut de page"
    else:
        return (frame - 1) * PAGE_SIZE + 10

# Limites des segments pour le processus A
segments_a = {
    "S1A": (0, 8191),
    "S2A": (8192, 20479),
    "S3A": (20480, 24575)
}

# Limites des segments pour le processus B
segments_b = {
    "S1B": (0, 16383),
    "S2B": (16384, 24575)
}

def find_segment(address, segments):
    for seg, (start, end) in segments.items():
        if start <= address <= end:
            return seg, address - start
    return None, None

def question_4a():
    # Adresse linéaire : 4098 (Processus A)
    addr = 4098
    seg, offset = find_segment(addr, segments_a)
    page = offset // PAGE_SIZE + 1
    displacement = offset % PAGE_SIZE
    frame = process_a[seg].get(page)
    if frame is None:
        return "Défaut de page"
    return (frame - 1) * PAGE_SIZE + displacement

def question_4b():
    # Adresse linéaire : 12292 (Processus A)
    addr = 12292
    seg, offset = find_segment(addr, segments_a)
    page = offset // PAGE_SIZE + 1
    displacement = offset % PAGE_SIZE
    frame = process_a[seg].get(page)
    if frame is None:
        return "Défaut de page"
    return (frame - 1) * PAGE_SIZE + displacement

def question_4c():
    # Adresse linéaire : 8212 (Processus B)
    addr = 8212
    seg, offset = find_segment(addr, segments_b)
    page = offset // PAGE_SIZE + 1
    displacement = offset % PAGE_SIZE
    frame = process_b[seg].get(page)
    if frame is None:
        return "Défaut de page"
    return (frame - 1) * PAGE_SIZE + displacement

# Exécution des réponses
if __name__ == "__main__":
    print("Question 2:", question_2())
    print("Question 3:", question_3())
    print("Question 4a:", question_4a())
    print("Question 4b:", question_4b())
    print("Question 4c:", question_4c())
