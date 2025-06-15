package com.example.connexionbdd // Adaptez à votre nom de package exact

import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import java.util.concurrent.TimeUnit

/**
 * Objet Singleton pour fournir une instance configurée de Retrofit et de l'ApiService.
 */
object RetrofitInstance {

    // !!! TRÈS IMPORTANT : REMPLACEZ CECI PAR L'ADRESSE IP DE VOTRE RASPBERRY PI !!!
    // N'oubliez pas le "http://" et le "/" à la fin.
    // Exemple : "http://192.168.1.123/"
    private const val BASE_URL = "http://172.17.1.161/"

    // Créer un intercepteur de logging OkHttp.
    // Cela affichera les détails des requêtes et des réponses dans Logcat,
    // ce qui est extrêmement utile pour le débogage des appels réseau.
    private val loggingInterceptor = HttpLoggingInterceptor().apply {
        // En mode DEBUG, loguer le corps complet des requêtes/réponses.
        // En mode RELEASE, vous pourriez vouloir un niveau moins verbeux (Level.BASIC ou Level.NONE).
        level = if (BuildConfig.DEBUG) { // BuildConfig est généré par Gradle
            HttpLoggingInterceptor.Level.BODY
        } else {
            HttpLoggingInterceptor.Level.NONE // Ou Level.BASIC pour moins de logs en production
        }
    }

    // Configurer le client OkHttp.
   // OkHttp est le client HTTP sous-jacent utilisé par Retrofit.
    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(loggingInterceptor) // Ajouter notre intercepteur de logging
        .connectTimeout(30, TimeUnit.SECONDS) // Délai d'attente pour établir une connexion
        .readTimeout(30, TimeUnit.SECONDS)    // Délai d'attente pour lire les données d'une connexion établie
        .writeTimeout(30, TimeUnit.SECONDS)   // Délai d'attente pour écrire des données sur une connexion établie
        .build()

    // Créer l'instance de Retrofit en utilisant la délégation 'lazy'.
    // 'lazy' signifie que l'objet Retrofit ne sera créé qu'à sa première utilisation,
    // et cette instance sera ensuite réutilisée.
    private val retrofit: Retrofit by lazy {
        Retrofit.Builder()
            .baseUrl(BASE_URL)                         // Définir l'URL de base de votre API
            .client(okHttpClient)                      // Utiliser notre client OkHttp personnalisé
            .addConverterFactory(GsonConverterFactory.create()) // Ajouter le convertisseur Gson
            // pour (dé)sérialiser JSON vers/depuis vos objets Kotlin
            .build()
    }

    // Exposer une instance de votre ApiService (définie à l'Étape 3).
    // Retrofit créera l'implémentation de cette interface pour vous.
    // Utilisation de 'lazy' ici aussi pour la même raison que pour 'retrofit'.
    val api: ApiService by lazy {
        retrofit.create(ApiService::class.java)
    }
}