#include "NetworkConfig.h"
#include <fstream>
#include <ostream>

void NetworkConfig::outputNetworkConfigData(std::ostream &stream) const {
  stream << "  " << UIutils::to_upper(network_name)
         << " CONFIGURATION DATA        \n"
            "--------------------------------\n";
  stream << "//NETWORK DETAILS//\n";
  stream << "Network Name: " << network_name << '\n';
  stream << "Date Created: " << date_created << '\n';

  stream << '\n';
  stream << "//ARCHITECTURE//\n";
  stream << "Number of Layers: " << layers << '\n';

  stream << '\n';
  stream << "//TRAINING//\n";
  stream << "Epochs trained: " << epochs_trained << '\n';
  stream << "Loss of last epoch: " << loss << '\n';
  stream << "Learning rate: " << learning_rate << '\n';
  stream << "Batch size: " << batch_size << '\n';

  stream << '\n';
}

void LayerConfig::outputLayerConfigData(const int &layerNum,
                                        std::ostream &stream) const {
  stream << "                  "
            "------------------------------------------------------------------"
            "---------------------------------\n";
  stream << "                  | Layer " << layerNum << " size: " << layerSize;
  stream << std::setw(80) << std::right << "|\n"; // std::setw, std::right
  stream << " Layer " << layerNum << "          | Layer " << layerNum
         << " layer type: " << UIutils::LayerTypeToString(layer_type);
  stream << std::setw(80) << std::right << "|\n";
  stream << "                  | Layer " << layerNum << " activation function: "
         << UIutils::ActivationFunctionToString(activation_function);
  stream << std::setw(80) << std::right << "|\n";
  stream << "                  "
            "------------------------------------------------------------------"
            "---------------------------------\n";
}

void NetworkConfig::outputAllLayerConfigs(std::ostream &stream) const {
  for (size_t i = 0; i < layerData.size(); i++) {
    layerData[i].outputLayerConfigData(i, stream);
  }
}

void NetworkConfig::save_current_date() {
  std::time_t t = std::time(nullptr);
  std::tm *now = std::localtime(&t);

  int year = now->tm_year + 1900;
  int month = now->tm_mon + 1;
  int day = now->tm_mday;

  // Build string manually (no advanced syntax)
  std::string date = "";
  date += std::to_string(year);
  date += "-";

  // zero pad month
  if (month < 10)
    date += "0";
  date += std::to_string(month);
  date += "-";

  // zero pad day
  if (day < 10)
    date += "0";
  date += std::to_string(day);

  date_created = date;
}

bool NetworkConfig::save_config_defualt_location() {
  std::filesystem::path save_dir =  std::filesystem::path("UserData") / "SaveConfigs" / network_name;
    save_file_path = save_dir.string();

  if (!std::filesystem::exists(save_dir))
    std::filesystem::create_directories(save_dir);

  std::filesystem::path config_path = save_dir / "config.txt";
  std::ofstream file(config_path);

  if (!file.is_open()) {
    std::cerr << "Error: Failed to open " << config_path << " for writing."
              << std::endl;
    return false;
  }

  outputNetworkConfigDataFileFormat(file);
  outputAllLayerConfigFileFormat(file);
  file.close();
  return true;
}

bool NetworkConfig::save_config_to_save_file_path() const {
  std::ofstream output_file;
  output_file.open((save_file_path));

  if (!output_file.is_open()) {
    std::cout << "\n[Error][Could not open save file]\n";
    return 0;
  }

  else {
    outputNetworkConfigDataFileFormat(output_file);
    output_file << '\n';
    outputAllLayerConfigFileFormat(output_file);
    output_file.close();
    return 1;
  }
}

void NetworkConfig::reset_date_created() { date_created = ""; }

void NetworkConfig::outputNetworkConfigDataFileFormat(
    std::ostream &stream) const {
  stream << UIutils::returnStringIfNotEmpty(network_name) << '\n';
  stream << UIutils::returnStringIfNotEmpty(date_created) << '\n';

  stream << batch_size << '\n';
  stream << learning_rate << '\n';

  stream << epochs_trained << '\n';
  stream << loss << '\n';

  stream << UIutils::returnStringIfNotEmpty(input_data_file_path) << '\n';
  stream << UIutils::returnStringIfNotEmpty(save_file_path) << '\n';
  stream << layers;

  stream << '\n';
  stream << '-';
  stream << '\n';
}

void LayerConfig::outputLayerConfigDataFileFormat(std::ostream &stream) const {
  stream << layerSize << '\n';
  stream << UIutils::LayerTypeToString(layer_type) << '\n';
  stream << UIutils::ActivationFunctionToString(activation_function) << '\n';
}

void NetworkConfig::outputAllLayerConfigFileFormat(std::ostream &stream) const {
  for (const auto &layer : layerData)
    layer.outputLayerConfigDataFileFormat(stream);
}
