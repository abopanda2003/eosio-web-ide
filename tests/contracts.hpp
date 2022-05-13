#pragma once
#include <eosio/testing/tester.hpp>

using namespace std;

namespace eosio { namespace testing {

struct contracts {
   static std::vector<uint8_t> system_wasm() { return read_wasm("${CMAKE_BINARY_DIR}/../contracts/eosio.system/eosio.system.wasm"); }
   static std::vector<char>    system_abi() { return read_abi("${CMAKE_BINARY_DIR}/../contracts/eosio.system/eosio.system.abi"); }
   static std::vector<uint8_t> token_wasm() { return read_wasm("${CMAKE_BINARY_DIR}/../contracts/eosio.token/eosio.token.wasm"); }
   static std::vector<char>    token_abi() { return read_abi("${CMAKE_BINARY_DIR}/../contracts/eosio.token/eosio.token.abi"); }
   static std::vector<uint8_t> msig_wasm() { return read_wasm("${CMAKE_BINARY_DIR}/../contracts/eosio.msig/eosio.msig.wasm"); }
   static std::vector<char>    msig_abi() { return read_abi("${CMAKE_BINARY_DIR}/../contracts/eosio.msig/eosio.msig.abi"); }
   static std::vector<uint8_t> wrap_wasm() { return read_wasm("${CMAKE_BINARY_DIR}/../contracts/eosio.wrap/eosio.wrap.wasm"); }
   static std::vector<char>    wrap_abi() { return read_abi("${CMAKE_BINARY_DIR}/../contracts/eosio.wrap/eosio.wrap.abi"); }
   static std::vector<uint8_t> bios_wasm() { return read_wasm("${CMAKE_BINARY_DIR}/../contracts/eosio.bios/eosio.bios.wasm"); }
   static std::vector<char>    bios_abi() { return read_abi("${CMAKE_BINARY_DIR}/../contracts/eosio.bios/eosio.bios.abi"); }

   struct util {
      static std::vector<uint8_t> reject_all_wasm() { return read_wasm("${CMAKE_SOURCE_DIR}/test_contracts/reject_all.wasm"); }
      static std::vector<uint8_t> exchange_wasm() { return read_wasm("${CMAKE_SOURCE_DIR}/test_contracts/exchange.wasm"); }
      static std::vector<uint8_t> system_wasm_v1_8() { return read_wasm("${CMAKE_SOURCE_DIR}/test_contracts/old_versions/v1.8.3/eosio.system/eosio.system.wasm"); }
      static std::vector<char>    system_abi_v1_8() { return read_abi("${CMAKE_SOURCE_DIR}/test_contracts/old_versions/v1.8.3/eosio.system/eosio.system.abi"); }
      static std::vector<uint8_t> system_wasm_old() { return read_wasm("${CMAKE_SOURCE_DIR}/test_contracts/old_versions/v1.2.1/eosio.system/eosio.system.wasm"); }
      static std::vector<char>    system_abi_old() { return read_abi("${CMAKE_SOURCE_DIR}/test_contracts/old_versions/v1.2.1/eosio.system/eosio.system.abi"); }
      static std::vector<uint8_t> msig_wasm_old() { return read_wasm("${CMAKE_SOURCE_DIR}/test_contracts/old_versions/v1.2.1/eosio.msig/eosio.msig.wasm"); }
      static std::vector<char>    msig_abi_old() { return read_abi("${CMAKE_SOURCE_DIR}/test_contracts/old_versions/v1.2.1/eosio.msig/eosio.msig.abi"); }
   };
};
}} //ns eosio::testing