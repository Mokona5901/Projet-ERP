package com.example.connexionbdd // Adaptez à votre nom de package exact

import com.google.gson.annotations.SerializedName

/**
 * Représente une seule lecture de capteur, correspondant à un objet
 * dans le tableau "data" de la réponse JSON.
 */
data class SensorReading(
    // L'annotation @SerializedName est cruciale si le nom de la variable Kotlin
    // est différent du nom de la clé dans le JSON.
    // Ici, ils sont identiques, donc ce serait optionnel, mais c'est une bonne habitude.
    @SerializedName("timestamp")
    val timestamp: Long?, // Nullable (?) pour gérer les cas où la donnée pourrait manquer ou être nulle dans le JSON

    @SerializedName("temperature")
    val temperature: Float?,

    @SerializedName("co2")
    val co2: Float?,

    @SerializedName("humidity")
    val humidity: Float?
)

/**
 * Représente la structure globale de la réponse JSON de votre API.
 */
data class ApiResponse(
    @SerializedName("status")
    val status: String, // "success" ou "error"

    // La liste des lectures de capteurs.
    // Peut être nulle ou vide si status="error" ou si aucune donnée n'est trouvée.
    @SerializedName("data")
    val data: List<SensorReading>?,

    // Message d'information ou d'erreur de l'API.
    // Peut être nul.
    @SerializedName("message")
    val message: String?
)