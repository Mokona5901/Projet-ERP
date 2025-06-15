package com.example.connexionbdd // Adaptez si votre package est différent

import android.util.Log
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.github.mikephil.charting.data.Entry
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import kotlinx.coroutines.flow.asStateFlow
import kotlinx.coroutines.launch
import java.io.IOException
import java.security.KeyStore

class MainViewModel : ViewModel() {

    private val _chartUiState = MutableStateFlow<ChartUiState>(ChartUiState.Loading)
    val chartUiState: StateFlow<ChartUiState> = _chartUiState.asStateFlow()

    private val apiService = RetrofitInstance.api // Assurez-vous que RetrofitInstance est bien créé et accessible

    init {
        fetchSensorData()
    }

    fun fetchSensorData() {
        _chartUiState.value = ChartUiState.Loading
        viewModelScope.launch {
            try {
                val response = apiService.getSensorData()
                if (response.isSuccessful) {
                    val apiResponse = response.body()
                    if (apiResponse != null && apiResponse.status == "success") {
                        val sensorReadings = apiResponse.data
                        if (!sensorReadings.isNullOrEmpty()) {
                            val temperatureEntries = mutableListOf<KeyStore.Entry>()
                            val co2Entries = mutableListOf<KeyStore.Entry>()
                            val humidityEntries = mutableListOf<KeyStore.Entry>()
                            val timestamps = mutableListOf<Long>()

                            sensorReadings.forEachIndexed { index, reading ->
                                reading.timestamp?.let { ts -> timestamps.add(ts) }
                                val xValue = index.toFloat()
                                reading.temperature?.let { temp -> temperatureEntries.add(
                mm                    KeyStore.Entry(
                                        xValue,
                                        temp
                                    )
                                ) }
                                reading.co2?.let { c -> co2Entries.add(KeyStore.Entry(xValue, c)) }
                                reading.humidity?.let { h -> humidityEntries.add(
                                    KeyStore.Entry(
                                        xValue,
                                        h
                                    )
                                ) }
                            }
                            _chartUiState.value = ChartUiState.Success(
                                temperatureEntries,
                                co2Entries,
                                humidityEntries,
                                timestamps
                            )
                        } else {
                            _chartUiState.value = ChartUiState.Empty
                        }
                    } else {
                        val errorMessage = apiResponse?.message ?: "Réponse invalide de l'API (status: ${apiResponse?.status})"
                        _chartUiState.value = ChartUiState.Error(errorMessage)
                        Log.e("MainViewModel", "API Logic Error: $errorMessage")
                    }
                } else {
                    val errorBody = response.errorBody()?.string() ?: "Aucun message d'erreur détaillé du serveur."
                    val errorMessage = "Erreur réseau ${response.code()}: $errorBody"
                    _chartUiState.value = ChartUiState.Error(errorMessage)
                    Log.e("MainViewModel", "Network Error: ${response.code()} - $errorBody")
                }
            } catch (e: IOException) {
                _chartUiState.value = ChartUiState.Error("Erreur de connexion: Vérifiez votre connexion Internet ou l'adresse du serveur.")
                Log.e("MainViewModel", "Network IO Exception", e)
            } catch (e: Exception) {
                val errorMessage = "Une erreur inattendue est survenue: ${e.localizedMessage ?: e.message ?: "Erreur inconnue"}"
                _chartUiState.value = ChartUiState.Error(errorMessage)
                Log.e("MainViewModel", "Generic Exception during API call", e)
            }
        }
    }

    fun refreshData() {
        fetchSensorData()
    }
}