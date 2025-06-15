package com.example.connexionbdd // Adaptez à votre nom de package exact

import retrofit2.Response // Important: utilisez retrofit2.Response, pas okhttp3.Response directement
import retrofit2.http.GET
// import retrofit2.http.Path // Décommentez si vous utilisez getSensorDataById
// import retrofit2.http.Query // Décommentez si vous utilisez getSensorDataByDateRange
// import retrofit2.http.POST // Décommentez si vous utilisez configureSensor
// import retrofit2.http.Body // Décommentez si vous utilisez configureSensor
// import com.google.gson.annotations.SerializedName // Décommentez si vous utilisez GenericStatusResponse

/**
 * Interface définissant les endpoints de l'API pour récupérer les données des capteurs.
 * Retrofit utilisera cette interface pour générer le code d'appel réseau.
 */
interface ApiService {

    /**
     * Récupère la liste des dernières lectures de capteurs depuis le script PHP.
     * La fonction est marquée 'suspend' car elle sera appelée depuis une coroutine
     * pour ne pas bloquer le thread principal.
     *
     * L'annotation @GET spécifie :
     *  - La méthode HTTP (GET dans ce cas).
     *  - Le chemin relatif de l'endpoint sur le serveur. Ce chemin sera ajouté à la BASE_URL
     *    définie lors de la création de l'instance Retrofit.
     *
     * La fonction retourne un objet Response<ApiResponse>.
     *  - Response : Contient les détails de la réponse HTTP (code de statut, headers, etc.)
     *    en plus du corps de la réponse. Utiliser Response permet une meilleure gestion des erreurs.
     *  - ApiResponse : C'est la classe de données (définie à l'Étape 2) dans laquelle Gson
     *    tentera de désérialiser le corps JSON de la réponse si la requête est réussie.
     */
    @GET("api/get_sensor_data.php") // Adaptez ce chemin si votre script PHP est ailleurs sur le serveur
    suspend fun getSensorData(): Response<ApiResponse> // Assurez-vous que ApiResponse est bien défini

    // --- Exemples d'autres types de requêtes que vous pourriez ajouter plus tard ---

    /*
    // Exemple d'une requête GET avec un paramètre dans l'URL (Path parameter)
    // Supposons que vous vouliez récupérer les données pour un capteur spécifique par son ID
    @GET("api/sensor/{sensorId}/data")
    suspend fun getSensorDataById(@Path("sensorId") id: String): Response<ApiResponse>

    // Exemple d'une requête GET avec des paramètres de requête (Query parameters)
    // Supposons que vous vouliez filtrer les données par date
    @GET("api/get_sensor_data.php")
    suspend fun getSensorDataByDateRange(
        @Query("startDate") startDate: Long, // Sera ajouté comme ?startDate=xxxx
        @Query("endDate") endDate: Long      // Sera ajouté comme &endDate=yyyy
    ): Response<ApiResponse>

    // Exemple d'une requête POST (si vous deviez envoyer des données au serveur)
    // Supposons que vous ayez un endpoint pour ajouter une nouvelle configuration
    // data class SensorConfig(val sensitivity: String, val isActive: Boolean) // Modèle pour le corps de la requête. À définir ailleurs.

    // @POST("api/configure_sensor.php")
    // suspend fun configureSensor(@Body config: SensorConfig): Response<GenericStatusResponse> // GenericStatusResponse serait un autre modèle simple
    */

}

// Vous pourriez aussi avoir besoin d'un modèle simple pour des réponses de statut génériques.
// Si vous l'utilisez, définissez-le dans son propre fichier ou avec vos autres modèles de données.
// Ne le laissez pas commenté au niveau supérieur de ce fichier.
/*
data class GenericStatusResponse(
   @SerializedName("status") val status: String,
   @SerializedName("message") val message: String?
)
*/