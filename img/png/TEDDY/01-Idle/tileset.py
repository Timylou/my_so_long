from PIL import Image
import os

def create_tileset(image_folder, output_file, tile_size, grid_size):
    """
    Combine plusieurs PNG en un seul tileset.

    :param image_folder: Dossier contenant les PNG.
    :param output_file: Fichier de sortie (ex. 'tileset.png').
    :param tile_size: Taille d'un sprite (largeur, hauteur) en pixels.
    :param grid_size: Dimensions de la grille (colonnes, lignes).
    """
    tile_width, tile_height = tile_size
    grid_columns, grid_rows = grid_size

    # Calculer les dimensions de l'image finale
    output_width = grid_columns * tile_width
    output_height = grid_rows * tile_height

    # Créer une image vide
    tileset = Image.new("RGBA", (output_width, output_height))

    # Charger et placer chaque sprite
    x, y = 0, 0
    for i, file_name in enumerate(sorted(os.listdir(image_folder))):
        if file_name.endswith(".png"):
            img_path = os.path.join(image_folder, file_name)
            sprite = Image.open(img_path).resize((tile_width, tile_height))
            tileset.paste(sprite, (x, y))

            # Passer au prochain emplacement
            x += tile_width
            if x >= output_width:
                x = 0
                y += tile_height

    # Sauvegarder le tileset
    tileset.save(output_file)
    print(f"Tileset créé : {output_file}")

# Exemple d'utilisation
create_tileset(
    image_folder="./02-Idle_Blink",
    output_file="tileset.png",
    tile_size=(450, 523),
    grid_size=(6, 2)  # 10 colonnes x 10 lignes
)

