package com.example.connexionbdd // Assurez-vous que ce package est correct

import com.github.mikephil.charting.data.Entry // C'est la bonne classe Entry pour MPAndroidChart
// Supprimez l'import 'import java.security.KeyStore' s'il était présent et non utilisé ailleurs

sealed class ChartUiState {
    object Loading : ChartUiState()
    data class Success(
        val temperatureEntries: List<Entry>, // CORRIGÉ : Utilise com.github.mikephil.charting.data.Entry
        val co2Entries: List<Entry>,         // CORRIGÉ : Utilise com.github.mikephil.charting.data.Entry
        val humidityEntries: List<Entry>,    // CORRIGÉ : Utilise com.github.mikephil.charting.data.Entry
        val timestamps: List<Long>
    ) : ChartUiState()
    data class Error(val message: String) : ChartUiState()
    object Empty : ChartUiState()
}