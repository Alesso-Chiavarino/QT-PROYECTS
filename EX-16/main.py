from fastapi import FastAPI, HTTPException, Request
from fastapi.responses import JSONResponse
from fastapi.encoders import jsonable_encoder
from pymongo import MongoClient

app = FastAPI()

# Configuración de la conexión a MongoDB
client = MongoClient("mongodb://localhost:27017/")
db = client["usuariosdb"]
collection = db["usuarios"]

@app.post("/validar_usuario")
async def validar_usuario(request: Request):
    # Obtener los datos del usuario desde la solicitud
    data = await request.json()
    usuario = data.get("usuario")
    clave = data.get("clave")

    # Consultar la base de datos para validar el usuario
    user = collection.find_one({"usuario": usuario, "clave": clave})

    if user:
        # Usuario válido
        return JSONResponse(content={"mensaje": "Usuario válido"}, status_code=200)
    else:
        # Usuario inválido
        raise HTTPException(status_code=401, detail="Credenciales inválidas")

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)
