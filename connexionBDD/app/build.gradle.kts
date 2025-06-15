plugins {
    alias(libs.plugins.android.application)
    alias(libs.plugins.kotlin.android)
}

android {
    namespace = "com.example.connexionbdd"
    // Je recommande toujours d'utiliser la dernière API stable si vous n'avez pas de raison spécifique pour la 35.
    // Au moment de l'écriture (début 2024), l'API 34 (Android 14) est stable.
    compileSdk = 34 // Ou 35 si vous en avez spécifiquement besoin et que vous l'avez installée

    defaultConfig {
        applicationId = "com.example.connexionbdd"
        minSdk = 24
        targetSdk = 34 // Devrait correspondre à compileSdk pour les versions stables
        versionCode = 1
        versionName = "1.0"

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
    }

    buildTypes {
        release {
            isMinifyEnabled = false // Pour une release, envisagez de mettre à true
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_11
        targetCompatibility = JavaVersion.VERSION_11
    }
    kotlinOptions {
        jvmTarget = "11"
    }
}

dependencies { // Début du SEUL bloc dependencies

    implementation(libs.androidx.core.ktx)
    implementation(libs.androidx.appcompat)
    implementation(libs.material)
    testImplementation(libs.junit)
    androidTestImplementation(libs.androidx.junit)
    androidTestImplementation(libs.androidx.espresso.core)

    // ATTENTION : Cette ligne est dangereuse et inutile si vous utilisez un script PHP intermédiaire.
    // Votre application Android ne doit PAS se connecter directement à PostgreSQL.
    // Supprimez cette ligne si vous suivez l'architecture avec l'API PHP.
    // implementation("org.postgresql:postgresql:42.2.27")

    // Le commentaire ci-dessous était redondant car il était à l'intérieur du bloc dependencies.
    // // build.gradle.kts (Module :app)
    //     // ... autres dépendances

    // Retrofit pour les appels réseau
    implementation("com.squareup.retrofit2:retrofit:2.9.0") // Vérifiez la dernière version
    implementation("com.squareup.retrofit2:converter-gson:2.9.0") // Pour parser le JSON en objets

    // OkHttp Logging Interceptor (très utile pour voir les requêtes/réponses)
    // Assurez-vous que la version est compatible avec Retrofit 2.9.0 (souvent OkHttp 4.x)
    implementation("com.squareup.okhttp3:logging-interceptor:4.11.0")

    // ViewModel et Coroutines pour la gestion de l'état et l'asynchronisme
    implementation("androidx.lifecycle:lifecycle-viewmodel-ktx:2.7.0") // Vérifiez la dernière version
    implementation("androidx.lifecycle:lifecycle-runtime-ktx:2.7.0")   // Pour `lifecycleScope.launch` et `repeatOnLifecycle`, vérifiez la dernière version
    implementation("org.jetbrains.kotlinx:kotlinx-coroutines-android:1.7.3") // Vérifiez la dernière version

    // MPAndroidChart (si pas encore ajouté)
    implementation("com.github.PhilJay:MPAndroidChart:v3.1.0")

} // Fin du SEUL bloc dependencies!
// L'ACCOLADE EN TROP QUI ÉTAIT ICI A ÉTÉ SUPPRIMÉE