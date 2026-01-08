import requests

def main():

    link_dpe = "https://data.melunvaldeseine.fr/api/explore/v2.1/catalog/datasets/diagnostics-de-performances-energetiques-dpe/records?limit=100"

    r_dpe = requests.get(link_dpe)

    json_dpe = r_dpe.json()

    print("\n Via API Melun pour DPE: \n")
    for i in range(99):
        print("Adresse: ",json_dpe['results'][i]['adresse_brut'], json_dpe['results'][i]['nom_commune_brut'] ," , Etiquette DPE: ",json_dpe['results'][i]['etiquette_dpe'])
if __name__=="__main__":
    main()
