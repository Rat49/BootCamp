#pragma once

#ifndef DISABLE_PLAYFABCLIENT_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace ClientModels
    {
        // Client Enums
        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        inline void ToJsonEnum(const CloudScriptRevisionOption input, web::json::value& output)
        {
            if (input == CloudScriptRevisionOptionLive) output = web::json::value(U("Live"));
            if (input == CloudScriptRevisionOptionLatest) output = web::json::value(U("Latest"));
            if (input == CloudScriptRevisionOptionSpecific) output = web::json::value(U("Specific"));
        }
        inline void FromJsonEnum(const web::json::value& input, CloudScriptRevisionOption& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Live")) output = CloudScriptRevisionOptionLive;
            if (inputStr == U("Latest")) output = CloudScriptRevisionOptionLatest;
            if (inputStr == U("Specific")) output = CloudScriptRevisionOptionSpecific;
        }

        enum ContinentCode
        {
            ContinentCodeAF,
            ContinentCodeAN,
            ContinentCodeAS,
            ContinentCodeEU,
            ContinentCodeNA,
            ContinentCodeOC,
            ContinentCodeSA
        };

        inline void ToJsonEnum(const ContinentCode input, web::json::value& output)
        {
            if (input == ContinentCodeAF) output = web::json::value(U("AF"));
            if (input == ContinentCodeAN) output = web::json::value(U("AN"));
            if (input == ContinentCodeAS) output = web::json::value(U("AS"));
            if (input == ContinentCodeEU) output = web::json::value(U("EU"));
            if (input == ContinentCodeNA) output = web::json::value(U("NA"));
            if (input == ContinentCodeOC) output = web::json::value(U("OC"));
            if (input == ContinentCodeSA) output = web::json::value(U("SA"));
        }
        inline void FromJsonEnum(const web::json::value& input, ContinentCode& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("AF")) output = ContinentCodeAF;
            if (inputStr == U("AN")) output = ContinentCodeAN;
            if (inputStr == U("AS")) output = ContinentCodeAS;
            if (inputStr == U("EU")) output = ContinentCodeEU;
            if (inputStr == U("NA")) output = ContinentCodeNA;
            if (inputStr == U("OC")) output = ContinentCodeOC;
            if (inputStr == U("SA")) output = ContinentCodeSA;
        }

        enum CountryCode
        {
            CountryCodeAF,
            CountryCodeAX,
            CountryCodeAL,
            CountryCodeDZ,
            CountryCodeAS,
            CountryCodeAD,
            CountryCodeAO,
            CountryCodeAI,
            CountryCodeAQ,
            CountryCodeAG,
            CountryCodeAR,
            CountryCodeAM,
            CountryCodeAW,
            CountryCodeAU,
            CountryCodeAT,
            CountryCodeAZ,
            CountryCodeBS,
            CountryCodeBH,
            CountryCodeBD,
            CountryCodeBB,
            CountryCodeBY,
            CountryCodeBE,
            CountryCodeBZ,
            CountryCodeBJ,
            CountryCodeBM,
            CountryCodeBT,
            CountryCodeBO,
            CountryCodeBQ,
            CountryCodeBA,
            CountryCodeBW,
            CountryCodeBV,
            CountryCodeBR,
            CountryCodeIO,
            CountryCodeBN,
            CountryCodeBG,
            CountryCodeBF,
            CountryCodeBI,
            CountryCodeKH,
            CountryCodeCM,
            CountryCodeCA,
            CountryCodeCV,
            CountryCodeKY,
            CountryCodeCF,
            CountryCodeTD,
            CountryCodeCL,
            CountryCodeCN,
            CountryCodeCX,
            CountryCodeCC,
            CountryCodeCO,
            CountryCodeKM,
            CountryCodeCG,
            CountryCodeCD,
            CountryCodeCK,
            CountryCodeCR,
            CountryCodeCI,
            CountryCodeHR,
            CountryCodeCU,
            CountryCodeCW,
            CountryCodeCY,
            CountryCodeCZ,
            CountryCodeDK,
            CountryCodeDJ,
            CountryCodeDM,
            CountryCodeDO,
            CountryCodeEC,
            CountryCodeEG,
            CountryCodeSV,
            CountryCodeGQ,
            CountryCodeER,
            CountryCodeEE,
            CountryCodeET,
            CountryCodeFK,
            CountryCodeFO,
            CountryCodeFJ,
            CountryCodeFI,
            CountryCodeFR,
            CountryCodeGF,
            CountryCodePF,
            CountryCodeTF,
            CountryCodeGA,
            CountryCodeGM,
            CountryCodeGE,
            CountryCodeDE,
            CountryCodeGH,
            CountryCodeGI,
            CountryCodeGR,
            CountryCodeGL,
            CountryCodeGD,
            CountryCodeGP,
            CountryCodeGU,
            CountryCodeGT,
            CountryCodeGG,
            CountryCodeGN,
            CountryCodeGW,
            CountryCodeGY,
            CountryCodeHT,
            CountryCodeHM,
            CountryCodeVA,
            CountryCodeHN,
            CountryCodeHK,
            CountryCodeHU,
            CountryCodeIS,
            CountryCodeIN,
            CountryCodeID,
            CountryCodeIR,
            CountryCodeIQ,
            CountryCodeIE,
            CountryCodeIM,
            CountryCodeIL,
            CountryCodeIT,
            CountryCodeJM,
            CountryCodeJP,
            CountryCodeJE,
            CountryCodeJO,
            CountryCodeKZ,
            CountryCodeKE,
            CountryCodeKI,
            CountryCodeKP,
            CountryCodeKR,
            CountryCodeKW,
            CountryCodeKG,
            CountryCodeLA,
            CountryCodeLV,
            CountryCodeLB,
            CountryCodeLS,
            CountryCodeLR,
            CountryCodeLY,
            CountryCodeLI,
            CountryCodeLT,
            CountryCodeLU,
            CountryCodeMO,
            CountryCodeMK,
            CountryCodeMG,
            CountryCodeMW,
            CountryCodeMY,
            CountryCodeMV,
            CountryCodeML,
            CountryCodeMT,
            CountryCodeMH,
            CountryCodeMQ,
            CountryCodeMR,
            CountryCodeMU,
            CountryCodeYT,
            CountryCodeMX,
            CountryCodeFM,
            CountryCodeMD,
            CountryCodeMC,
            CountryCodeMN,
            CountryCodeME,
            CountryCodeMS,
            CountryCodeMA,
            CountryCodeMZ,
            CountryCodeMM,
            CountryCodeNA,
            CountryCodeNR,
            CountryCodeNP,
            CountryCodeNL,
            CountryCodeNC,
            CountryCodeNZ,
            CountryCodeNI,
            CountryCodeNE,
            CountryCodeNG,
            CountryCodeNU,
            CountryCodeNF,
            CountryCodeMP,
            CountryCodeNO,
            CountryCodeOM,
            CountryCodePK,
            CountryCodePW,
            CountryCodePS,
            CountryCodePA,
            CountryCodePG,
            CountryCodePY,
            CountryCodePE,
            CountryCodePH,
            CountryCodePN,
            CountryCodePL,
            CountryCodePT,
            CountryCodePR,
            CountryCodeQA,
            CountryCodeRE,
            CountryCodeRO,
            CountryCodeRU,
            CountryCodeRW,
            CountryCodeBL,
            CountryCodeSH,
            CountryCodeKN,
            CountryCodeLC,
            CountryCodeMF,
            CountryCodePM,
            CountryCodeVC,
            CountryCodeWS,
            CountryCodeSM,
            CountryCodeST,
            CountryCodeSA,
            CountryCodeSN,
            CountryCodeRS,
            CountryCodeSC,
            CountryCodeSL,
            CountryCodeSG,
            CountryCodeSX,
            CountryCodeSK,
            CountryCodeSI,
            CountryCodeSB,
            CountryCodeSO,
            CountryCodeZA,
            CountryCodeGS,
            CountryCodeSS,
            CountryCodeES,
            CountryCodeLK,
            CountryCodeSD,
            CountryCodeSR,
            CountryCodeSJ,
            CountryCodeSZ,
            CountryCodeSE,
            CountryCodeCH,
            CountryCodeSY,
            CountryCodeTW,
            CountryCodeTJ,
            CountryCodeTZ,
            CountryCodeTH,
            CountryCodeTL,
            CountryCodeTG,
            CountryCodeTK,
            CountryCodeTO,
            CountryCodeTT,
            CountryCodeTN,
            CountryCodeTR,
            CountryCodeTM,
            CountryCodeTC,
            CountryCodeTV,
            CountryCodeUG,
            CountryCodeUA,
            CountryCodeAE,
            CountryCodeGB,
            CountryCodeUS,
            CountryCodeUM,
            CountryCodeUY,
            CountryCodeUZ,
            CountryCodeVU,
            CountryCodeVE,
            CountryCodeVN,
            CountryCodeVG,
            CountryCodeVI,
            CountryCodeWF,
            CountryCodeEH,
            CountryCodeYE,
            CountryCodeZM,
            CountryCodeZW
        };

        inline void ToJsonEnum(const CountryCode input, web::json::value& output)
        {
            if (input == CountryCodeAF) output = web::json::value(U("AF"));
            if (input == CountryCodeAX) output = web::json::value(U("AX"));
            if (input == CountryCodeAL) output = web::json::value(U("AL"));
            if (input == CountryCodeDZ) output = web::json::value(U("DZ"));
            if (input == CountryCodeAS) output = web::json::value(U("AS"));
            if (input == CountryCodeAD) output = web::json::value(U("AD"));
            if (input == CountryCodeAO) output = web::json::value(U("AO"));
            if (input == CountryCodeAI) output = web::json::value(U("AI"));
            if (input == CountryCodeAQ) output = web::json::value(U("AQ"));
            if (input == CountryCodeAG) output = web::json::value(U("AG"));
            if (input == CountryCodeAR) output = web::json::value(U("AR"));
            if (input == CountryCodeAM) output = web::json::value(U("AM"));
            if (input == CountryCodeAW) output = web::json::value(U("AW"));
            if (input == CountryCodeAU) output = web::json::value(U("AU"));
            if (input == CountryCodeAT) output = web::json::value(U("AT"));
            if (input == CountryCodeAZ) output = web::json::value(U("AZ"));
            if (input == CountryCodeBS) output = web::json::value(U("BS"));
            if (input == CountryCodeBH) output = web::json::value(U("BH"));
            if (input == CountryCodeBD) output = web::json::value(U("BD"));
            if (input == CountryCodeBB) output = web::json::value(U("BB"));
            if (input == CountryCodeBY) output = web::json::value(U("BY"));
            if (input == CountryCodeBE) output = web::json::value(U("BE"));
            if (input == CountryCodeBZ) output = web::json::value(U("BZ"));
            if (input == CountryCodeBJ) output = web::json::value(U("BJ"));
            if (input == CountryCodeBM) output = web::json::value(U("BM"));
            if (input == CountryCodeBT) output = web::json::value(U("BT"));
            if (input == CountryCodeBO) output = web::json::value(U("BO"));
            if (input == CountryCodeBQ) output = web::json::value(U("BQ"));
            if (input == CountryCodeBA) output = web::json::value(U("BA"));
            if (input == CountryCodeBW) output = web::json::value(U("BW"));
            if (input == CountryCodeBV) output = web::json::value(U("BV"));
            if (input == CountryCodeBR) output = web::json::value(U("BR"));
            if (input == CountryCodeIO) output = web::json::value(U("IO"));
            if (input == CountryCodeBN) output = web::json::value(U("BN"));
            if (input == CountryCodeBG) output = web::json::value(U("BG"));
            if (input == CountryCodeBF) output = web::json::value(U("BF"));
            if (input == CountryCodeBI) output = web::json::value(U("BI"));
            if (input == CountryCodeKH) output = web::json::value(U("KH"));
            if (input == CountryCodeCM) output = web::json::value(U("CM"));
            if (input == CountryCodeCA) output = web::json::value(U("CA"));
            if (input == CountryCodeCV) output = web::json::value(U("CV"));
            if (input == CountryCodeKY) output = web::json::value(U("KY"));
            if (input == CountryCodeCF) output = web::json::value(U("CF"));
            if (input == CountryCodeTD) output = web::json::value(U("TD"));
            if (input == CountryCodeCL) output = web::json::value(U("CL"));
            if (input == CountryCodeCN) output = web::json::value(U("CN"));
            if (input == CountryCodeCX) output = web::json::value(U("CX"));
            if (input == CountryCodeCC) output = web::json::value(U("CC"));
            if (input == CountryCodeCO) output = web::json::value(U("CO"));
            if (input == CountryCodeKM) output = web::json::value(U("KM"));
            if (input == CountryCodeCG) output = web::json::value(U("CG"));
            if (input == CountryCodeCD) output = web::json::value(U("CD"));
            if (input == CountryCodeCK) output = web::json::value(U("CK"));
            if (input == CountryCodeCR) output = web::json::value(U("CR"));
            if (input == CountryCodeCI) output = web::json::value(U("CI"));
            if (input == CountryCodeHR) output = web::json::value(U("HR"));
            if (input == CountryCodeCU) output = web::json::value(U("CU"));
            if (input == CountryCodeCW) output = web::json::value(U("CW"));
            if (input == CountryCodeCY) output = web::json::value(U("CY"));
            if (input == CountryCodeCZ) output = web::json::value(U("CZ"));
            if (input == CountryCodeDK) output = web::json::value(U("DK"));
            if (input == CountryCodeDJ) output = web::json::value(U("DJ"));
            if (input == CountryCodeDM) output = web::json::value(U("DM"));
            if (input == CountryCodeDO) output = web::json::value(U("DO"));
            if (input == CountryCodeEC) output = web::json::value(U("EC"));
            if (input == CountryCodeEG) output = web::json::value(U("EG"));
            if (input == CountryCodeSV) output = web::json::value(U("SV"));
            if (input == CountryCodeGQ) output = web::json::value(U("GQ"));
            if (input == CountryCodeER) output = web::json::value(U("ER"));
            if (input == CountryCodeEE) output = web::json::value(U("EE"));
            if (input == CountryCodeET) output = web::json::value(U("ET"));
            if (input == CountryCodeFK) output = web::json::value(U("FK"));
            if (input == CountryCodeFO) output = web::json::value(U("FO"));
            if (input == CountryCodeFJ) output = web::json::value(U("FJ"));
            if (input == CountryCodeFI) output = web::json::value(U("FI"));
            if (input == CountryCodeFR) output = web::json::value(U("FR"));
            if (input == CountryCodeGF) output = web::json::value(U("GF"));
            if (input == CountryCodePF) output = web::json::value(U("PF"));
            if (input == CountryCodeTF) output = web::json::value(U("TF"));
            if (input == CountryCodeGA) output = web::json::value(U("GA"));
            if (input == CountryCodeGM) output = web::json::value(U("GM"));
            if (input == CountryCodeGE) output = web::json::value(U("GE"));
            if (input == CountryCodeDE) output = web::json::value(U("DE"));
            if (input == CountryCodeGH) output = web::json::value(U("GH"));
            if (input == CountryCodeGI) output = web::json::value(U("GI"));
            if (input == CountryCodeGR) output = web::json::value(U("GR"));
            if (input == CountryCodeGL) output = web::json::value(U("GL"));
            if (input == CountryCodeGD) output = web::json::value(U("GD"));
            if (input == CountryCodeGP) output = web::json::value(U("GP"));
            if (input == CountryCodeGU) output = web::json::value(U("GU"));
            if (input == CountryCodeGT) output = web::json::value(U("GT"));
            if (input == CountryCodeGG) output = web::json::value(U("GG"));
            if (input == CountryCodeGN) output = web::json::value(U("GN"));
            if (input == CountryCodeGW) output = web::json::value(U("GW"));
            if (input == CountryCodeGY) output = web::json::value(U("GY"));
            if (input == CountryCodeHT) output = web::json::value(U("HT"));
            if (input == CountryCodeHM) output = web::json::value(U("HM"));
            if (input == CountryCodeVA) output = web::json::value(U("VA"));
            if (input == CountryCodeHN) output = web::json::value(U("HN"));
            if (input == CountryCodeHK) output = web::json::value(U("HK"));
            if (input == CountryCodeHU) output = web::json::value(U("HU"));
            if (input == CountryCodeIS) output = web::json::value(U("IS"));
            if (input == CountryCodeIN) output = web::json::value(U("IN"));
            if (input == CountryCodeID) output = web::json::value(U("ID"));
            if (input == CountryCodeIR) output = web::json::value(U("IR"));
            if (input == CountryCodeIQ) output = web::json::value(U("IQ"));
            if (input == CountryCodeIE) output = web::json::value(U("IE"));
            if (input == CountryCodeIM) output = web::json::value(U("IM"));
            if (input == CountryCodeIL) output = web::json::value(U("IL"));
            if (input == CountryCodeIT) output = web::json::value(U("IT"));
            if (input == CountryCodeJM) output = web::json::value(U("JM"));
            if (input == CountryCodeJP) output = web::json::value(U("JP"));
            if (input == CountryCodeJE) output = web::json::value(U("JE"));
            if (input == CountryCodeJO) output = web::json::value(U("JO"));
            if (input == CountryCodeKZ) output = web::json::value(U("KZ"));
            if (input == CountryCodeKE) output = web::json::value(U("KE"));
            if (input == CountryCodeKI) output = web::json::value(U("KI"));
            if (input == CountryCodeKP) output = web::json::value(U("KP"));
            if (input == CountryCodeKR) output = web::json::value(U("KR"));
            if (input == CountryCodeKW) output = web::json::value(U("KW"));
            if (input == CountryCodeKG) output = web::json::value(U("KG"));
            if (input == CountryCodeLA) output = web::json::value(U("LA"));
            if (input == CountryCodeLV) output = web::json::value(U("LV"));
            if (input == CountryCodeLB) output = web::json::value(U("LB"));
            if (input == CountryCodeLS) output = web::json::value(U("LS"));
            if (input == CountryCodeLR) output = web::json::value(U("LR"));
            if (input == CountryCodeLY) output = web::json::value(U("LY"));
            if (input == CountryCodeLI) output = web::json::value(U("LI"));
            if (input == CountryCodeLT) output = web::json::value(U("LT"));
            if (input == CountryCodeLU) output = web::json::value(U("LU"));
            if (input == CountryCodeMO) output = web::json::value(U("MO"));
            if (input == CountryCodeMK) output = web::json::value(U("MK"));
            if (input == CountryCodeMG) output = web::json::value(U("MG"));
            if (input == CountryCodeMW) output = web::json::value(U("MW"));
            if (input == CountryCodeMY) output = web::json::value(U("MY"));
            if (input == CountryCodeMV) output = web::json::value(U("MV"));
            if (input == CountryCodeML) output = web::json::value(U("ML"));
            if (input == CountryCodeMT) output = web::json::value(U("MT"));
            if (input == CountryCodeMH) output = web::json::value(U("MH"));
            if (input == CountryCodeMQ) output = web::json::value(U("MQ"));
            if (input == CountryCodeMR) output = web::json::value(U("MR"));
            if (input == CountryCodeMU) output = web::json::value(U("MU"));
            if (input == CountryCodeYT) output = web::json::value(U("YT"));
            if (input == CountryCodeMX) output = web::json::value(U("MX"));
            if (input == CountryCodeFM) output = web::json::value(U("FM"));
            if (input == CountryCodeMD) output = web::json::value(U("MD"));
            if (input == CountryCodeMC) output = web::json::value(U("MC"));
            if (input == CountryCodeMN) output = web::json::value(U("MN"));
            if (input == CountryCodeME) output = web::json::value(U("ME"));
            if (input == CountryCodeMS) output = web::json::value(U("MS"));
            if (input == CountryCodeMA) output = web::json::value(U("MA"));
            if (input == CountryCodeMZ) output = web::json::value(U("MZ"));
            if (input == CountryCodeMM) output = web::json::value(U("MM"));
            if (input == CountryCodeNA) output = web::json::value(U("NA"));
            if (input == CountryCodeNR) output = web::json::value(U("NR"));
            if (input == CountryCodeNP) output = web::json::value(U("NP"));
            if (input == CountryCodeNL) output = web::json::value(U("NL"));
            if (input == CountryCodeNC) output = web::json::value(U("NC"));
            if (input == CountryCodeNZ) output = web::json::value(U("NZ"));
            if (input == CountryCodeNI) output = web::json::value(U("NI"));
            if (input == CountryCodeNE) output = web::json::value(U("NE"));
            if (input == CountryCodeNG) output = web::json::value(U("NG"));
            if (input == CountryCodeNU) output = web::json::value(U("NU"));
            if (input == CountryCodeNF) output = web::json::value(U("NF"));
            if (input == CountryCodeMP) output = web::json::value(U("MP"));
            if (input == CountryCodeNO) output = web::json::value(U("NO"));
            if (input == CountryCodeOM) output = web::json::value(U("OM"));
            if (input == CountryCodePK) output = web::json::value(U("PK"));
            if (input == CountryCodePW) output = web::json::value(U("PW"));
            if (input == CountryCodePS) output = web::json::value(U("PS"));
            if (input == CountryCodePA) output = web::json::value(U("PA"));
            if (input == CountryCodePG) output = web::json::value(U("PG"));
            if (input == CountryCodePY) output = web::json::value(U("PY"));
            if (input == CountryCodePE) output = web::json::value(U("PE"));
            if (input == CountryCodePH) output = web::json::value(U("PH"));
            if (input == CountryCodePN) output = web::json::value(U("PN"));
            if (input == CountryCodePL) output = web::json::value(U("PL"));
            if (input == CountryCodePT) output = web::json::value(U("PT"));
            if (input == CountryCodePR) output = web::json::value(U("PR"));
            if (input == CountryCodeQA) output = web::json::value(U("QA"));
            if (input == CountryCodeRE) output = web::json::value(U("RE"));
            if (input == CountryCodeRO) output = web::json::value(U("RO"));
            if (input == CountryCodeRU) output = web::json::value(U("RU"));
            if (input == CountryCodeRW) output = web::json::value(U("RW"));
            if (input == CountryCodeBL) output = web::json::value(U("BL"));
            if (input == CountryCodeSH) output = web::json::value(U("SH"));
            if (input == CountryCodeKN) output = web::json::value(U("KN"));
            if (input == CountryCodeLC) output = web::json::value(U("LC"));
            if (input == CountryCodeMF) output = web::json::value(U("MF"));
            if (input == CountryCodePM) output = web::json::value(U("PM"));
            if (input == CountryCodeVC) output = web::json::value(U("VC"));
            if (input == CountryCodeWS) output = web::json::value(U("WS"));
            if (input == CountryCodeSM) output = web::json::value(U("SM"));
            if (input == CountryCodeST) output = web::json::value(U("ST"));
            if (input == CountryCodeSA) output = web::json::value(U("SA"));
            if (input == CountryCodeSN) output = web::json::value(U("SN"));
            if (input == CountryCodeRS) output = web::json::value(U("RS"));
            if (input == CountryCodeSC) output = web::json::value(U("SC"));
            if (input == CountryCodeSL) output = web::json::value(U("SL"));
            if (input == CountryCodeSG) output = web::json::value(U("SG"));
            if (input == CountryCodeSX) output = web::json::value(U("SX"));
            if (input == CountryCodeSK) output = web::json::value(U("SK"));
            if (input == CountryCodeSI) output = web::json::value(U("SI"));
            if (input == CountryCodeSB) output = web::json::value(U("SB"));
            if (input == CountryCodeSO) output = web::json::value(U("SO"));
            if (input == CountryCodeZA) output = web::json::value(U("ZA"));
            if (input == CountryCodeGS) output = web::json::value(U("GS"));
            if (input == CountryCodeSS) output = web::json::value(U("SS"));
            if (input == CountryCodeES) output = web::json::value(U("ES"));
            if (input == CountryCodeLK) output = web::json::value(U("LK"));
            if (input == CountryCodeSD) output = web::json::value(U("SD"));
            if (input == CountryCodeSR) output = web::json::value(U("SR"));
            if (input == CountryCodeSJ) output = web::json::value(U("SJ"));
            if (input == CountryCodeSZ) output = web::json::value(U("SZ"));
            if (input == CountryCodeSE) output = web::json::value(U("SE"));
            if (input == CountryCodeCH) output = web::json::value(U("CH"));
            if (input == CountryCodeSY) output = web::json::value(U("SY"));
            if (input == CountryCodeTW) output = web::json::value(U("TW"));
            if (input == CountryCodeTJ) output = web::json::value(U("TJ"));
            if (input == CountryCodeTZ) output = web::json::value(U("TZ"));
            if (input == CountryCodeTH) output = web::json::value(U("TH"));
            if (input == CountryCodeTL) output = web::json::value(U("TL"));
            if (input == CountryCodeTG) output = web::json::value(U("TG"));
            if (input == CountryCodeTK) output = web::json::value(U("TK"));
            if (input == CountryCodeTO) output = web::json::value(U("TO"));
            if (input == CountryCodeTT) output = web::json::value(U("TT"));
            if (input == CountryCodeTN) output = web::json::value(U("TN"));
            if (input == CountryCodeTR) output = web::json::value(U("TR"));
            if (input == CountryCodeTM) output = web::json::value(U("TM"));
            if (input == CountryCodeTC) output = web::json::value(U("TC"));
            if (input == CountryCodeTV) output = web::json::value(U("TV"));
            if (input == CountryCodeUG) output = web::json::value(U("UG"));
            if (input == CountryCodeUA) output = web::json::value(U("UA"));
            if (input == CountryCodeAE) output = web::json::value(U("AE"));
            if (input == CountryCodeGB) output = web::json::value(U("GB"));
            if (input == CountryCodeUS) output = web::json::value(U("US"));
            if (input == CountryCodeUM) output = web::json::value(U("UM"));
            if (input == CountryCodeUY) output = web::json::value(U("UY"));
            if (input == CountryCodeUZ) output = web::json::value(U("UZ"));
            if (input == CountryCodeVU) output = web::json::value(U("VU"));
            if (input == CountryCodeVE) output = web::json::value(U("VE"));
            if (input == CountryCodeVN) output = web::json::value(U("VN"));
            if (input == CountryCodeVG) output = web::json::value(U("VG"));
            if (input == CountryCodeVI) output = web::json::value(U("VI"));
            if (input == CountryCodeWF) output = web::json::value(U("WF"));
            if (input == CountryCodeEH) output = web::json::value(U("EH"));
            if (input == CountryCodeYE) output = web::json::value(U("YE"));
            if (input == CountryCodeZM) output = web::json::value(U("ZM"));
            if (input == CountryCodeZW) output = web::json::value(U("ZW"));
        }
        inline void FromJsonEnum(const web::json::value& input, CountryCode& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("AF")) output = CountryCodeAF;
            if (inputStr == U("AX")) output = CountryCodeAX;
            if (inputStr == U("AL")) output = CountryCodeAL;
            if (inputStr == U("DZ")) output = CountryCodeDZ;
            if (inputStr == U("AS")) output = CountryCodeAS;
            if (inputStr == U("AD")) output = CountryCodeAD;
            if (inputStr == U("AO")) output = CountryCodeAO;
            if (inputStr == U("AI")) output = CountryCodeAI;
            if (inputStr == U("AQ")) output = CountryCodeAQ;
            if (inputStr == U("AG")) output = CountryCodeAG;
            if (inputStr == U("AR")) output = CountryCodeAR;
            if (inputStr == U("AM")) output = CountryCodeAM;
            if (inputStr == U("AW")) output = CountryCodeAW;
            if (inputStr == U("AU")) output = CountryCodeAU;
            if (inputStr == U("AT")) output = CountryCodeAT;
            if (inputStr == U("AZ")) output = CountryCodeAZ;
            if (inputStr == U("BS")) output = CountryCodeBS;
            if (inputStr == U("BH")) output = CountryCodeBH;
            if (inputStr == U("BD")) output = CountryCodeBD;
            if (inputStr == U("BB")) output = CountryCodeBB;
            if (inputStr == U("BY")) output = CountryCodeBY;
            if (inputStr == U("BE")) output = CountryCodeBE;
            if (inputStr == U("BZ")) output = CountryCodeBZ;
            if (inputStr == U("BJ")) output = CountryCodeBJ;
            if (inputStr == U("BM")) output = CountryCodeBM;
            if (inputStr == U("BT")) output = CountryCodeBT;
            if (inputStr == U("BO")) output = CountryCodeBO;
            if (inputStr == U("BQ")) output = CountryCodeBQ;
            if (inputStr == U("BA")) output = CountryCodeBA;
            if (inputStr == U("BW")) output = CountryCodeBW;
            if (inputStr == U("BV")) output = CountryCodeBV;
            if (inputStr == U("BR")) output = CountryCodeBR;
            if (inputStr == U("IO")) output = CountryCodeIO;
            if (inputStr == U("BN")) output = CountryCodeBN;
            if (inputStr == U("BG")) output = CountryCodeBG;
            if (inputStr == U("BF")) output = CountryCodeBF;
            if (inputStr == U("BI")) output = CountryCodeBI;
            if (inputStr == U("KH")) output = CountryCodeKH;
            if (inputStr == U("CM")) output = CountryCodeCM;
            if (inputStr == U("CA")) output = CountryCodeCA;
            if (inputStr == U("CV")) output = CountryCodeCV;
            if (inputStr == U("KY")) output = CountryCodeKY;
            if (inputStr == U("CF")) output = CountryCodeCF;
            if (inputStr == U("TD")) output = CountryCodeTD;
            if (inputStr == U("CL")) output = CountryCodeCL;
            if (inputStr == U("CN")) output = CountryCodeCN;
            if (inputStr == U("CX")) output = CountryCodeCX;
            if (inputStr == U("CC")) output = CountryCodeCC;
            if (inputStr == U("CO")) output = CountryCodeCO;
            if (inputStr == U("KM")) output = CountryCodeKM;
            if (inputStr == U("CG")) output = CountryCodeCG;
            if (inputStr == U("CD")) output = CountryCodeCD;
            if (inputStr == U("CK")) output = CountryCodeCK;
            if (inputStr == U("CR")) output = CountryCodeCR;
            if (inputStr == U("CI")) output = CountryCodeCI;
            if (inputStr == U("HR")) output = CountryCodeHR;
            if (inputStr == U("CU")) output = CountryCodeCU;
            if (inputStr == U("CW")) output = CountryCodeCW;
            if (inputStr == U("CY")) output = CountryCodeCY;
            if (inputStr == U("CZ")) output = CountryCodeCZ;
            if (inputStr == U("DK")) output = CountryCodeDK;
            if (inputStr == U("DJ")) output = CountryCodeDJ;
            if (inputStr == U("DM")) output = CountryCodeDM;
            if (inputStr == U("DO")) output = CountryCodeDO;
            if (inputStr == U("EC")) output = CountryCodeEC;
            if (inputStr == U("EG")) output = CountryCodeEG;
            if (inputStr == U("SV")) output = CountryCodeSV;
            if (inputStr == U("GQ")) output = CountryCodeGQ;
            if (inputStr == U("ER")) output = CountryCodeER;
            if (inputStr == U("EE")) output = CountryCodeEE;
            if (inputStr == U("ET")) output = CountryCodeET;
            if (inputStr == U("FK")) output = CountryCodeFK;
            if (inputStr == U("FO")) output = CountryCodeFO;
            if (inputStr == U("FJ")) output = CountryCodeFJ;
            if (inputStr == U("FI")) output = CountryCodeFI;
            if (inputStr == U("FR")) output = CountryCodeFR;
            if (inputStr == U("GF")) output = CountryCodeGF;
            if (inputStr == U("PF")) output = CountryCodePF;
            if (inputStr == U("TF")) output = CountryCodeTF;
            if (inputStr == U("GA")) output = CountryCodeGA;
            if (inputStr == U("GM")) output = CountryCodeGM;
            if (inputStr == U("GE")) output = CountryCodeGE;
            if (inputStr == U("DE")) output = CountryCodeDE;
            if (inputStr == U("GH")) output = CountryCodeGH;
            if (inputStr == U("GI")) output = CountryCodeGI;
            if (inputStr == U("GR")) output = CountryCodeGR;
            if (inputStr == U("GL")) output = CountryCodeGL;
            if (inputStr == U("GD")) output = CountryCodeGD;
            if (inputStr == U("GP")) output = CountryCodeGP;
            if (inputStr == U("GU")) output = CountryCodeGU;
            if (inputStr == U("GT")) output = CountryCodeGT;
            if (inputStr == U("GG")) output = CountryCodeGG;
            if (inputStr == U("GN")) output = CountryCodeGN;
            if (inputStr == U("GW")) output = CountryCodeGW;
            if (inputStr == U("GY")) output = CountryCodeGY;
            if (inputStr == U("HT")) output = CountryCodeHT;
            if (inputStr == U("HM")) output = CountryCodeHM;
            if (inputStr == U("VA")) output = CountryCodeVA;
            if (inputStr == U("HN")) output = CountryCodeHN;
            if (inputStr == U("HK")) output = CountryCodeHK;
            if (inputStr == U("HU")) output = CountryCodeHU;
            if (inputStr == U("IS")) output = CountryCodeIS;
            if (inputStr == U("IN")) output = CountryCodeIN;
            if (inputStr == U("ID")) output = CountryCodeID;
            if (inputStr == U("IR")) output = CountryCodeIR;
            if (inputStr == U("IQ")) output = CountryCodeIQ;
            if (inputStr == U("IE")) output = CountryCodeIE;
            if (inputStr == U("IM")) output = CountryCodeIM;
            if (inputStr == U("IL")) output = CountryCodeIL;
            if (inputStr == U("IT")) output = CountryCodeIT;
            if (inputStr == U("JM")) output = CountryCodeJM;
            if (inputStr == U("JP")) output = CountryCodeJP;
            if (inputStr == U("JE")) output = CountryCodeJE;
            if (inputStr == U("JO")) output = CountryCodeJO;
            if (inputStr == U("KZ")) output = CountryCodeKZ;
            if (inputStr == U("KE")) output = CountryCodeKE;
            if (inputStr == U("KI")) output = CountryCodeKI;
            if (inputStr == U("KP")) output = CountryCodeKP;
            if (inputStr == U("KR")) output = CountryCodeKR;
            if (inputStr == U("KW")) output = CountryCodeKW;
            if (inputStr == U("KG")) output = CountryCodeKG;
            if (inputStr == U("LA")) output = CountryCodeLA;
            if (inputStr == U("LV")) output = CountryCodeLV;
            if (inputStr == U("LB")) output = CountryCodeLB;
            if (inputStr == U("LS")) output = CountryCodeLS;
            if (inputStr == U("LR")) output = CountryCodeLR;
            if (inputStr == U("LY")) output = CountryCodeLY;
            if (inputStr == U("LI")) output = CountryCodeLI;
            if (inputStr == U("LT")) output = CountryCodeLT;
            if (inputStr == U("LU")) output = CountryCodeLU;
            if (inputStr == U("MO")) output = CountryCodeMO;
            if (inputStr == U("MK")) output = CountryCodeMK;
            if (inputStr == U("MG")) output = CountryCodeMG;
            if (inputStr == U("MW")) output = CountryCodeMW;
            if (inputStr == U("MY")) output = CountryCodeMY;
            if (inputStr == U("MV")) output = CountryCodeMV;
            if (inputStr == U("ML")) output = CountryCodeML;
            if (inputStr == U("MT")) output = CountryCodeMT;
            if (inputStr == U("MH")) output = CountryCodeMH;
            if (inputStr == U("MQ")) output = CountryCodeMQ;
            if (inputStr == U("MR")) output = CountryCodeMR;
            if (inputStr == U("MU")) output = CountryCodeMU;
            if (inputStr == U("YT")) output = CountryCodeYT;
            if (inputStr == U("MX")) output = CountryCodeMX;
            if (inputStr == U("FM")) output = CountryCodeFM;
            if (inputStr == U("MD")) output = CountryCodeMD;
            if (inputStr == U("MC")) output = CountryCodeMC;
            if (inputStr == U("MN")) output = CountryCodeMN;
            if (inputStr == U("ME")) output = CountryCodeME;
            if (inputStr == U("MS")) output = CountryCodeMS;
            if (inputStr == U("MA")) output = CountryCodeMA;
            if (inputStr == U("MZ")) output = CountryCodeMZ;
            if (inputStr == U("MM")) output = CountryCodeMM;
            if (inputStr == U("NA")) output = CountryCodeNA;
            if (inputStr == U("NR")) output = CountryCodeNR;
            if (inputStr == U("NP")) output = CountryCodeNP;
            if (inputStr == U("NL")) output = CountryCodeNL;
            if (inputStr == U("NC")) output = CountryCodeNC;
            if (inputStr == U("NZ")) output = CountryCodeNZ;
            if (inputStr == U("NI")) output = CountryCodeNI;
            if (inputStr == U("NE")) output = CountryCodeNE;
            if (inputStr == U("NG")) output = CountryCodeNG;
            if (inputStr == U("NU")) output = CountryCodeNU;
            if (inputStr == U("NF")) output = CountryCodeNF;
            if (inputStr == U("MP")) output = CountryCodeMP;
            if (inputStr == U("NO")) output = CountryCodeNO;
            if (inputStr == U("OM")) output = CountryCodeOM;
            if (inputStr == U("PK")) output = CountryCodePK;
            if (inputStr == U("PW")) output = CountryCodePW;
            if (inputStr == U("PS")) output = CountryCodePS;
            if (inputStr == U("PA")) output = CountryCodePA;
            if (inputStr == U("PG")) output = CountryCodePG;
            if (inputStr == U("PY")) output = CountryCodePY;
            if (inputStr == U("PE")) output = CountryCodePE;
            if (inputStr == U("PH")) output = CountryCodePH;
            if (inputStr == U("PN")) output = CountryCodePN;
            if (inputStr == U("PL")) output = CountryCodePL;
            if (inputStr == U("PT")) output = CountryCodePT;
            if (inputStr == U("PR")) output = CountryCodePR;
            if (inputStr == U("QA")) output = CountryCodeQA;
            if (inputStr == U("RE")) output = CountryCodeRE;
            if (inputStr == U("RO")) output = CountryCodeRO;
            if (inputStr == U("RU")) output = CountryCodeRU;
            if (inputStr == U("RW")) output = CountryCodeRW;
            if (inputStr == U("BL")) output = CountryCodeBL;
            if (inputStr == U("SH")) output = CountryCodeSH;
            if (inputStr == U("KN")) output = CountryCodeKN;
            if (inputStr == U("LC")) output = CountryCodeLC;
            if (inputStr == U("MF")) output = CountryCodeMF;
            if (inputStr == U("PM")) output = CountryCodePM;
            if (inputStr == U("VC")) output = CountryCodeVC;
            if (inputStr == U("WS")) output = CountryCodeWS;
            if (inputStr == U("SM")) output = CountryCodeSM;
            if (inputStr == U("ST")) output = CountryCodeST;
            if (inputStr == U("SA")) output = CountryCodeSA;
            if (inputStr == U("SN")) output = CountryCodeSN;
            if (inputStr == U("RS")) output = CountryCodeRS;
            if (inputStr == U("SC")) output = CountryCodeSC;
            if (inputStr == U("SL")) output = CountryCodeSL;
            if (inputStr == U("SG")) output = CountryCodeSG;
            if (inputStr == U("SX")) output = CountryCodeSX;
            if (inputStr == U("SK")) output = CountryCodeSK;
            if (inputStr == U("SI")) output = CountryCodeSI;
            if (inputStr == U("SB")) output = CountryCodeSB;
            if (inputStr == U("SO")) output = CountryCodeSO;
            if (inputStr == U("ZA")) output = CountryCodeZA;
            if (inputStr == U("GS")) output = CountryCodeGS;
            if (inputStr == U("SS")) output = CountryCodeSS;
            if (inputStr == U("ES")) output = CountryCodeES;
            if (inputStr == U("LK")) output = CountryCodeLK;
            if (inputStr == U("SD")) output = CountryCodeSD;
            if (inputStr == U("SR")) output = CountryCodeSR;
            if (inputStr == U("SJ")) output = CountryCodeSJ;
            if (inputStr == U("SZ")) output = CountryCodeSZ;
            if (inputStr == U("SE")) output = CountryCodeSE;
            if (inputStr == U("CH")) output = CountryCodeCH;
            if (inputStr == U("SY")) output = CountryCodeSY;
            if (inputStr == U("TW")) output = CountryCodeTW;
            if (inputStr == U("TJ")) output = CountryCodeTJ;
            if (inputStr == U("TZ")) output = CountryCodeTZ;
            if (inputStr == U("TH")) output = CountryCodeTH;
            if (inputStr == U("TL")) output = CountryCodeTL;
            if (inputStr == U("TG")) output = CountryCodeTG;
            if (inputStr == U("TK")) output = CountryCodeTK;
            if (inputStr == U("TO")) output = CountryCodeTO;
            if (inputStr == U("TT")) output = CountryCodeTT;
            if (inputStr == U("TN")) output = CountryCodeTN;
            if (inputStr == U("TR")) output = CountryCodeTR;
            if (inputStr == U("TM")) output = CountryCodeTM;
            if (inputStr == U("TC")) output = CountryCodeTC;
            if (inputStr == U("TV")) output = CountryCodeTV;
            if (inputStr == U("UG")) output = CountryCodeUG;
            if (inputStr == U("UA")) output = CountryCodeUA;
            if (inputStr == U("AE")) output = CountryCodeAE;
            if (inputStr == U("GB")) output = CountryCodeGB;
            if (inputStr == U("US")) output = CountryCodeUS;
            if (inputStr == U("UM")) output = CountryCodeUM;
            if (inputStr == U("UY")) output = CountryCodeUY;
            if (inputStr == U("UZ")) output = CountryCodeUZ;
            if (inputStr == U("VU")) output = CountryCodeVU;
            if (inputStr == U("VE")) output = CountryCodeVE;
            if (inputStr == U("VN")) output = CountryCodeVN;
            if (inputStr == U("VG")) output = CountryCodeVG;
            if (inputStr == U("VI")) output = CountryCodeVI;
            if (inputStr == U("WF")) output = CountryCodeWF;
            if (inputStr == U("EH")) output = CountryCodeEH;
            if (inputStr == U("YE")) output = CountryCodeYE;
            if (inputStr == U("ZM")) output = CountryCodeZM;
            if (inputStr == U("ZW")) output = CountryCodeZW;
        }

        enum Currency
        {
            CurrencyAED,
            CurrencyAFN,
            CurrencyALL,
            CurrencyAMD,
            CurrencyANG,
            CurrencyAOA,
            CurrencyARS,
            CurrencyAUD,
            CurrencyAWG,
            CurrencyAZN,
            CurrencyBAM,
            CurrencyBBD,
            CurrencyBDT,
            CurrencyBGN,
            CurrencyBHD,
            CurrencyBIF,
            CurrencyBMD,
            CurrencyBND,
            CurrencyBOB,
            CurrencyBRL,
            CurrencyBSD,
            CurrencyBTN,
            CurrencyBWP,
            CurrencyBYR,
            CurrencyBZD,
            CurrencyCAD,
            CurrencyCDF,
            CurrencyCHF,
            CurrencyCLP,
            CurrencyCNY,
            CurrencyCOP,
            CurrencyCRC,
            CurrencyCUC,
            CurrencyCUP,
            CurrencyCVE,
            CurrencyCZK,
            CurrencyDJF,
            CurrencyDKK,
            CurrencyDOP,
            CurrencyDZD,
            CurrencyEGP,
            CurrencyERN,
            CurrencyETB,
            CurrencyEUR,
            CurrencyFJD,
            CurrencyFKP,
            CurrencyGBP,
            CurrencyGEL,
            CurrencyGGP,
            CurrencyGHS,
            CurrencyGIP,
            CurrencyGMD,
            CurrencyGNF,
            CurrencyGTQ,
            CurrencyGYD,
            CurrencyHKD,
            CurrencyHNL,
            CurrencyHRK,
            CurrencyHTG,
            CurrencyHUF,
            CurrencyIDR,
            CurrencyILS,
            CurrencyIMP,
            CurrencyINR,
            CurrencyIQD,
            CurrencyIRR,
            CurrencyISK,
            CurrencyJEP,
            CurrencyJMD,
            CurrencyJOD,
            CurrencyJPY,
            CurrencyKES,
            CurrencyKGS,
            CurrencyKHR,
            CurrencyKMF,
            CurrencyKPW,
            CurrencyKRW,
            CurrencyKWD,
            CurrencyKYD,
            CurrencyKZT,
            CurrencyLAK,
            CurrencyLBP,
            CurrencyLKR,
            CurrencyLRD,
            CurrencyLSL,
            CurrencyLYD,
            CurrencyMAD,
            CurrencyMDL,
            CurrencyMGA,
            CurrencyMKD,
            CurrencyMMK,
            CurrencyMNT,
            CurrencyMOP,
            CurrencyMRO,
            CurrencyMUR,
            CurrencyMVR,
            CurrencyMWK,
            CurrencyMXN,
            CurrencyMYR,
            CurrencyMZN,
            CurrencyNAD,
            CurrencyNGN,
            CurrencyNIO,
            CurrencyNOK,
            CurrencyNPR,
            CurrencyNZD,
            CurrencyOMR,
            CurrencyPAB,
            CurrencyPEN,
            CurrencyPGK,
            CurrencyPHP,
            CurrencyPKR,
            CurrencyPLN,
            CurrencyPYG,
            CurrencyQAR,
            CurrencyRON,
            CurrencyRSD,
            CurrencyRUB,
            CurrencyRWF,
            CurrencySAR,
            CurrencySBD,
            CurrencySCR,
            CurrencySDG,
            CurrencySEK,
            CurrencySGD,
            CurrencySHP,
            CurrencySLL,
            CurrencySOS,
            CurrencySPL,
            CurrencySRD,
            CurrencySTD,
            CurrencySVC,
            CurrencySYP,
            CurrencySZL,
            CurrencyTHB,
            CurrencyTJS,
            CurrencyTMT,
            CurrencyTND,
            CurrencyTOP,
            CurrencyTRY,
            CurrencyTTD,
            CurrencyTVD,
            CurrencyTWD,
            CurrencyTZS,
            CurrencyUAH,
            CurrencyUGX,
            CurrencyUSD,
            CurrencyUYU,
            CurrencyUZS,
            CurrencyVEF,
            CurrencyVND,
            CurrencyVUV,
            CurrencyWST,
            CurrencyXAF,
            CurrencyXCD,
            CurrencyXDR,
            CurrencyXOF,
            CurrencyXPF,
            CurrencyYER,
            CurrencyZAR,
            CurrencyZMW,
            CurrencyZWD
        };

        inline void ToJsonEnum(const Currency input, web::json::value& output)
        {
            if (input == CurrencyAED) output = web::json::value(U("AED"));
            if (input == CurrencyAFN) output = web::json::value(U("AFN"));
            if (input == CurrencyALL) output = web::json::value(U("ALL"));
            if (input == CurrencyAMD) output = web::json::value(U("AMD"));
            if (input == CurrencyANG) output = web::json::value(U("ANG"));
            if (input == CurrencyAOA) output = web::json::value(U("AOA"));
            if (input == CurrencyARS) output = web::json::value(U("ARS"));
            if (input == CurrencyAUD) output = web::json::value(U("AUD"));
            if (input == CurrencyAWG) output = web::json::value(U("AWG"));
            if (input == CurrencyAZN) output = web::json::value(U("AZN"));
            if (input == CurrencyBAM) output = web::json::value(U("BAM"));
            if (input == CurrencyBBD) output = web::json::value(U("BBD"));
            if (input == CurrencyBDT) output = web::json::value(U("BDT"));
            if (input == CurrencyBGN) output = web::json::value(U("BGN"));
            if (input == CurrencyBHD) output = web::json::value(U("BHD"));
            if (input == CurrencyBIF) output = web::json::value(U("BIF"));
            if (input == CurrencyBMD) output = web::json::value(U("BMD"));
            if (input == CurrencyBND) output = web::json::value(U("BND"));
            if (input == CurrencyBOB) output = web::json::value(U("BOB"));
            if (input == CurrencyBRL) output = web::json::value(U("BRL"));
            if (input == CurrencyBSD) output = web::json::value(U("BSD"));
            if (input == CurrencyBTN) output = web::json::value(U("BTN"));
            if (input == CurrencyBWP) output = web::json::value(U("BWP"));
            if (input == CurrencyBYR) output = web::json::value(U("BYR"));
            if (input == CurrencyBZD) output = web::json::value(U("BZD"));
            if (input == CurrencyCAD) output = web::json::value(U("CAD"));
            if (input == CurrencyCDF) output = web::json::value(U("CDF"));
            if (input == CurrencyCHF) output = web::json::value(U("CHF"));
            if (input == CurrencyCLP) output = web::json::value(U("CLP"));
            if (input == CurrencyCNY) output = web::json::value(U("CNY"));
            if (input == CurrencyCOP) output = web::json::value(U("COP"));
            if (input == CurrencyCRC) output = web::json::value(U("CRC"));
            if (input == CurrencyCUC) output = web::json::value(U("CUC"));
            if (input == CurrencyCUP) output = web::json::value(U("CUP"));
            if (input == CurrencyCVE) output = web::json::value(U("CVE"));
            if (input == CurrencyCZK) output = web::json::value(U("CZK"));
            if (input == CurrencyDJF) output = web::json::value(U("DJF"));
            if (input == CurrencyDKK) output = web::json::value(U("DKK"));
            if (input == CurrencyDOP) output = web::json::value(U("DOP"));
            if (input == CurrencyDZD) output = web::json::value(U("DZD"));
            if (input == CurrencyEGP) output = web::json::value(U("EGP"));
            if (input == CurrencyERN) output = web::json::value(U("ERN"));
            if (input == CurrencyETB) output = web::json::value(U("ETB"));
            if (input == CurrencyEUR) output = web::json::value(U("EUR"));
            if (input == CurrencyFJD) output = web::json::value(U("FJD"));
            if (input == CurrencyFKP) output = web::json::value(U("FKP"));
            if (input == CurrencyGBP) output = web::json::value(U("GBP"));
            if (input == CurrencyGEL) output = web::json::value(U("GEL"));
            if (input == CurrencyGGP) output = web::json::value(U("GGP"));
            if (input == CurrencyGHS) output = web::json::value(U("GHS"));
            if (input == CurrencyGIP) output = web::json::value(U("GIP"));
            if (input == CurrencyGMD) output = web::json::value(U("GMD"));
            if (input == CurrencyGNF) output = web::json::value(U("GNF"));
            if (input == CurrencyGTQ) output = web::json::value(U("GTQ"));
            if (input == CurrencyGYD) output = web::json::value(U("GYD"));
            if (input == CurrencyHKD) output = web::json::value(U("HKD"));
            if (input == CurrencyHNL) output = web::json::value(U("HNL"));
            if (input == CurrencyHRK) output = web::json::value(U("HRK"));
            if (input == CurrencyHTG) output = web::json::value(U("HTG"));
            if (input == CurrencyHUF) output = web::json::value(U("HUF"));
            if (input == CurrencyIDR) output = web::json::value(U("IDR"));
            if (input == CurrencyILS) output = web::json::value(U("ILS"));
            if (input == CurrencyIMP) output = web::json::value(U("IMP"));
            if (input == CurrencyINR) output = web::json::value(U("INR"));
            if (input == CurrencyIQD) output = web::json::value(U("IQD"));
            if (input == CurrencyIRR) output = web::json::value(U("IRR"));
            if (input == CurrencyISK) output = web::json::value(U("ISK"));
            if (input == CurrencyJEP) output = web::json::value(U("JEP"));
            if (input == CurrencyJMD) output = web::json::value(U("JMD"));
            if (input == CurrencyJOD) output = web::json::value(U("JOD"));
            if (input == CurrencyJPY) output = web::json::value(U("JPY"));
            if (input == CurrencyKES) output = web::json::value(U("KES"));
            if (input == CurrencyKGS) output = web::json::value(U("KGS"));
            if (input == CurrencyKHR) output = web::json::value(U("KHR"));
            if (input == CurrencyKMF) output = web::json::value(U("KMF"));
            if (input == CurrencyKPW) output = web::json::value(U("KPW"));
            if (input == CurrencyKRW) output = web::json::value(U("KRW"));
            if (input == CurrencyKWD) output = web::json::value(U("KWD"));
            if (input == CurrencyKYD) output = web::json::value(U("KYD"));
            if (input == CurrencyKZT) output = web::json::value(U("KZT"));
            if (input == CurrencyLAK) output = web::json::value(U("LAK"));
            if (input == CurrencyLBP) output = web::json::value(U("LBP"));
            if (input == CurrencyLKR) output = web::json::value(U("LKR"));
            if (input == CurrencyLRD) output = web::json::value(U("LRD"));
            if (input == CurrencyLSL) output = web::json::value(U("LSL"));
            if (input == CurrencyLYD) output = web::json::value(U("LYD"));
            if (input == CurrencyMAD) output = web::json::value(U("MAD"));
            if (input == CurrencyMDL) output = web::json::value(U("MDL"));
            if (input == CurrencyMGA) output = web::json::value(U("MGA"));
            if (input == CurrencyMKD) output = web::json::value(U("MKD"));
            if (input == CurrencyMMK) output = web::json::value(U("MMK"));
            if (input == CurrencyMNT) output = web::json::value(U("MNT"));
            if (input == CurrencyMOP) output = web::json::value(U("MOP"));
            if (input == CurrencyMRO) output = web::json::value(U("MRO"));
            if (input == CurrencyMUR) output = web::json::value(U("MUR"));
            if (input == CurrencyMVR) output = web::json::value(U("MVR"));
            if (input == CurrencyMWK) output = web::json::value(U("MWK"));
            if (input == CurrencyMXN) output = web::json::value(U("MXN"));
            if (input == CurrencyMYR) output = web::json::value(U("MYR"));
            if (input == CurrencyMZN) output = web::json::value(U("MZN"));
            if (input == CurrencyNAD) output = web::json::value(U("NAD"));
            if (input == CurrencyNGN) output = web::json::value(U("NGN"));
            if (input == CurrencyNIO) output = web::json::value(U("NIO"));
            if (input == CurrencyNOK) output = web::json::value(U("NOK"));
            if (input == CurrencyNPR) output = web::json::value(U("NPR"));
            if (input == CurrencyNZD) output = web::json::value(U("NZD"));
            if (input == CurrencyOMR) output = web::json::value(U("OMR"));
            if (input == CurrencyPAB) output = web::json::value(U("PAB"));
            if (input == CurrencyPEN) output = web::json::value(U("PEN"));
            if (input == CurrencyPGK) output = web::json::value(U("PGK"));
            if (input == CurrencyPHP) output = web::json::value(U("PHP"));
            if (input == CurrencyPKR) output = web::json::value(U("PKR"));
            if (input == CurrencyPLN) output = web::json::value(U("PLN"));
            if (input == CurrencyPYG) output = web::json::value(U("PYG"));
            if (input == CurrencyQAR) output = web::json::value(U("QAR"));
            if (input == CurrencyRON) output = web::json::value(U("RON"));
            if (input == CurrencyRSD) output = web::json::value(U("RSD"));
            if (input == CurrencyRUB) output = web::json::value(U("RUB"));
            if (input == CurrencyRWF) output = web::json::value(U("RWF"));
            if (input == CurrencySAR) output = web::json::value(U("SAR"));
            if (input == CurrencySBD) output = web::json::value(U("SBD"));
            if (input == CurrencySCR) output = web::json::value(U("SCR"));
            if (input == CurrencySDG) output = web::json::value(U("SDG"));
            if (input == CurrencySEK) output = web::json::value(U("SEK"));
            if (input == CurrencySGD) output = web::json::value(U("SGD"));
            if (input == CurrencySHP) output = web::json::value(U("SHP"));
            if (input == CurrencySLL) output = web::json::value(U("SLL"));
            if (input == CurrencySOS) output = web::json::value(U("SOS"));
            if (input == CurrencySPL) output = web::json::value(U("SPL"));
            if (input == CurrencySRD) output = web::json::value(U("SRD"));
            if (input == CurrencySTD) output = web::json::value(U("STD"));
            if (input == CurrencySVC) output = web::json::value(U("SVC"));
            if (input == CurrencySYP) output = web::json::value(U("SYP"));
            if (input == CurrencySZL) output = web::json::value(U("SZL"));
            if (input == CurrencyTHB) output = web::json::value(U("THB"));
            if (input == CurrencyTJS) output = web::json::value(U("TJS"));
            if (input == CurrencyTMT) output = web::json::value(U("TMT"));
            if (input == CurrencyTND) output = web::json::value(U("TND"));
            if (input == CurrencyTOP) output = web::json::value(U("TOP"));
            if (input == CurrencyTRY) output = web::json::value(U("TRY"));
            if (input == CurrencyTTD) output = web::json::value(U("TTD"));
            if (input == CurrencyTVD) output = web::json::value(U("TVD"));
            if (input == CurrencyTWD) output = web::json::value(U("TWD"));
            if (input == CurrencyTZS) output = web::json::value(U("TZS"));
            if (input == CurrencyUAH) output = web::json::value(U("UAH"));
            if (input == CurrencyUGX) output = web::json::value(U("UGX"));
            if (input == CurrencyUSD) output = web::json::value(U("USD"));
            if (input == CurrencyUYU) output = web::json::value(U("UYU"));
            if (input == CurrencyUZS) output = web::json::value(U("UZS"));
            if (input == CurrencyVEF) output = web::json::value(U("VEF"));
            if (input == CurrencyVND) output = web::json::value(U("VND"));
            if (input == CurrencyVUV) output = web::json::value(U("VUV"));
            if (input == CurrencyWST) output = web::json::value(U("WST"));
            if (input == CurrencyXAF) output = web::json::value(U("XAF"));
            if (input == CurrencyXCD) output = web::json::value(U("XCD"));
            if (input == CurrencyXDR) output = web::json::value(U("XDR"));
            if (input == CurrencyXOF) output = web::json::value(U("XOF"));
            if (input == CurrencyXPF) output = web::json::value(U("XPF"));
            if (input == CurrencyYER) output = web::json::value(U("YER"));
            if (input == CurrencyZAR) output = web::json::value(U("ZAR"));
            if (input == CurrencyZMW) output = web::json::value(U("ZMW"));
            if (input == CurrencyZWD) output = web::json::value(U("ZWD"));
        }
        inline void FromJsonEnum(const web::json::value& input, Currency& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("AED")) output = CurrencyAED;
            if (inputStr == U("AFN")) output = CurrencyAFN;
            if (inputStr == U("ALL")) output = CurrencyALL;
            if (inputStr == U("AMD")) output = CurrencyAMD;
            if (inputStr == U("ANG")) output = CurrencyANG;
            if (inputStr == U("AOA")) output = CurrencyAOA;
            if (inputStr == U("ARS")) output = CurrencyARS;
            if (inputStr == U("AUD")) output = CurrencyAUD;
            if (inputStr == U("AWG")) output = CurrencyAWG;
            if (inputStr == U("AZN")) output = CurrencyAZN;
            if (inputStr == U("BAM")) output = CurrencyBAM;
            if (inputStr == U("BBD")) output = CurrencyBBD;
            if (inputStr == U("BDT")) output = CurrencyBDT;
            if (inputStr == U("BGN")) output = CurrencyBGN;
            if (inputStr == U("BHD")) output = CurrencyBHD;
            if (inputStr == U("BIF")) output = CurrencyBIF;
            if (inputStr == U("BMD")) output = CurrencyBMD;
            if (inputStr == U("BND")) output = CurrencyBND;
            if (inputStr == U("BOB")) output = CurrencyBOB;
            if (inputStr == U("BRL")) output = CurrencyBRL;
            if (inputStr == U("BSD")) output = CurrencyBSD;
            if (inputStr == U("BTN")) output = CurrencyBTN;
            if (inputStr == U("BWP")) output = CurrencyBWP;
            if (inputStr == U("BYR")) output = CurrencyBYR;
            if (inputStr == U("BZD")) output = CurrencyBZD;
            if (inputStr == U("CAD")) output = CurrencyCAD;
            if (inputStr == U("CDF")) output = CurrencyCDF;
            if (inputStr == U("CHF")) output = CurrencyCHF;
            if (inputStr == U("CLP")) output = CurrencyCLP;
            if (inputStr == U("CNY")) output = CurrencyCNY;
            if (inputStr == U("COP")) output = CurrencyCOP;
            if (inputStr == U("CRC")) output = CurrencyCRC;
            if (inputStr == U("CUC")) output = CurrencyCUC;
            if (inputStr == U("CUP")) output = CurrencyCUP;
            if (inputStr == U("CVE")) output = CurrencyCVE;
            if (inputStr == U("CZK")) output = CurrencyCZK;
            if (inputStr == U("DJF")) output = CurrencyDJF;
            if (inputStr == U("DKK")) output = CurrencyDKK;
            if (inputStr == U("DOP")) output = CurrencyDOP;
            if (inputStr == U("DZD")) output = CurrencyDZD;
            if (inputStr == U("EGP")) output = CurrencyEGP;
            if (inputStr == U("ERN")) output = CurrencyERN;
            if (inputStr == U("ETB")) output = CurrencyETB;
            if (inputStr == U("EUR")) output = CurrencyEUR;
            if (inputStr == U("FJD")) output = CurrencyFJD;
            if (inputStr == U("FKP")) output = CurrencyFKP;
            if (inputStr == U("GBP")) output = CurrencyGBP;
            if (inputStr == U("GEL")) output = CurrencyGEL;
            if (inputStr == U("GGP")) output = CurrencyGGP;
            if (inputStr == U("GHS")) output = CurrencyGHS;
            if (inputStr == U("GIP")) output = CurrencyGIP;
            if (inputStr == U("GMD")) output = CurrencyGMD;
            if (inputStr == U("GNF")) output = CurrencyGNF;
            if (inputStr == U("GTQ")) output = CurrencyGTQ;
            if (inputStr == U("GYD")) output = CurrencyGYD;
            if (inputStr == U("HKD")) output = CurrencyHKD;
            if (inputStr == U("HNL")) output = CurrencyHNL;
            if (inputStr == U("HRK")) output = CurrencyHRK;
            if (inputStr == U("HTG")) output = CurrencyHTG;
            if (inputStr == U("HUF")) output = CurrencyHUF;
            if (inputStr == U("IDR")) output = CurrencyIDR;
            if (inputStr == U("ILS")) output = CurrencyILS;
            if (inputStr == U("IMP")) output = CurrencyIMP;
            if (inputStr == U("INR")) output = CurrencyINR;
            if (inputStr == U("IQD")) output = CurrencyIQD;
            if (inputStr == U("IRR")) output = CurrencyIRR;
            if (inputStr == U("ISK")) output = CurrencyISK;
            if (inputStr == U("JEP")) output = CurrencyJEP;
            if (inputStr == U("JMD")) output = CurrencyJMD;
            if (inputStr == U("JOD")) output = CurrencyJOD;
            if (inputStr == U("JPY")) output = CurrencyJPY;
            if (inputStr == U("KES")) output = CurrencyKES;
            if (inputStr == U("KGS")) output = CurrencyKGS;
            if (inputStr == U("KHR")) output = CurrencyKHR;
            if (inputStr == U("KMF")) output = CurrencyKMF;
            if (inputStr == U("KPW")) output = CurrencyKPW;
            if (inputStr == U("KRW")) output = CurrencyKRW;
            if (inputStr == U("KWD")) output = CurrencyKWD;
            if (inputStr == U("KYD")) output = CurrencyKYD;
            if (inputStr == U("KZT")) output = CurrencyKZT;
            if (inputStr == U("LAK")) output = CurrencyLAK;
            if (inputStr == U("LBP")) output = CurrencyLBP;
            if (inputStr == U("LKR")) output = CurrencyLKR;
            if (inputStr == U("LRD")) output = CurrencyLRD;
            if (inputStr == U("LSL")) output = CurrencyLSL;
            if (inputStr == U("LYD")) output = CurrencyLYD;
            if (inputStr == U("MAD")) output = CurrencyMAD;
            if (inputStr == U("MDL")) output = CurrencyMDL;
            if (inputStr == U("MGA")) output = CurrencyMGA;
            if (inputStr == U("MKD")) output = CurrencyMKD;
            if (inputStr == U("MMK")) output = CurrencyMMK;
            if (inputStr == U("MNT")) output = CurrencyMNT;
            if (inputStr == U("MOP")) output = CurrencyMOP;
            if (inputStr == U("MRO")) output = CurrencyMRO;
            if (inputStr == U("MUR")) output = CurrencyMUR;
            if (inputStr == U("MVR")) output = CurrencyMVR;
            if (inputStr == U("MWK")) output = CurrencyMWK;
            if (inputStr == U("MXN")) output = CurrencyMXN;
            if (inputStr == U("MYR")) output = CurrencyMYR;
            if (inputStr == U("MZN")) output = CurrencyMZN;
            if (inputStr == U("NAD")) output = CurrencyNAD;
            if (inputStr == U("NGN")) output = CurrencyNGN;
            if (inputStr == U("NIO")) output = CurrencyNIO;
            if (inputStr == U("NOK")) output = CurrencyNOK;
            if (inputStr == U("NPR")) output = CurrencyNPR;
            if (inputStr == U("NZD")) output = CurrencyNZD;
            if (inputStr == U("OMR")) output = CurrencyOMR;
            if (inputStr == U("PAB")) output = CurrencyPAB;
            if (inputStr == U("PEN")) output = CurrencyPEN;
            if (inputStr == U("PGK")) output = CurrencyPGK;
            if (inputStr == U("PHP")) output = CurrencyPHP;
            if (inputStr == U("PKR")) output = CurrencyPKR;
            if (inputStr == U("PLN")) output = CurrencyPLN;
            if (inputStr == U("PYG")) output = CurrencyPYG;
            if (inputStr == U("QAR")) output = CurrencyQAR;
            if (inputStr == U("RON")) output = CurrencyRON;
            if (inputStr == U("RSD")) output = CurrencyRSD;
            if (inputStr == U("RUB")) output = CurrencyRUB;
            if (inputStr == U("RWF")) output = CurrencyRWF;
            if (inputStr == U("SAR")) output = CurrencySAR;
            if (inputStr == U("SBD")) output = CurrencySBD;
            if (inputStr == U("SCR")) output = CurrencySCR;
            if (inputStr == U("SDG")) output = CurrencySDG;
            if (inputStr == U("SEK")) output = CurrencySEK;
            if (inputStr == U("SGD")) output = CurrencySGD;
            if (inputStr == U("SHP")) output = CurrencySHP;
            if (inputStr == U("SLL")) output = CurrencySLL;
            if (inputStr == U("SOS")) output = CurrencySOS;
            if (inputStr == U("SPL")) output = CurrencySPL;
            if (inputStr == U("SRD")) output = CurrencySRD;
            if (inputStr == U("STD")) output = CurrencySTD;
            if (inputStr == U("SVC")) output = CurrencySVC;
            if (inputStr == U("SYP")) output = CurrencySYP;
            if (inputStr == U("SZL")) output = CurrencySZL;
            if (inputStr == U("THB")) output = CurrencyTHB;
            if (inputStr == U("TJS")) output = CurrencyTJS;
            if (inputStr == U("TMT")) output = CurrencyTMT;
            if (inputStr == U("TND")) output = CurrencyTND;
            if (inputStr == U("TOP")) output = CurrencyTOP;
            if (inputStr == U("TRY")) output = CurrencyTRY;
            if (inputStr == U("TTD")) output = CurrencyTTD;
            if (inputStr == U("TVD")) output = CurrencyTVD;
            if (inputStr == U("TWD")) output = CurrencyTWD;
            if (inputStr == U("TZS")) output = CurrencyTZS;
            if (inputStr == U("UAH")) output = CurrencyUAH;
            if (inputStr == U("UGX")) output = CurrencyUGX;
            if (inputStr == U("USD")) output = CurrencyUSD;
            if (inputStr == U("UYU")) output = CurrencyUYU;
            if (inputStr == U("UZS")) output = CurrencyUZS;
            if (inputStr == U("VEF")) output = CurrencyVEF;
            if (inputStr == U("VND")) output = CurrencyVND;
            if (inputStr == U("VUV")) output = CurrencyVUV;
            if (inputStr == U("WST")) output = CurrencyWST;
            if (inputStr == U("XAF")) output = CurrencyXAF;
            if (inputStr == U("XCD")) output = CurrencyXCD;
            if (inputStr == U("XDR")) output = CurrencyXDR;
            if (inputStr == U("XOF")) output = CurrencyXOF;
            if (inputStr == U("XPF")) output = CurrencyXPF;
            if (inputStr == U("YER")) output = CurrencyYER;
            if (inputStr == U("ZAR")) output = CurrencyZAR;
            if (inputStr == U("ZMW")) output = CurrencyZMW;
            if (inputStr == U("ZWD")) output = CurrencyZWD;
        }

        enum EmailVerificationStatus
        {
            EmailVerificationStatusUnverified,
            EmailVerificationStatusPending,
            EmailVerificationStatusConfirmed
        };

        inline void ToJsonEnum(const EmailVerificationStatus input, web::json::value& output)
        {
            if (input == EmailVerificationStatusUnverified) output = web::json::value(U("Unverified"));
            if (input == EmailVerificationStatusPending) output = web::json::value(U("Pending"));
            if (input == EmailVerificationStatusConfirmed) output = web::json::value(U("Confirmed"));
        }
        inline void FromJsonEnum(const web::json::value& input, EmailVerificationStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Unverified")) output = EmailVerificationStatusUnverified;
            if (inputStr == U("Pending")) output = EmailVerificationStatusPending;
            if (inputStr == U("Confirmed")) output = EmailVerificationStatusConfirmed;
        }

        enum EntityTypes
        {
            EntityTypestitle,
            EntityTypesmaster_player_account,
            EntityTypestitle_player_account,
            EntityTypescharacter,
            EntityTypesgroup
        };

        inline void ToJsonEnum(const EntityTypes input, web::json::value& output)
        {
            if (input == EntityTypestitle) output = web::json::value(U("title"));
            if (input == EntityTypesmaster_player_account) output = web::json::value(U("master_player_account"));
            if (input == EntityTypestitle_player_account) output = web::json::value(U("title_player_account"));
            if (input == EntityTypescharacter) output = web::json::value(U("character"));
            if (input == EntityTypesgroup) output = web::json::value(U("group"));
        }
        inline void FromJsonEnum(const web::json::value& input, EntityTypes& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("title")) output = EntityTypestitle;
            if (inputStr == U("master_player_account")) output = EntityTypesmaster_player_account;
            if (inputStr == U("title_player_account")) output = EntityTypestitle_player_account;
            if (inputStr == U("character")) output = EntityTypescharacter;
            if (inputStr == U("group")) output = EntityTypesgroup;
        }

        enum GameInstanceState
        {
            GameInstanceStateOpen,
            GameInstanceStateClosed
        };

        inline void ToJsonEnum(const GameInstanceState input, web::json::value& output)
        {
            if (input == GameInstanceStateOpen) output = web::json::value(U("Open"));
            if (input == GameInstanceStateClosed) output = web::json::value(U("Closed"));
        }
        inline void FromJsonEnum(const web::json::value& input, GameInstanceState& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Open")) output = GameInstanceStateOpen;
            if (inputStr == U("Closed")) output = GameInstanceStateClosed;
        }

        enum LoginIdentityProvider
        {
            LoginIdentityProviderUnknown,
            LoginIdentityProviderPlayFab,
            LoginIdentityProviderCustom,
            LoginIdentityProviderGameCenter,
            LoginIdentityProviderGooglePlay,
            LoginIdentityProviderSteam,
            LoginIdentityProviderXBoxLive,
            LoginIdentityProviderPSN,
            LoginIdentityProviderKongregate,
            LoginIdentityProviderFacebook,
            LoginIdentityProviderIOSDevice,
            LoginIdentityProviderAndroidDevice,
            LoginIdentityProviderTwitch,
            LoginIdentityProviderWindowsHello
        };

        inline void ToJsonEnum(const LoginIdentityProvider input, web::json::value& output)
        {
            if (input == LoginIdentityProviderUnknown) output = web::json::value(U("Unknown"));
            if (input == LoginIdentityProviderPlayFab) output = web::json::value(U("PlayFab"));
            if (input == LoginIdentityProviderCustom) output = web::json::value(U("Custom"));
            if (input == LoginIdentityProviderGameCenter) output = web::json::value(U("GameCenter"));
            if (input == LoginIdentityProviderGooglePlay) output = web::json::value(U("GooglePlay"));
            if (input == LoginIdentityProviderSteam) output = web::json::value(U("Steam"));
            if (input == LoginIdentityProviderXBoxLive) output = web::json::value(U("XBoxLive"));
            if (input == LoginIdentityProviderPSN) output = web::json::value(U("PSN"));
            if (input == LoginIdentityProviderKongregate) output = web::json::value(U("Kongregate"));
            if (input == LoginIdentityProviderFacebook) output = web::json::value(U("Facebook"));
            if (input == LoginIdentityProviderIOSDevice) output = web::json::value(U("IOSDevice"));
            if (input == LoginIdentityProviderAndroidDevice) output = web::json::value(U("AndroidDevice"));
            if (input == LoginIdentityProviderTwitch) output = web::json::value(U("Twitch"));
            if (input == LoginIdentityProviderWindowsHello) output = web::json::value(U("WindowsHello"));
        }
        inline void FromJsonEnum(const web::json::value& input, LoginIdentityProvider& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Unknown")) output = LoginIdentityProviderUnknown;
            if (inputStr == U("PlayFab")) output = LoginIdentityProviderPlayFab;
            if (inputStr == U("Custom")) output = LoginIdentityProviderCustom;
            if (inputStr == U("GameCenter")) output = LoginIdentityProviderGameCenter;
            if (inputStr == U("GooglePlay")) output = LoginIdentityProviderGooglePlay;
            if (inputStr == U("Steam")) output = LoginIdentityProviderSteam;
            if (inputStr == U("XBoxLive")) output = LoginIdentityProviderXBoxLive;
            if (inputStr == U("PSN")) output = LoginIdentityProviderPSN;
            if (inputStr == U("Kongregate")) output = LoginIdentityProviderKongregate;
            if (inputStr == U("Facebook")) output = LoginIdentityProviderFacebook;
            if (inputStr == U("IOSDevice")) output = LoginIdentityProviderIOSDevice;
            if (inputStr == U("AndroidDevice")) output = LoginIdentityProviderAndroidDevice;
            if (inputStr == U("Twitch")) output = LoginIdentityProviderTwitch;
            if (inputStr == U("WindowsHello")) output = LoginIdentityProviderWindowsHello;
        }

        enum MatchmakeStatus
        {
            MatchmakeStatusComplete,
            MatchmakeStatusWaiting,
            MatchmakeStatusGameNotFound,
            MatchmakeStatusNoAvailableSlots,
            MatchmakeStatusSessionClosed
        };

        inline void ToJsonEnum(const MatchmakeStatus input, web::json::value& output)
        {
            if (input == MatchmakeStatusComplete) output = web::json::value(U("Complete"));
            if (input == MatchmakeStatusWaiting) output = web::json::value(U("Waiting"));
            if (input == MatchmakeStatusGameNotFound) output = web::json::value(U("GameNotFound"));
            if (input == MatchmakeStatusNoAvailableSlots) output = web::json::value(U("NoAvailableSlots"));
            if (input == MatchmakeStatusSessionClosed) output = web::json::value(U("SessionClosed"));
        }
        inline void FromJsonEnum(const web::json::value& input, MatchmakeStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Complete")) output = MatchmakeStatusComplete;
            if (inputStr == U("Waiting")) output = MatchmakeStatusWaiting;
            if (inputStr == U("GameNotFound")) output = MatchmakeStatusGameNotFound;
            if (inputStr == U("NoAvailableSlots")) output = MatchmakeStatusNoAvailableSlots;
            if (inputStr == U("SessionClosed")) output = MatchmakeStatusSessionClosed;
        }

        enum PushNotificationPlatform
        {
            PushNotificationPlatformApplePushNotificationService,
            PushNotificationPlatformGoogleCloudMessaging
        };

        inline void ToJsonEnum(const PushNotificationPlatform input, web::json::value& output)
        {
            if (input == PushNotificationPlatformApplePushNotificationService) output = web::json::value(U("ApplePushNotificationService"));
            if (input == PushNotificationPlatformGoogleCloudMessaging) output = web::json::value(U("GoogleCloudMessaging"));
        }
        inline void FromJsonEnum(const web::json::value& input, PushNotificationPlatform& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("ApplePushNotificationService")) output = PushNotificationPlatformApplePushNotificationService;
            if (inputStr == U("GoogleCloudMessaging")) output = PushNotificationPlatformGoogleCloudMessaging;
        }

        enum Region
        {
            RegionUSCentral,
            RegionUSEast,
            RegionEUWest,
            RegionSingapore,
            RegionJapan,
            RegionBrazil,
            RegionAustralia
        };

        inline void ToJsonEnum(const Region input, web::json::value& output)
        {
            if (input == RegionUSCentral) output = web::json::value(U("USCentral"));
            if (input == RegionUSEast) output = web::json::value(U("USEast"));
            if (input == RegionEUWest) output = web::json::value(U("EUWest"));
            if (input == RegionSingapore) output = web::json::value(U("Singapore"));
            if (input == RegionJapan) output = web::json::value(U("Japan"));
            if (input == RegionBrazil) output = web::json::value(U("Brazil"));
            if (input == RegionAustralia) output = web::json::value(U("Australia"));
        }
        inline void FromJsonEnum(const web::json::value& input, Region& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("USCentral")) output = RegionUSCentral;
            if (inputStr == U("USEast")) output = RegionUSEast;
            if (inputStr == U("EUWest")) output = RegionEUWest;
            if (inputStr == U("Singapore")) output = RegionSingapore;
            if (inputStr == U("Japan")) output = RegionJapan;
            if (inputStr == U("Brazil")) output = RegionBrazil;
            if (inputStr == U("Australia")) output = RegionAustralia;
        }

        enum SourceType
        {
            SourceTypeAdmin,
            SourceTypeBackEnd,
            SourceTypeGameClient,
            SourceTypeGameServer,
            SourceTypePartner
        };

        inline void ToJsonEnum(const SourceType input, web::json::value& output)
        {
            if (input == SourceTypeAdmin) output = web::json::value(U("Admin"));
            if (input == SourceTypeBackEnd) output = web::json::value(U("BackEnd"));
            if (input == SourceTypeGameClient) output = web::json::value(U("GameClient"));
            if (input == SourceTypeGameServer) output = web::json::value(U("GameServer"));
            if (input == SourceTypePartner) output = web::json::value(U("Partner"));
        }
        inline void FromJsonEnum(const web::json::value& input, SourceType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Admin")) output = SourceTypeAdmin;
            if (inputStr == U("BackEnd")) output = SourceTypeBackEnd;
            if (inputStr == U("GameClient")) output = SourceTypeGameClient;
            if (inputStr == U("GameServer")) output = SourceTypeGameServer;
            if (inputStr == U("Partner")) output = SourceTypePartner;
        }

        enum SubscriptionProviderStatus
        {
            SubscriptionProviderStatusNoError,
            SubscriptionProviderStatusCancelled,
            SubscriptionProviderStatusUnknownError,
            SubscriptionProviderStatusBillingError,
            SubscriptionProviderStatusProductUnavailable,
            SubscriptionProviderStatusCustomerDidNotAcceptPriceChange,
            SubscriptionProviderStatusFreeTrial,
            SubscriptionProviderStatusPaymentPending
        };

        inline void ToJsonEnum(const SubscriptionProviderStatus input, web::json::value& output)
        {
            if (input == SubscriptionProviderStatusNoError) output = web::json::value(U("NoError"));
            if (input == SubscriptionProviderStatusCancelled) output = web::json::value(U("Cancelled"));
            if (input == SubscriptionProviderStatusUnknownError) output = web::json::value(U("UnknownError"));
            if (input == SubscriptionProviderStatusBillingError) output = web::json::value(U("BillingError"));
            if (input == SubscriptionProviderStatusProductUnavailable) output = web::json::value(U("ProductUnavailable"));
            if (input == SubscriptionProviderStatusCustomerDidNotAcceptPriceChange) output = web::json::value(U("CustomerDidNotAcceptPriceChange"));
            if (input == SubscriptionProviderStatusFreeTrial) output = web::json::value(U("FreeTrial"));
            if (input == SubscriptionProviderStatusPaymentPending) output = web::json::value(U("PaymentPending"));
        }
        inline void FromJsonEnum(const web::json::value& input, SubscriptionProviderStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("NoError")) output = SubscriptionProviderStatusNoError;
            if (inputStr == U("Cancelled")) output = SubscriptionProviderStatusCancelled;
            if (inputStr == U("UnknownError")) output = SubscriptionProviderStatusUnknownError;
            if (inputStr == U("BillingError")) output = SubscriptionProviderStatusBillingError;
            if (inputStr == U("ProductUnavailable")) output = SubscriptionProviderStatusProductUnavailable;
            if (inputStr == U("CustomerDidNotAcceptPriceChange")) output = SubscriptionProviderStatusCustomerDidNotAcceptPriceChange;
            if (inputStr == U("FreeTrial")) output = SubscriptionProviderStatusFreeTrial;
            if (inputStr == U("PaymentPending")) output = SubscriptionProviderStatusPaymentPending;
        }

        enum TitleActivationStatus
        {
            TitleActivationStatusNone,
            TitleActivationStatusActivatedTitleKey,
            TitleActivationStatusPendingSteam,
            TitleActivationStatusActivatedSteam,
            TitleActivationStatusRevokedSteam
        };

        inline void ToJsonEnum(const TitleActivationStatus input, web::json::value& output)
        {
            if (input == TitleActivationStatusNone) output = web::json::value(U("None"));
            if (input == TitleActivationStatusActivatedTitleKey) output = web::json::value(U("ActivatedTitleKey"));
            if (input == TitleActivationStatusPendingSteam) output = web::json::value(U("PendingSteam"));
            if (input == TitleActivationStatusActivatedSteam) output = web::json::value(U("ActivatedSteam"));
            if (input == TitleActivationStatusRevokedSteam) output = web::json::value(U("RevokedSteam"));
        }
        inline void FromJsonEnum(const web::json::value& input, TitleActivationStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("None")) output = TitleActivationStatusNone;
            if (inputStr == U("ActivatedTitleKey")) output = TitleActivationStatusActivatedTitleKey;
            if (inputStr == U("PendingSteam")) output = TitleActivationStatusPendingSteam;
            if (inputStr == U("ActivatedSteam")) output = TitleActivationStatusActivatedSteam;
            if (inputStr == U("RevokedSteam")) output = TitleActivationStatusRevokedSteam;
        }

        enum TradeStatus
        {
            TradeStatusInvalid,
            TradeStatusOpening,
            TradeStatusOpen,
            TradeStatusAccepting,
            TradeStatusAccepted,
            TradeStatusFilled,
            TradeStatusCancelled
        };

        inline void ToJsonEnum(const TradeStatus input, web::json::value& output)
        {
            if (input == TradeStatusInvalid) output = web::json::value(U("Invalid"));
            if (input == TradeStatusOpening) output = web::json::value(U("Opening"));
            if (input == TradeStatusOpen) output = web::json::value(U("Open"));
            if (input == TradeStatusAccepting) output = web::json::value(U("Accepting"));
            if (input == TradeStatusAccepted) output = web::json::value(U("Accepted"));
            if (input == TradeStatusFilled) output = web::json::value(U("Filled"));
            if (input == TradeStatusCancelled) output = web::json::value(U("Cancelled"));
        }
        inline void FromJsonEnum(const web::json::value& input, TradeStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Invalid")) output = TradeStatusInvalid;
            if (inputStr == U("Opening")) output = TradeStatusOpening;
            if (inputStr == U("Open")) output = TradeStatusOpen;
            if (inputStr == U("Accepting")) output = TradeStatusAccepting;
            if (inputStr == U("Accepted")) output = TradeStatusAccepted;
            if (inputStr == U("Filled")) output = TradeStatusFilled;
            if (inputStr == U("Cancelled")) output = TradeStatusCancelled;
        }

        enum TransactionStatus
        {
            TransactionStatusCreateCart,
            TransactionStatusInit,
            TransactionStatusApproved,
            TransactionStatusSucceeded,
            TransactionStatusFailedByProvider,
            TransactionStatusDisputePending,
            TransactionStatusRefundPending,
            TransactionStatusRefunded,
            TransactionStatusRefundFailed,
            TransactionStatusChargedBack,
            TransactionStatusFailedByUber,
            TransactionStatusFailedByPlayFab,
            TransactionStatusRevoked,
            TransactionStatusTradePending,
            TransactionStatusTraded,
            TransactionStatusUpgraded,
            TransactionStatusStackPending,
            TransactionStatusStacked,
            TransactionStatusOther,
            TransactionStatusFailed
        };

        inline void ToJsonEnum(const TransactionStatus input, web::json::value& output)
        {
            if (input == TransactionStatusCreateCart) output = web::json::value(U("CreateCart"));
            if (input == TransactionStatusInit) output = web::json::value(U("Init"));
            if (input == TransactionStatusApproved) output = web::json::value(U("Approved"));
            if (input == TransactionStatusSucceeded) output = web::json::value(U("Succeeded"));
            if (input == TransactionStatusFailedByProvider) output = web::json::value(U("FailedByProvider"));
            if (input == TransactionStatusDisputePending) output = web::json::value(U("DisputePending"));
            if (input == TransactionStatusRefundPending) output = web::json::value(U("RefundPending"));
            if (input == TransactionStatusRefunded) output = web::json::value(U("Refunded"));
            if (input == TransactionStatusRefundFailed) output = web::json::value(U("RefundFailed"));
            if (input == TransactionStatusChargedBack) output = web::json::value(U("ChargedBack"));
            if (input == TransactionStatusFailedByUber) output = web::json::value(U("FailedByUber"));
            if (input == TransactionStatusFailedByPlayFab) output = web::json::value(U("FailedByPlayFab"));
            if (input == TransactionStatusRevoked) output = web::json::value(U("Revoked"));
            if (input == TransactionStatusTradePending) output = web::json::value(U("TradePending"));
            if (input == TransactionStatusTraded) output = web::json::value(U("Traded"));
            if (input == TransactionStatusUpgraded) output = web::json::value(U("Upgraded"));
            if (input == TransactionStatusStackPending) output = web::json::value(U("StackPending"));
            if (input == TransactionStatusStacked) output = web::json::value(U("Stacked"));
            if (input == TransactionStatusOther) output = web::json::value(U("Other"));
            if (input == TransactionStatusFailed) output = web::json::value(U("Failed"));
        }
        inline void FromJsonEnum(const web::json::value& input, TransactionStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("CreateCart")) output = TransactionStatusCreateCart;
            if (inputStr == U("Init")) output = TransactionStatusInit;
            if (inputStr == U("Approved")) output = TransactionStatusApproved;
            if (inputStr == U("Succeeded")) output = TransactionStatusSucceeded;
            if (inputStr == U("FailedByProvider")) output = TransactionStatusFailedByProvider;
            if (inputStr == U("DisputePending")) output = TransactionStatusDisputePending;
            if (inputStr == U("RefundPending")) output = TransactionStatusRefundPending;
            if (inputStr == U("Refunded")) output = TransactionStatusRefunded;
            if (inputStr == U("RefundFailed")) output = TransactionStatusRefundFailed;
            if (inputStr == U("ChargedBack")) output = TransactionStatusChargedBack;
            if (inputStr == U("FailedByUber")) output = TransactionStatusFailedByUber;
            if (inputStr == U("FailedByPlayFab")) output = TransactionStatusFailedByPlayFab;
            if (inputStr == U("Revoked")) output = TransactionStatusRevoked;
            if (inputStr == U("TradePending")) output = TransactionStatusTradePending;
            if (inputStr == U("Traded")) output = TransactionStatusTraded;
            if (inputStr == U("Upgraded")) output = TransactionStatusUpgraded;
            if (inputStr == U("StackPending")) output = TransactionStatusStackPending;
            if (inputStr == U("Stacked")) output = TransactionStatusStacked;
            if (inputStr == U("Other")) output = TransactionStatusOther;
            if (inputStr == U("Failed")) output = TransactionStatusFailed;
        }

        enum UserDataPermission
        {
            UserDataPermissionPrivate,
            UserDataPermissionPublic
        };

        inline void ToJsonEnum(const UserDataPermission input, web::json::value& output)
        {
            if (input == UserDataPermissionPrivate) output = web::json::value(U("Private"));
            if (input == UserDataPermissionPublic) output = web::json::value(U("Public"));
        }
        inline void FromJsonEnum(const web::json::value& input, UserDataPermission& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Private")) output = UserDataPermissionPrivate;
            if (inputStr == U("Public")) output = UserDataPermissionPublic;
        }

        enum UserOrigination
        {
            UserOriginationOrganic,
            UserOriginationSteam,
            UserOriginationGoogle,
            UserOriginationAmazon,
            UserOriginationFacebook,
            UserOriginationKongregate,
            UserOriginationGamersFirst,
            UserOriginationUnknown,
            UserOriginationIOS,
            UserOriginationLoadTest,
            UserOriginationAndroid,
            UserOriginationPSN,
            UserOriginationGameCenter,
            UserOriginationCustomId,
            UserOriginationXboxLive,
            UserOriginationParse,
            UserOriginationTwitch,
            UserOriginationWindowsHello
        };

        inline void ToJsonEnum(const UserOrigination input, web::json::value& output)
        {
            if (input == UserOriginationOrganic) output = web::json::value(U("Organic"));
            if (input == UserOriginationSteam) output = web::json::value(U("Steam"));
            if (input == UserOriginationGoogle) output = web::json::value(U("Google"));
            if (input == UserOriginationAmazon) output = web::json::value(U("Amazon"));
            if (input == UserOriginationFacebook) output = web::json::value(U("Facebook"));
            if (input == UserOriginationKongregate) output = web::json::value(U("Kongregate"));
            if (input == UserOriginationGamersFirst) output = web::json::value(U("GamersFirst"));
            if (input == UserOriginationUnknown) output = web::json::value(U("Unknown"));
            if (input == UserOriginationIOS) output = web::json::value(U("IOS"));
            if (input == UserOriginationLoadTest) output = web::json::value(U("LoadTest"));
            if (input == UserOriginationAndroid) output = web::json::value(U("Android"));
            if (input == UserOriginationPSN) output = web::json::value(U("PSN"));
            if (input == UserOriginationGameCenter) output = web::json::value(U("GameCenter"));
            if (input == UserOriginationCustomId) output = web::json::value(U("CustomId"));
            if (input == UserOriginationXboxLive) output = web::json::value(U("XboxLive"));
            if (input == UserOriginationParse) output = web::json::value(U("Parse"));
            if (input == UserOriginationTwitch) output = web::json::value(U("Twitch"));
            if (input == UserOriginationWindowsHello) output = web::json::value(U("WindowsHello"));
        }
        inline void FromJsonEnum(const web::json::value& input, UserOrigination& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Organic")) output = UserOriginationOrganic;
            if (inputStr == U("Steam")) output = UserOriginationSteam;
            if (inputStr == U("Google")) output = UserOriginationGoogle;
            if (inputStr == U("Amazon")) output = UserOriginationAmazon;
            if (inputStr == U("Facebook")) output = UserOriginationFacebook;
            if (inputStr == U("Kongregate")) output = UserOriginationKongregate;
            if (inputStr == U("GamersFirst")) output = UserOriginationGamersFirst;
            if (inputStr == U("Unknown")) output = UserOriginationUnknown;
            if (inputStr == U("IOS")) output = UserOriginationIOS;
            if (inputStr == U("LoadTest")) output = UserOriginationLoadTest;
            if (inputStr == U("Android")) output = UserOriginationAndroid;
            if (inputStr == U("PSN")) output = UserOriginationPSN;
            if (inputStr == U("GameCenter")) output = UserOriginationGameCenter;
            if (inputStr == U("CustomId")) output = UserOriginationCustomId;
            if (inputStr == U("XboxLive")) output = UserOriginationXboxLive;
            if (inputStr == U("Parse")) output = UserOriginationParse;
            if (inputStr == U("Twitch")) output = UserOriginationTwitch;
            if (inputStr == U("WindowsHello")) output = UserOriginationWindowsHello;
        }

        // Client Classes
        struct AcceptTradeRequest : public PlayFabRequestCommon
        {
            std::list<std::string> AcceptedInventoryInstanceIds;
            std::string OfferingPlayerId;
            std::string TradeId;

            AcceptTradeRequest() :
                PlayFabRequestCommon(),
                AcceptedInventoryInstanceIds(),
                OfferingPlayerId(),
                TradeId()
            {}

            AcceptTradeRequest(const AcceptTradeRequest& src) :
                PlayFabRequestCommon(),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId)
            {}

            ~AcceptTradeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AcceptedInventoryInstanceIds")], AcceptedInventoryInstanceIds);
                FromJsonUtilS(input[U("OfferingPlayerId")], OfferingPlayerId);
                FromJsonUtilS(input[U("TradeId")], TradeId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AcceptedInventoryInstanceIds; ToJsonUtilS(AcceptedInventoryInstanceIds, each_AcceptedInventoryInstanceIds); output[U("AcceptedInventoryInstanceIds")] = each_AcceptedInventoryInstanceIds;
                web::json::value each_OfferingPlayerId; ToJsonUtilS(OfferingPlayerId, each_OfferingPlayerId); output[U("OfferingPlayerId")] = each_OfferingPlayerId;
                web::json::value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output[U("TradeId")] = each_TradeId;
                return output;
            }
        };

        struct TradeInfo : public PlayFabBaseModel
        {
            std::list<std::string> AcceptedInventoryInstanceIds;
            std::string AcceptedPlayerId;
            std::list<std::string> AllowedPlayerIds;
            Boxed<time_t> CancelledAt;
            Boxed<time_t> FilledAt;
            Boxed<time_t> InvalidatedAt;
            std::list<std::string> OfferedCatalogItemIds;
            std::list<std::string> OfferedInventoryInstanceIds;
            std::string OfferingPlayerId;
            Boxed<time_t> OpenedAt;
            std::list<std::string> RequestedCatalogItemIds;
            Boxed<TradeStatus> Status;
            std::string TradeId;

            TradeInfo() :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(),
                AcceptedPlayerId(),
                AllowedPlayerIds(),
                CancelledAt(),
                FilledAt(),
                InvalidatedAt(),
                OfferedCatalogItemIds(),
                OfferedInventoryInstanceIds(),
                OfferingPlayerId(),
                OpenedAt(),
                RequestedCatalogItemIds(),
                Status(),
                TradeId()
            {}

            TradeInfo(const TradeInfo& src) :
                PlayFabBaseModel(),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds),
                AcceptedPlayerId(src.AcceptedPlayerId),
                AllowedPlayerIds(src.AllowedPlayerIds),
                CancelledAt(src.CancelledAt),
                FilledAt(src.FilledAt),
                InvalidatedAt(src.InvalidatedAt),
                OfferedCatalogItemIds(src.OfferedCatalogItemIds),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                OfferingPlayerId(src.OfferingPlayerId),
                OpenedAt(src.OpenedAt),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds),
                Status(src.Status),
                TradeId(src.TradeId)
            {}

            ~TradeInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AcceptedInventoryInstanceIds")], AcceptedInventoryInstanceIds);
                FromJsonUtilS(input[U("AcceptedPlayerId")], AcceptedPlayerId);
                FromJsonUtilS(input[U("AllowedPlayerIds")], AllowedPlayerIds);
                FromJsonUtilT(input[U("CancelledAt")], CancelledAt);
                FromJsonUtilT(input[U("FilledAt")], FilledAt);
                FromJsonUtilT(input[U("InvalidatedAt")], InvalidatedAt);
                FromJsonUtilS(input[U("OfferedCatalogItemIds")], OfferedCatalogItemIds);
                FromJsonUtilS(input[U("OfferedInventoryInstanceIds")], OfferedInventoryInstanceIds);
                FromJsonUtilS(input[U("OfferingPlayerId")], OfferingPlayerId);
                FromJsonUtilT(input[U("OpenedAt")], OpenedAt);
                FromJsonUtilS(input[U("RequestedCatalogItemIds")], RequestedCatalogItemIds);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilS(input[U("TradeId")], TradeId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AcceptedInventoryInstanceIds; ToJsonUtilS(AcceptedInventoryInstanceIds, each_AcceptedInventoryInstanceIds); output[U("AcceptedInventoryInstanceIds")] = each_AcceptedInventoryInstanceIds;
                web::json::value each_AcceptedPlayerId; ToJsonUtilS(AcceptedPlayerId, each_AcceptedPlayerId); output[U("AcceptedPlayerId")] = each_AcceptedPlayerId;
                web::json::value each_AllowedPlayerIds; ToJsonUtilS(AllowedPlayerIds, each_AllowedPlayerIds); output[U("AllowedPlayerIds")] = each_AllowedPlayerIds;
                web::json::value each_CancelledAt; ToJsonUtilT(CancelledAt, each_CancelledAt); output[U("CancelledAt")] = each_CancelledAt;
                web::json::value each_FilledAt; ToJsonUtilT(FilledAt, each_FilledAt); output[U("FilledAt")] = each_FilledAt;
                web::json::value each_InvalidatedAt; ToJsonUtilT(InvalidatedAt, each_InvalidatedAt); output[U("InvalidatedAt")] = each_InvalidatedAt;
                web::json::value each_OfferedCatalogItemIds; ToJsonUtilS(OfferedCatalogItemIds, each_OfferedCatalogItemIds); output[U("OfferedCatalogItemIds")] = each_OfferedCatalogItemIds;
                web::json::value each_OfferedInventoryInstanceIds; ToJsonUtilS(OfferedInventoryInstanceIds, each_OfferedInventoryInstanceIds); output[U("OfferedInventoryInstanceIds")] = each_OfferedInventoryInstanceIds;
                web::json::value each_OfferingPlayerId; ToJsonUtilS(OfferingPlayerId, each_OfferingPlayerId); output[U("OfferingPlayerId")] = each_OfferingPlayerId;
                web::json::value each_OpenedAt; ToJsonUtilT(OpenedAt, each_OpenedAt); output[U("OpenedAt")] = each_OpenedAt;
                web::json::value each_RequestedCatalogItemIds; ToJsonUtilS(RequestedCatalogItemIds, each_RequestedCatalogItemIds); output[U("RequestedCatalogItemIds")] = each_RequestedCatalogItemIds;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
                web::json::value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output[U("TradeId")] = each_TradeId;
                return output;
            }
        };

        struct AcceptTradeResponse : public PlayFabResultCommon
        {
            Boxed<TradeInfo> Trade;

            AcceptTradeResponse() :
                PlayFabResultCommon(),
                Trade()
            {}

            AcceptTradeResponse(const AcceptTradeResponse& src) :
                PlayFabResultCommon(),
                Trade(src.Trade)
            {}

            ~AcceptTradeResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Trade")], Trade);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Trade; ToJsonUtilO(Trade, each_Trade); output[U("Trade")] = each_Trade;
                return output;
            }
        };

        struct AdCampaignAttributionModel : public PlayFabBaseModel
        {
            time_t AttributedAt;
            std::string CampaignId;
            std::string Platform;

            AdCampaignAttributionModel() :
                PlayFabBaseModel(),
                AttributedAt(),
                CampaignId(),
                Platform()
            {}

            AdCampaignAttributionModel(const AdCampaignAttributionModel& src) :
                PlayFabBaseModel(),
                AttributedAt(src.AttributedAt),
                CampaignId(src.CampaignId),
                Platform(src.Platform)
            {}

            ~AdCampaignAttributionModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("AttributedAt")], AttributedAt);
                FromJsonUtilS(input[U("CampaignId")], CampaignId);
                FromJsonUtilS(input[U("Platform")], Platform);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AttributedAt; ToJsonUtilT(AttributedAt, each_AttributedAt); output[U("AttributedAt")] = each_AttributedAt;
                web::json::value each_CampaignId; ToJsonUtilS(CampaignId, each_CampaignId); output[U("CampaignId")] = each_CampaignId;
                web::json::value each_Platform; ToJsonUtilS(Platform, each_Platform); output[U("Platform")] = each_Platform;
                return output;
            }
        };

        struct AddFriendRequest : public PlayFabRequestCommon
        {
            std::string FriendEmail;
            std::string FriendPlayFabId;
            std::string FriendTitleDisplayName;
            std::string FriendUsername;

            AddFriendRequest() :
                PlayFabRequestCommon(),
                FriendEmail(),
                FriendPlayFabId(),
                FriendTitleDisplayName(),
                FriendUsername()
            {}

            AddFriendRequest(const AddFriendRequest& src) :
                PlayFabRequestCommon(),
                FriendEmail(src.FriendEmail),
                FriendPlayFabId(src.FriendPlayFabId),
                FriendTitleDisplayName(src.FriendTitleDisplayName),
                FriendUsername(src.FriendUsername)
            {}

            ~AddFriendRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FriendEmail")], FriendEmail);
                FromJsonUtilS(input[U("FriendPlayFabId")], FriendPlayFabId);
                FromJsonUtilS(input[U("FriendTitleDisplayName")], FriendTitleDisplayName);
                FromJsonUtilS(input[U("FriendUsername")], FriendUsername);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendEmail; ToJsonUtilS(FriendEmail, each_FriendEmail); output[U("FriendEmail")] = each_FriendEmail;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[U("FriendPlayFabId")] = each_FriendPlayFabId;
                web::json::value each_FriendTitleDisplayName; ToJsonUtilS(FriendTitleDisplayName, each_FriendTitleDisplayName); output[U("FriendTitleDisplayName")] = each_FriendTitleDisplayName;
                web::json::value each_FriendUsername; ToJsonUtilS(FriendUsername, each_FriendUsername); output[U("FriendUsername")] = each_FriendUsername;
                return output;
            }
        };

        struct AddFriendResult : public PlayFabResultCommon
        {
            bool Created;

            AddFriendResult() :
                PlayFabResultCommon(),
                Created()
            {}

            AddFriendResult(const AddFriendResult& src) :
                PlayFabResultCommon(),
                Created(src.Created)
            {}

            ~AddFriendResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Created")], Created);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Created; ToJsonUtilP(Created, each_Created); output[U("Created")] = each_Created;
                return output;
            }
        };

        struct GenericServiceId : public PlayFabBaseModel
        {
            std::string ServiceName;
            std::string UserId;

            GenericServiceId() :
                PlayFabBaseModel(),
                ServiceName(),
                UserId()
            {}

            GenericServiceId(const GenericServiceId& src) :
                PlayFabBaseModel(),
                ServiceName(src.ServiceName),
                UserId(src.UserId)
            {}

            ~GenericServiceId() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ServiceName")], ServiceName);
                FromJsonUtilS(input[U("UserId")], UserId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ServiceName; ToJsonUtilS(ServiceName, each_ServiceName); output[U("ServiceName")] = each_ServiceName;
                web::json::value each_UserId; ToJsonUtilS(UserId, each_UserId); output[U("UserId")] = each_UserId;
                return output;
            }
        };

        struct AddGenericIDRequest : public PlayFabRequestCommon
        {
            GenericServiceId GenericId;

            AddGenericIDRequest() :
                PlayFabRequestCommon(),
                GenericId()
            {}

            AddGenericIDRequest(const AddGenericIDRequest& src) :
                PlayFabRequestCommon(),
                GenericId(src.GenericId)
            {}

            ~AddGenericIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("GenericId")], GenericId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GenericId; ToJsonUtilO(GenericId, each_GenericId); output[U("GenericId")] = each_GenericId;
                return output;
            }
        };

        struct AddGenericIDResult : public PlayFabResultCommon
        {

            AddGenericIDResult() :
                PlayFabResultCommon()
            {}

            AddGenericIDResult(const AddGenericIDResult& src) :
                PlayFabResultCommon()
            {}

            ~AddGenericIDResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct AddOrUpdateContactEmailRequest : public PlayFabRequestCommon
        {
            std::string EmailAddress;

            AddOrUpdateContactEmailRequest() :
                PlayFabRequestCommon(),
                EmailAddress()
            {}

            AddOrUpdateContactEmailRequest(const AddOrUpdateContactEmailRequest& src) :
                PlayFabRequestCommon(),
                EmailAddress(src.EmailAddress)
            {}

            ~AddOrUpdateContactEmailRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("EmailAddress")], EmailAddress);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EmailAddress; ToJsonUtilS(EmailAddress, each_EmailAddress); output[U("EmailAddress")] = each_EmailAddress;
                return output;
            }
        };

        struct AddOrUpdateContactEmailResult : public PlayFabResultCommon
        {

            AddOrUpdateContactEmailResult() :
                PlayFabResultCommon()
            {}

            AddOrUpdateContactEmailResult(const AddOrUpdateContactEmailResult& src) :
                PlayFabResultCommon()
            {}

            ~AddOrUpdateContactEmailResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct AddSharedGroupMembersRequest : public PlayFabRequestCommon
        {
            std::list<std::string> PlayFabIds;
            std::string SharedGroupId;

            AddSharedGroupMembersRequest() :
                PlayFabRequestCommon(),
                PlayFabIds(),
                SharedGroupId()
            {}

            AddSharedGroupMembersRequest(const AddSharedGroupMembersRequest& src) :
                PlayFabRequestCommon(),
                PlayFabIds(src.PlayFabIds),
                SharedGroupId(src.SharedGroupId)
            {}

            ~AddSharedGroupMembersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabIds")], PlayFabIds);
                FromJsonUtilS(input[U("SharedGroupId")], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabIds; ToJsonUtilS(PlayFabIds, each_PlayFabIds); output[U("PlayFabIds")] = each_PlayFabIds;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[U("SharedGroupId")] = each_SharedGroupId;
                return output;
            }
        };

        struct AddSharedGroupMembersResult : public PlayFabResultCommon
        {

            AddSharedGroupMembersResult() :
                PlayFabResultCommon()
            {}

            AddSharedGroupMembersResult(const AddSharedGroupMembersResult& src) :
                PlayFabResultCommon()
            {}

            ~AddSharedGroupMembersResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct AddUsernamePasswordRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string Password;
            std::string Username;

            AddUsernamePasswordRequest() :
                PlayFabRequestCommon(),
                Email(),
                Password(),
                Username()
            {}

            AddUsernamePasswordRequest(const AddUsernamePasswordRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                Password(src.Password),
                Username(src.Username)
            {}

            ~AddUsernamePasswordRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Email")], Email);
                FromJsonUtilS(input[U("Password")], Password);
                FromJsonUtilS(input[U("Username")], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[U("Email")] = each_Email;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[U("Password")] = each_Password;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                return output;
            }
        };

        struct AddUsernamePasswordResult : public PlayFabResultCommon
        {
            std::string Username;

            AddUsernamePasswordResult() :
                PlayFabResultCommon(),
                Username()
            {}

            AddUsernamePasswordResult(const AddUsernamePasswordResult& src) :
                PlayFabResultCommon(),
                Username(src.Username)
            {}

            ~AddUsernamePasswordResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Username")], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                return output;
            }
        };

        struct AddUserVirtualCurrencyRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string VirtualCurrency;

            AddUserVirtualCurrencyRequest() :
                PlayFabRequestCommon(),
                Amount(),
                VirtualCurrency()
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~AddUserVirtualCurrencyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Amount")], Amount);
                FromJsonUtilS(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[U("Amount")] = each_Amount;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct AndroidDevicePushNotificationRegistrationRequest : public PlayFabRequestCommon
        {
            std::string ConfirmationMessage;
            std::string DeviceToken;
            Boxed<bool> SendPushNotificationConfirmation;

            AndroidDevicePushNotificationRegistrationRequest() :
                PlayFabRequestCommon(),
                ConfirmationMessage(),
                DeviceToken(),
                SendPushNotificationConfirmation()
            {}

            AndroidDevicePushNotificationRegistrationRequest(const AndroidDevicePushNotificationRegistrationRequest& src) :
                PlayFabRequestCommon(),
                ConfirmationMessage(src.ConfirmationMessage),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation)
            {}

            ~AndroidDevicePushNotificationRegistrationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ConfirmationMessage")], ConfirmationMessage);
                FromJsonUtilS(input[U("DeviceToken")], DeviceToken);
                FromJsonUtilP(input[U("SendPushNotificationConfirmation")], SendPushNotificationConfirmation);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ConfirmationMessage; ToJsonUtilS(ConfirmationMessage, each_ConfirmationMessage); output[U("ConfirmationMessage")] = each_ConfirmationMessage;
                web::json::value each_DeviceToken; ToJsonUtilS(DeviceToken, each_DeviceToken); output[U("DeviceToken")] = each_DeviceToken;
                web::json::value each_SendPushNotificationConfirmation; ToJsonUtilP(SendPushNotificationConfirmation, each_SendPushNotificationConfirmation); output[U("SendPushNotificationConfirmation")] = each_SendPushNotificationConfirmation;
                return output;
            }
        };

        struct AndroidDevicePushNotificationRegistrationResult : public PlayFabResultCommon
        {

            AndroidDevicePushNotificationRegistrationResult() :
                PlayFabResultCommon()
            {}

            AndroidDevicePushNotificationRegistrationResult(const AndroidDevicePushNotificationRegistrationResult& src) :
                PlayFabResultCommon()
            {}

            ~AndroidDevicePushNotificationRegistrationResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct AttributeInstallRequest : public PlayFabRequestCommon
        {
            std::string Adid;
            std::string Idfa;

            AttributeInstallRequest() :
                PlayFabRequestCommon(),
                Adid(),
                Idfa()
            {}

            AttributeInstallRequest(const AttributeInstallRequest& src) :
                PlayFabRequestCommon(),
                Adid(src.Adid),
                Idfa(src.Idfa)
            {}

            ~AttributeInstallRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Adid")], Adid);
                FromJsonUtilS(input[U("Idfa")], Idfa);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Adid; ToJsonUtilS(Adid, each_Adid); output[U("Adid")] = each_Adid;
                web::json::value each_Idfa; ToJsonUtilS(Idfa, each_Idfa); output[U("Idfa")] = each_Idfa;
                return output;
            }
        };

        struct AttributeInstallResult : public PlayFabResultCommon
        {

            AttributeInstallResult() :
                PlayFabResultCommon()
            {}

            AttributeInstallResult(const AttributeInstallResult& src) :
                PlayFabResultCommon()
            {}

            ~AttributeInstallResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct CancelTradeRequest : public PlayFabRequestCommon
        {
            std::string TradeId;

            CancelTradeRequest() :
                PlayFabRequestCommon(),
                TradeId()
            {}

            CancelTradeRequest(const CancelTradeRequest& src) :
                PlayFabRequestCommon(),
                TradeId(src.TradeId)
            {}

            ~CancelTradeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("TradeId")], TradeId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output[U("TradeId")] = each_TradeId;
                return output;
            }
        };

        struct CancelTradeResponse : public PlayFabResultCommon
        {
            Boxed<TradeInfo> Trade;

            CancelTradeResponse() :
                PlayFabResultCommon(),
                Trade()
            {}

            CancelTradeResponse(const CancelTradeResponse& src) :
                PlayFabResultCommon(),
                Trade(src.Trade)
            {}

            ~CancelTradeResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Trade")], Trade);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Trade; ToJsonUtilO(Trade, each_Trade); output[U("Trade")] = each_Trade;
                return output;
            }
        };

        struct CartItem : public PlayFabBaseModel
        {
            std::string Description;
            std::string DisplayName;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::map<std::string, Uint32> VCAmount;
            std::map<std::string, Uint32> VirtualCurrencyPrices;

            CartItem() :
                PlayFabBaseModel(),
                Description(),
                DisplayName(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                RealCurrencyPrices(),
                VCAmount(),
                VirtualCurrencyPrices()
            {}

            CartItem(const CartItem& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                DisplayName(src.DisplayName),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                RealCurrencyPrices(src.RealCurrencyPrices),
                VCAmount(src.VCAmount),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            ~CartItem() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Description")], Description);
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilS(input[U("ItemClass")], ItemClass);
                FromJsonUtilS(input[U("ItemId")], ItemId);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilP(input[U("RealCurrencyPrices")], RealCurrencyPrices);
                FromJsonUtilP(input[U("VCAmount")], VCAmount);
                FromJsonUtilP(input[U("VirtualCurrencyPrices")], VirtualCurrencyPrices);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[U("Description")] = each_Description;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output[U("ItemClass")] = each_ItemClass;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_RealCurrencyPrices; ToJsonUtilP(RealCurrencyPrices, each_RealCurrencyPrices); output[U("RealCurrencyPrices")] = each_RealCurrencyPrices;
                web::json::value each_VCAmount; ToJsonUtilP(VCAmount, each_VCAmount); output[U("VCAmount")] = each_VCAmount;
                web::json::value each_VirtualCurrencyPrices; ToJsonUtilP(VirtualCurrencyPrices, each_VirtualCurrencyPrices); output[U("VirtualCurrencyPrices")] = each_VirtualCurrencyPrices;
                return output;
            }
        };

        struct CatalogItemBundleInfo : public PlayFabBaseModel
        {
            std::list<std::string> BundledItems;
            std::list<std::string> BundledResultTables;
            std::map<std::string, Uint32> BundledVirtualCurrencies;

            CatalogItemBundleInfo() :
                PlayFabBaseModel(),
                BundledItems(),
                BundledResultTables(),
                BundledVirtualCurrencies()
            {}

            CatalogItemBundleInfo(const CatalogItemBundleInfo& src) :
                PlayFabBaseModel(),
                BundledItems(src.BundledItems),
                BundledResultTables(src.BundledResultTables),
                BundledVirtualCurrencies(src.BundledVirtualCurrencies)
            {}

            ~CatalogItemBundleInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BundledItems")], BundledItems);
                FromJsonUtilS(input[U("BundledResultTables")], BundledResultTables);
                FromJsonUtilP(input[U("BundledVirtualCurrencies")], BundledVirtualCurrencies);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BundledItems; ToJsonUtilS(BundledItems, each_BundledItems); output[U("BundledItems")] = each_BundledItems;
                web::json::value each_BundledResultTables; ToJsonUtilS(BundledResultTables, each_BundledResultTables); output[U("BundledResultTables")] = each_BundledResultTables;
                web::json::value each_BundledVirtualCurrencies; ToJsonUtilP(BundledVirtualCurrencies, each_BundledVirtualCurrencies); output[U("BundledVirtualCurrencies")] = each_BundledVirtualCurrencies;
                return output;
            }
        };

        struct CatalogItemConsumableInfo : public PlayFabBaseModel
        {
            Boxed<Uint32> UsageCount;
            Boxed<Uint32> UsagePeriod;
            std::string UsagePeriodGroup;

            CatalogItemConsumableInfo() :
                PlayFabBaseModel(),
                UsageCount(),
                UsagePeriod(),
                UsagePeriodGroup()
            {}

            CatalogItemConsumableInfo(const CatalogItemConsumableInfo& src) :
                PlayFabBaseModel(),
                UsageCount(src.UsageCount),
                UsagePeriod(src.UsagePeriod),
                UsagePeriodGroup(src.UsagePeriodGroup)
            {}

            ~CatalogItemConsumableInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("UsageCount")], UsageCount);
                FromJsonUtilP(input[U("UsagePeriod")], UsagePeriod);
                FromJsonUtilS(input[U("UsagePeriodGroup")], UsagePeriodGroup);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_UsageCount; ToJsonUtilP(UsageCount, each_UsageCount); output[U("UsageCount")] = each_UsageCount;
                web::json::value each_UsagePeriod; ToJsonUtilP(UsagePeriod, each_UsagePeriod); output[U("UsagePeriod")] = each_UsagePeriod;
                web::json::value each_UsagePeriodGroup; ToJsonUtilS(UsagePeriodGroup, each_UsagePeriodGroup); output[U("UsagePeriodGroup")] = each_UsagePeriodGroup;
                return output;
            }
        };

        struct CatalogItemContainerInfo : public PlayFabBaseModel
        {
            std::list<std::string> ItemContents;
            std::string KeyItemId;
            std::list<std::string> ResultTableContents;
            std::map<std::string, Uint32> VirtualCurrencyContents;

            CatalogItemContainerInfo() :
                PlayFabBaseModel(),
                ItemContents(),
                KeyItemId(),
                ResultTableContents(),
                VirtualCurrencyContents()
            {}

            CatalogItemContainerInfo(const CatalogItemContainerInfo& src) :
                PlayFabBaseModel(),
                ItemContents(src.ItemContents),
                KeyItemId(src.KeyItemId),
                ResultTableContents(src.ResultTableContents),
                VirtualCurrencyContents(src.VirtualCurrencyContents)
            {}

            ~CatalogItemContainerInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ItemContents")], ItemContents);
                FromJsonUtilS(input[U("KeyItemId")], KeyItemId);
                FromJsonUtilS(input[U("ResultTableContents")], ResultTableContents);
                FromJsonUtilP(input[U("VirtualCurrencyContents")], VirtualCurrencyContents);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ItemContents; ToJsonUtilS(ItemContents, each_ItemContents); output[U("ItemContents")] = each_ItemContents;
                web::json::value each_KeyItemId; ToJsonUtilS(KeyItemId, each_KeyItemId); output[U("KeyItemId")] = each_KeyItemId;
                web::json::value each_ResultTableContents; ToJsonUtilS(ResultTableContents, each_ResultTableContents); output[U("ResultTableContents")] = each_ResultTableContents;
                web::json::value each_VirtualCurrencyContents; ToJsonUtilP(VirtualCurrencyContents, each_VirtualCurrencyContents); output[U("VirtualCurrencyContents")] = each_VirtualCurrencyContents;
                return output;
            }
        };

        struct CatalogItem : public PlayFabBaseModel
        {
            Boxed<CatalogItemBundleInfo> Bundle;
            bool CanBecomeCharacter;
            std::string CatalogVersion;
            Boxed<CatalogItemConsumableInfo> Consumable;
            Boxed<CatalogItemContainerInfo> Container;
            std::string CustomData;
            std::string Description;
            std::string DisplayName;
            Int32 InitialLimitedEditionCount;
            bool IsLimitedEdition;
            bool IsStackable;
            bool IsTradable;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemImageUrl;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::list<std::string> Tags;
            std::map<std::string, Uint32> VirtualCurrencyPrices;

            CatalogItem() :
                PlayFabBaseModel(),
                Bundle(),
                CanBecomeCharacter(),
                CatalogVersion(),
                Consumable(),
                Container(),
                CustomData(),
                Description(),
                DisplayName(),
                InitialLimitedEditionCount(),
                IsLimitedEdition(),
                IsStackable(),
                IsTradable(),
                ItemClass(),
                ItemId(),
                ItemImageUrl(),
                RealCurrencyPrices(),
                Tags(),
                VirtualCurrencyPrices()
            {}

            CatalogItem(const CatalogItem& src) :
                PlayFabBaseModel(),
                Bundle(src.Bundle),
                CanBecomeCharacter(src.CanBecomeCharacter),
                CatalogVersion(src.CatalogVersion),
                Consumable(src.Consumable),
                Container(src.Container),
                CustomData(src.CustomData),
                Description(src.Description),
                DisplayName(src.DisplayName),
                InitialLimitedEditionCount(src.InitialLimitedEditionCount),
                IsLimitedEdition(src.IsLimitedEdition),
                IsStackable(src.IsStackable),
                IsTradable(src.IsTradable),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemImageUrl(src.ItemImageUrl),
                RealCurrencyPrices(src.RealCurrencyPrices),
                Tags(src.Tags),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            ~CatalogItem() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Bundle")], Bundle);
                FromJsonUtilP(input[U("CanBecomeCharacter")], CanBecomeCharacter);
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilO(input[U("Consumable")], Consumable);
                FromJsonUtilO(input[U("Container")], Container);
                FromJsonUtilS(input[U("CustomData")], CustomData);
                FromJsonUtilS(input[U("Description")], Description);
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilP(input[U("InitialLimitedEditionCount")], InitialLimitedEditionCount);
                FromJsonUtilP(input[U("IsLimitedEdition")], IsLimitedEdition);
                FromJsonUtilP(input[U("IsStackable")], IsStackable);
                FromJsonUtilP(input[U("IsTradable")], IsTradable);
                FromJsonUtilS(input[U("ItemClass")], ItemClass);
                FromJsonUtilS(input[U("ItemId")], ItemId);
                FromJsonUtilS(input[U("ItemImageUrl")], ItemImageUrl);
                FromJsonUtilP(input[U("RealCurrencyPrices")], RealCurrencyPrices);
                FromJsonUtilS(input[U("Tags")], Tags);
                FromJsonUtilP(input[U("VirtualCurrencyPrices")], VirtualCurrencyPrices);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Bundle; ToJsonUtilO(Bundle, each_Bundle); output[U("Bundle")] = each_Bundle;
                web::json::value each_CanBecomeCharacter; ToJsonUtilP(CanBecomeCharacter, each_CanBecomeCharacter); output[U("CanBecomeCharacter")] = each_CanBecomeCharacter;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_Consumable; ToJsonUtilO(Consumable, each_Consumable); output[U("Consumable")] = each_Consumable;
                web::json::value each_Container; ToJsonUtilO(Container, each_Container); output[U("Container")] = each_Container;
                web::json::value each_CustomData; ToJsonUtilS(CustomData, each_CustomData); output[U("CustomData")] = each_CustomData;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[U("Description")] = each_Description;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_InitialLimitedEditionCount; ToJsonUtilP(InitialLimitedEditionCount, each_InitialLimitedEditionCount); output[U("InitialLimitedEditionCount")] = each_InitialLimitedEditionCount;
                web::json::value each_IsLimitedEdition; ToJsonUtilP(IsLimitedEdition, each_IsLimitedEdition); output[U("IsLimitedEdition")] = each_IsLimitedEdition;
                web::json::value each_IsStackable; ToJsonUtilP(IsStackable, each_IsStackable); output[U("IsStackable")] = each_IsStackable;
                web::json::value each_IsTradable; ToJsonUtilP(IsTradable, each_IsTradable); output[U("IsTradable")] = each_IsTradable;
                web::json::value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output[U("ItemClass")] = each_ItemClass;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                web::json::value each_ItemImageUrl; ToJsonUtilS(ItemImageUrl, each_ItemImageUrl); output[U("ItemImageUrl")] = each_ItemImageUrl;
                web::json::value each_RealCurrencyPrices; ToJsonUtilP(RealCurrencyPrices, each_RealCurrencyPrices); output[U("RealCurrencyPrices")] = each_RealCurrencyPrices;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[U("Tags")] = each_Tags;
                web::json::value each_VirtualCurrencyPrices; ToJsonUtilP(VirtualCurrencyPrices, each_VirtualCurrencyPrices); output[U("VirtualCurrencyPrices")] = each_VirtualCurrencyPrices;
                return output;
            }
        };

        struct ItemInstance : public PlayFabBaseModel
        {
            std::string Annotation;
            std::list<std::string> BundleContents;
            std::string BundleParent;
            std::string CatalogVersion;
            std::map<std::string, std::string> CustomData;
            std::string DisplayName;
            Boxed<time_t> Expiration;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            Boxed<time_t> PurchaseDate;
            Boxed<Int32> RemainingUses;
            std::string UnitCurrency;
            Uint32 UnitPrice;
            Boxed<Int32> UsesIncrementedBy;

            ItemInstance() :
                PlayFabBaseModel(),
                Annotation(),
                BundleContents(),
                BundleParent(),
                CatalogVersion(),
                CustomData(),
                DisplayName(),
                Expiration(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                PurchaseDate(),
                RemainingUses(),
                UnitCurrency(),
                UnitPrice(),
                UsesIncrementedBy()
            {}

            ItemInstance(const ItemInstance& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                BundleContents(src.BundleContents),
                BundleParent(src.BundleParent),
                CatalogVersion(src.CatalogVersion),
                CustomData(src.CustomData),
                DisplayName(src.DisplayName),
                Expiration(src.Expiration),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                PurchaseDate(src.PurchaseDate),
                RemainingUses(src.RemainingUses),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                UsesIncrementedBy(src.UsesIncrementedBy)
            {}

            ~ItemInstance() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Annotation")], Annotation);
                FromJsonUtilS(input[U("BundleContents")], BundleContents);
                FromJsonUtilS(input[U("BundleParent")], BundleParent);
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CustomData")], CustomData);
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilT(input[U("Expiration")], Expiration);
                FromJsonUtilS(input[U("ItemClass")], ItemClass);
                FromJsonUtilS(input[U("ItemId")], ItemId);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilT(input[U("PurchaseDate")], PurchaseDate);
                FromJsonUtilP(input[U("RemainingUses")], RemainingUses);
                FromJsonUtilS(input[U("UnitCurrency")], UnitCurrency);
                FromJsonUtilP(input[U("UnitPrice")], UnitPrice);
                FromJsonUtilP(input[U("UsesIncrementedBy")], UsesIncrementedBy);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output[U("Annotation")] = each_Annotation;
                web::json::value each_BundleContents; ToJsonUtilS(BundleContents, each_BundleContents); output[U("BundleContents")] = each_BundleContents;
                web::json::value each_BundleParent; ToJsonUtilS(BundleParent, each_BundleParent); output[U("BundleParent")] = each_BundleParent;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CustomData; ToJsonUtilS(CustomData, each_CustomData); output[U("CustomData")] = each_CustomData;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_Expiration; ToJsonUtilT(Expiration, each_Expiration); output[U("Expiration")] = each_Expiration;
                web::json::value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output[U("ItemClass")] = each_ItemClass;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output[U("PurchaseDate")] = each_PurchaseDate;
                web::json::value each_RemainingUses; ToJsonUtilP(RemainingUses, each_RemainingUses); output[U("RemainingUses")] = each_RemainingUses;
                web::json::value each_UnitCurrency; ToJsonUtilS(UnitCurrency, each_UnitCurrency); output[U("UnitCurrency")] = each_UnitCurrency;
                web::json::value each_UnitPrice; ToJsonUtilP(UnitPrice, each_UnitPrice); output[U("UnitPrice")] = each_UnitPrice;
                web::json::value each_UsesIncrementedBy; ToJsonUtilP(UsesIncrementedBy, each_UsesIncrementedBy); output[U("UsesIncrementedBy")] = each_UsesIncrementedBy;
                return output;
            }
        };

        struct CharacterInventory : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::list<ItemInstance> Inventory;

            CharacterInventory() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory()
            {}

            CharacterInventory(const CharacterInventory& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory)
            {}

            ~CharacterInventory() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilO(input[U("Inventory")], Inventory);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[U("Inventory")] = each_Inventory;
                return output;
            }
        };

        struct CharacterLeaderboardEntry : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string CharacterName;
            std::string CharacterType;
            std::string DisplayName;
            std::string PlayFabId;
            Int32 Position;
            Int32 StatValue;

            CharacterLeaderboardEntry() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterName(),
                CharacterType(),
                DisplayName(),
                PlayFabId(),
                Position(),
                StatValue()
            {}

            CharacterLeaderboardEntry(const CharacterLeaderboardEntry& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId),
                Position(src.Position),
                StatValue(src.StatValue)
            {}

            ~CharacterLeaderboardEntry() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("CharacterName")], CharacterName);
                FromJsonUtilS(input[U("CharacterType")], CharacterType);
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilP(input[U("Position")], Position);
                FromJsonUtilP(input[U("StatValue")], StatValue);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CharacterName; ToJsonUtilS(CharacterName, each_CharacterName); output[U("CharacterName")] = each_CharacterName;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[U("CharacterType")] = each_CharacterType;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Position; ToJsonUtilP(Position, each_Position); output[U("Position")] = each_Position;
                web::json::value each_StatValue; ToJsonUtilP(StatValue, each_StatValue); output[U("StatValue")] = each_StatValue;
                return output;
            }
        };

        struct CharacterResult : public PlayFabResultCommon
        {
            std::string CharacterId;
            std::string CharacterName;
            std::string CharacterType;

            CharacterResult() :
                PlayFabResultCommon(),
                CharacterId(),
                CharacterName(),
                CharacterType()
            {}

            CharacterResult(const CharacterResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType)
            {}

            ~CharacterResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("CharacterName")], CharacterName);
                FromJsonUtilS(input[U("CharacterType")], CharacterType);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CharacterName; ToJsonUtilS(CharacterName, each_CharacterName); output[U("CharacterName")] = each_CharacterName;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[U("CharacterType")] = each_CharacterType;
                return output;
            }
        };

        struct Container_Dictionary_String_String : public PlayFabBaseModel
        {
            std::map<std::string, std::string> Data;

            Container_Dictionary_String_String() :
                PlayFabBaseModel(),
                Data()
            {}

            Container_Dictionary_String_String(const Container_Dictionary_String_String& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            ~Container_Dictionary_String_String() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Data")], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                return output;
            }
        };

        struct CollectionFilter : public PlayFabBaseModel
        {
            std::list<Container_Dictionary_String_String> Excludes;
            std::list<Container_Dictionary_String_String> Includes;

            CollectionFilter() :
                PlayFabBaseModel(),
                Excludes(),
                Includes()
            {}

            CollectionFilter(const CollectionFilter& src) :
                PlayFabBaseModel(),
                Excludes(src.Excludes),
                Includes(src.Includes)
            {}

            ~CollectionFilter() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Excludes")], Excludes);
                FromJsonUtilO(input[U("Includes")], Includes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Excludes; ToJsonUtilO(Excludes, each_Excludes); output[U("Excludes")] = each_Excludes;
                web::json::value each_Includes; ToJsonUtilO(Includes, each_Includes); output[U("Includes")] = each_Includes;
                return output;
            }
        };

        struct ConfirmPurchaseRequest : public PlayFabRequestCommon
        {
            std::string OrderId;

            ConfirmPurchaseRequest() :
                PlayFabRequestCommon(),
                OrderId()
            {}

            ConfirmPurchaseRequest(const ConfirmPurchaseRequest& src) :
                PlayFabRequestCommon(),
                OrderId(src.OrderId)
            {}

            ~ConfirmPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("OrderId")], OrderId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[U("OrderId")] = each_OrderId;
                return output;
            }
        };

        struct ConfirmPurchaseResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> Items;
            std::string OrderId;
            time_t PurchaseDate;

            ConfirmPurchaseResult() :
                PlayFabResultCommon(),
                Items(),
                OrderId(),
                PurchaseDate()
            {}

            ConfirmPurchaseResult(const ConfirmPurchaseResult& src) :
                PlayFabResultCommon(),
                Items(src.Items),
                OrderId(src.OrderId),
                PurchaseDate(src.PurchaseDate)
            {}

            ~ConfirmPurchaseResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Items")], Items);
                FromJsonUtilS(input[U("OrderId")], OrderId);
                FromJsonUtilT(input[U("PurchaseDate")], PurchaseDate);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Items; ToJsonUtilO(Items, each_Items); output[U("Items")] = each_Items;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[U("OrderId")] = each_OrderId;
                web::json::value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output[U("PurchaseDate")] = each_PurchaseDate;
                return output;
            }
        };

        struct ConsumeItemRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            Int32 ConsumeCount;
            std::string ItemInstanceId;

            ConsumeItemRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                ConsumeCount(),
                ItemInstanceId()
            {}

            ConsumeItemRequest(const ConsumeItemRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                ConsumeCount(src.ConsumeCount),
                ItemInstanceId(src.ItemInstanceId)
            {}

            ~ConsumeItemRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilP(input[U("ConsumeCount")], ConsumeCount);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ConsumeCount; ToJsonUtilP(ConsumeCount, each_ConsumeCount); output[U("ConsumeCount")] = each_ConsumeCount;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                return output;
            }
        };

        struct ConsumeItemResult : public PlayFabResultCommon
        {
            std::string ItemInstanceId;
            Int32 RemainingUses;

            ConsumeItemResult() :
                PlayFabResultCommon(),
                ItemInstanceId(),
                RemainingUses()
            {}

            ConsumeItemResult(const ConsumeItemResult& src) :
                PlayFabResultCommon(),
                ItemInstanceId(src.ItemInstanceId),
                RemainingUses(src.RemainingUses)
            {}

            ~ConsumeItemResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilP(input[U("RemainingUses")], RemainingUses);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_RemainingUses; ToJsonUtilP(RemainingUses, each_RemainingUses); output[U("RemainingUses")] = each_RemainingUses;
                return output;
            }
        };

        struct ContactEmailInfoModel : public PlayFabBaseModel
        {
            std::string EmailAddress;
            std::string Name;
            Boxed<EmailVerificationStatus> VerificationStatus;

            ContactEmailInfoModel() :
                PlayFabBaseModel(),
                EmailAddress(),
                Name(),
                VerificationStatus()
            {}

            ContactEmailInfoModel(const ContactEmailInfoModel& src) :
                PlayFabBaseModel(),
                EmailAddress(src.EmailAddress),
                Name(src.Name),
                VerificationStatus(src.VerificationStatus)
            {}

            ~ContactEmailInfoModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("EmailAddress")], EmailAddress);
                FromJsonUtilS(input[U("Name")], Name);
                FromJsonUtilE(input[U("VerificationStatus")], VerificationStatus);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EmailAddress; ToJsonUtilS(EmailAddress, each_EmailAddress); output[U("EmailAddress")] = each_EmailAddress;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                web::json::value each_VerificationStatus; ToJsonUtilE(VerificationStatus, each_VerificationStatus); output[U("VerificationStatus")] = each_VerificationStatus;
                return output;
            }
        };

        struct CreateSharedGroupRequest : public PlayFabRequestCommon
        {
            std::string SharedGroupId;

            CreateSharedGroupRequest() :
                PlayFabRequestCommon(),
                SharedGroupId()
            {}

            CreateSharedGroupRequest(const CreateSharedGroupRequest& src) :
                PlayFabRequestCommon(),
                SharedGroupId(src.SharedGroupId)
            {}

            ~CreateSharedGroupRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("SharedGroupId")], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[U("SharedGroupId")] = each_SharedGroupId;
                return output;
            }
        };

        struct CreateSharedGroupResult : public PlayFabResultCommon
        {
            std::string SharedGroupId;

            CreateSharedGroupResult() :
                PlayFabResultCommon(),
                SharedGroupId()
            {}

            CreateSharedGroupResult(const CreateSharedGroupResult& src) :
                PlayFabResultCommon(),
                SharedGroupId(src.SharedGroupId)
            {}

            ~CreateSharedGroupResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("SharedGroupId")], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[U("SharedGroupId")] = each_SharedGroupId;
                return output;
            }
        };

        struct CurrentGamesRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;
            std::string GameMode;
            Boxed<Region> pfRegion;
            std::string StatisticName;
            Boxed<CollectionFilter> TagFilter;

            CurrentGamesRequest() :
                PlayFabRequestCommon(),
                BuildVersion(),
                GameMode(),
                pfRegion(),
                StatisticName(),
                TagFilter()
            {}

            CurrentGamesRequest(const CurrentGamesRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion),
                StatisticName(src.StatisticName),
                TagFilter(src.TagFilter)
            {}

            ~CurrentGamesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildVersion")], BuildVersion);
                FromJsonUtilS(input[U("GameMode")], GameMode);
                FromJsonUtilE(input[U("pfRegion")], pfRegion);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilO(input[U("TagFilter")], TagFilter);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[U("BuildVersion")] = each_BuildVersion;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[U("GameMode")] = each_GameMode;
                web::json::value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output[U("Region")] = each_pfRegion;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_TagFilter; ToJsonUtilO(TagFilter, each_TagFilter); output[U("TagFilter")] = each_TagFilter;
                return output;
            }
        };

        struct GameInfo : public PlayFabBaseModel
        {
            std::string BuildVersion;
            std::string GameMode;
            std::string GameServerData;
            Boxed<GameInstanceState> GameServerStateEnum;
            Boxed<time_t> LastHeartbeat;
            std::string LobbyID;
            Boxed<Int32> MaxPlayers;
            std::list<std::string> PlayerUserIds;
            Boxed<Region> pfRegion;
            Uint32 RunTime;
            std::string ServerHostname;
            std::string ServerIPV6Address;
            Boxed<Int32> ServerPort;
            std::string StatisticName;
            std::map<std::string, std::string> Tags;

            GameInfo() :
                PlayFabBaseModel(),
                BuildVersion(),
                GameMode(),
                GameServerData(),
                GameServerStateEnum(),
                LastHeartbeat(),
                LobbyID(),
                MaxPlayers(),
                PlayerUserIds(),
                pfRegion(),
                RunTime(),
                ServerHostname(),
                ServerIPV6Address(),
                ServerPort(),
                StatisticName(),
                Tags()
            {}

            GameInfo(const GameInfo& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                GameServerData(src.GameServerData),
                GameServerStateEnum(src.GameServerStateEnum),
                LastHeartbeat(src.LastHeartbeat),
                LobbyID(src.LobbyID),
                MaxPlayers(src.MaxPlayers),
                PlayerUserIds(src.PlayerUserIds),
                pfRegion(src.pfRegion),
                RunTime(src.RunTime),
                ServerHostname(src.ServerHostname),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                StatisticName(src.StatisticName),
                Tags(src.Tags)
            {}

            ~GameInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildVersion")], BuildVersion);
                FromJsonUtilS(input[U("GameMode")], GameMode);
                FromJsonUtilS(input[U("GameServerData")], GameServerData);
                FromJsonUtilE(input[U("GameServerStateEnum")], GameServerStateEnum);
                FromJsonUtilT(input[U("LastHeartbeat")], LastHeartbeat);
                FromJsonUtilS(input[U("LobbyID")], LobbyID);
                FromJsonUtilP(input[U("MaxPlayers")], MaxPlayers);
                FromJsonUtilS(input[U("PlayerUserIds")], PlayerUserIds);
                FromJsonUtilE(input[U("pfRegion")], pfRegion);
                FromJsonUtilP(input[U("RunTime")], RunTime);
                FromJsonUtilS(input[U("ServerHostname")], ServerHostname);
                FromJsonUtilS(input[U("ServerIPV6Address")], ServerIPV6Address);
                FromJsonUtilP(input[U("ServerPort")], ServerPort);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilS(input[U("Tags")], Tags);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[U("BuildVersion")] = each_BuildVersion;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[U("GameMode")] = each_GameMode;
                web::json::value each_GameServerData; ToJsonUtilS(GameServerData, each_GameServerData); output[U("GameServerData")] = each_GameServerData;
                web::json::value each_GameServerStateEnum; ToJsonUtilE(GameServerStateEnum, each_GameServerStateEnum); output[U("GameServerStateEnum")] = each_GameServerStateEnum;
                web::json::value each_LastHeartbeat; ToJsonUtilT(LastHeartbeat, each_LastHeartbeat); output[U("LastHeartbeat")] = each_LastHeartbeat;
                web::json::value each_LobbyID; ToJsonUtilS(LobbyID, each_LobbyID); output[U("LobbyID")] = each_LobbyID;
                web::json::value each_MaxPlayers; ToJsonUtilP(MaxPlayers, each_MaxPlayers); output[U("MaxPlayers")] = each_MaxPlayers;
                web::json::value each_PlayerUserIds; ToJsonUtilS(PlayerUserIds, each_PlayerUserIds); output[U("PlayerUserIds")] = each_PlayerUserIds;
                web::json::value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output[U("Region")] = each_pfRegion;
                web::json::value each_RunTime; ToJsonUtilP(RunTime, each_RunTime); output[U("RunTime")] = each_RunTime;
                web::json::value each_ServerHostname; ToJsonUtilS(ServerHostname, each_ServerHostname); output[U("ServerHostname")] = each_ServerHostname;
                web::json::value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output[U("ServerIPV6Address")] = each_ServerIPV6Address;
                web::json::value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output[U("ServerPort")] = each_ServerPort;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[U("Tags")] = each_Tags;
                return output;
            }
        };

        struct CurrentGamesResult : public PlayFabResultCommon
        {
            Int32 GameCount;
            std::list<GameInfo> Games;
            Int32 PlayerCount;

            CurrentGamesResult() :
                PlayFabResultCommon(),
                GameCount(),
                Games(),
                PlayerCount()
            {}

            CurrentGamesResult(const CurrentGamesResult& src) :
                PlayFabResultCommon(),
                GameCount(src.GameCount),
                Games(src.Games),
                PlayerCount(src.PlayerCount)
            {}

            ~CurrentGamesResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("GameCount")], GameCount);
                FromJsonUtilO(input[U("Games")], Games);
                FromJsonUtilP(input[U("PlayerCount")], PlayerCount);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameCount; ToJsonUtilP(GameCount, each_GameCount); output[U("GameCount")] = each_GameCount;
                web::json::value each_Games; ToJsonUtilO(Games, each_Games); output[U("Games")] = each_Games;
                web::json::value each_PlayerCount; ToJsonUtilP(PlayerCount, each_PlayerCount); output[U("PlayerCount")] = each_PlayerCount;
                return output;
            }
        };

        struct DeviceInfoRequest : public PlayFabRequestCommon
        {
            web::json::value Info; // Not truly arbitrary. See documentation for restrictions on format

            DeviceInfoRequest() :
                PlayFabRequestCommon(),
                Info()
            {}

            DeviceInfoRequest(const DeviceInfoRequest& src) :
                PlayFabRequestCommon(),
                Info(src.Info)
            {}

            ~DeviceInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                Info = input[U("Info")];
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("Info")] = Info;
                return output;
            }
        };

        struct EmptyResult : public PlayFabResultCommon
        {

            EmptyResult() :
                PlayFabResultCommon()
            {}

            EmptyResult(const EmptyResult& src) :
                PlayFabResultCommon()
            {}

            ~EmptyResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct EntityKey : public PlayFabBaseModel
        {
            std::string Id;
            Boxed<EntityTypes> Type;
            std::string TypeString;

            EntityKey() :
                PlayFabBaseModel(),
                Id(),
                Type(),
                TypeString()
            {}

            EntityKey(const EntityKey& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Type(src.Type),
                TypeString(src.TypeString)
            {}

            ~EntityKey() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Id")], Id);
                FromJsonUtilE(input[U("Type")], Type);
                FromJsonUtilS(input[U("TypeString")], TypeString);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Id; ToJsonUtilS(Id, each_Id); output[U("Id")] = each_Id;
                web::json::value each_Type; ToJsonUtilE(Type, each_Type); output[U("Type")] = each_Type;
                web::json::value each_TypeString; ToJsonUtilS(TypeString, each_TypeString); output[U("TypeString")] = each_TypeString;
                return output;
            }
        };

        struct EntityTokenResponse : public PlayFabResultCommon
        {
            Boxed<EntityKey> Entity;
            std::string EntityToken;
            Boxed<time_t> TokenExpiration;

            EntityTokenResponse() :
                PlayFabResultCommon(),
                Entity(),
                EntityToken(),
                TokenExpiration()
            {}

            EntityTokenResponse(const EntityTokenResponse& src) :
                PlayFabResultCommon(),
                Entity(src.Entity),
                EntityToken(src.EntityToken),
                TokenExpiration(src.TokenExpiration)
            {}

            ~EntityTokenResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Entity")], Entity);
                FromJsonUtilS(input[U("EntityToken")], EntityToken);
                FromJsonUtilT(input[U("TokenExpiration")], TokenExpiration);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Entity; ToJsonUtilO(Entity, each_Entity); output[U("Entity")] = each_Entity;
                web::json::value each_EntityToken; ToJsonUtilS(EntityToken, each_EntityToken); output[U("EntityToken")] = each_EntityToken;
                web::json::value each_TokenExpiration; ToJsonUtilT(TokenExpiration, each_TokenExpiration); output[U("TokenExpiration")] = each_TokenExpiration;
                return output;
            }
        };

        struct ExecuteCloudScriptRequest : public PlayFabRequestCommon
        {
            std::string FunctionName;
            web::json::value FunctionParameter;
            Boxed<bool> GeneratePlayStreamEvent;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            Boxed<Int32> SpecificRevision;

            ExecuteCloudScriptRequest() :
                PlayFabRequestCommon(),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent(),
                RevisionSelection(),
                SpecificRevision()
            {}

            ExecuteCloudScriptRequest(const ExecuteCloudScriptRequest& src) :
                PlayFabRequestCommon(),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision)
            {}

            ~ExecuteCloudScriptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FunctionName")], FunctionName);
                FunctionParameter = input[U("FunctionParameter")];
                FromJsonUtilP(input[U("GeneratePlayStreamEvent")], GeneratePlayStreamEvent);
                FromJsonUtilE(input[U("RevisionSelection")], RevisionSelection);
                FromJsonUtilP(input[U("SpecificRevision")], SpecificRevision);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output[U("FunctionName")] = each_FunctionName;
                output[U("FunctionParameter")] = FunctionParameter;
                web::json::value each_GeneratePlayStreamEvent; ToJsonUtilP(GeneratePlayStreamEvent, each_GeneratePlayStreamEvent); output[U("GeneratePlayStreamEvent")] = each_GeneratePlayStreamEvent;
                web::json::value each_RevisionSelection; ToJsonUtilE(RevisionSelection, each_RevisionSelection); output[U("RevisionSelection")] = each_RevisionSelection;
                web::json::value each_SpecificRevision; ToJsonUtilP(SpecificRevision, each_SpecificRevision); output[U("SpecificRevision")] = each_SpecificRevision;
                return output;
            }
        };

        struct ScriptExecutionError : public PlayFabBaseModel
        {
            std::string Error;
            std::string Message;
            std::string StackTrace;

            ScriptExecutionError() :
                PlayFabBaseModel(),
                Error(),
                Message(),
                StackTrace()
            {}

            ScriptExecutionError(const ScriptExecutionError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Message(src.Message),
                StackTrace(src.StackTrace)
            {}

            ~ScriptExecutionError() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Error")], Error);
                FromJsonUtilS(input[U("Message")], Message);
                FromJsonUtilS(input[U("StackTrace")], StackTrace);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Error; ToJsonUtilS(Error, each_Error); output[U("Error")] = each_Error;
                web::json::value each_Message; ToJsonUtilS(Message, each_Message); output[U("Message")] = each_Message;
                web::json::value each_StackTrace; ToJsonUtilS(StackTrace, each_StackTrace); output[U("StackTrace")] = each_StackTrace;
                return output;
            }
        };

        struct LogStatement : public PlayFabBaseModel
        {
            web::json::value Data;
            std::string Level;
            std::string Message;

            LogStatement() :
                PlayFabBaseModel(),
                Data(),
                Level(),
                Message()
            {}

            LogStatement(const LogStatement& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Level(src.Level),
                Message(src.Message)
            {}

            ~LogStatement() { }

            void FromJson(web::json::value& input) override
            {
                Data = input[U("Data")];
                FromJsonUtilS(input[U("Level")], Level);
                FromJsonUtilS(input[U("Message")], Message);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("Data")] = Data;
                web::json::value each_Level; ToJsonUtilS(Level, each_Level); output[U("Level")] = each_Level;
                web::json::value each_Message; ToJsonUtilS(Message, each_Message); output[U("Message")] = each_Message;
                return output;
            }
        };

        struct ExecuteCloudScriptResult : public PlayFabResultCommon
        {
            Int32 APIRequestsIssued;
            Boxed<ScriptExecutionError> Error;
            double ExecutionTimeSeconds;
            std::string FunctionName;
            web::json::value FunctionResult;
            Boxed<bool> FunctionResultTooLarge;
            Int32 HttpRequestsIssued;
            std::list<LogStatement> Logs;
            Boxed<bool> LogsTooLarge;
            Uint32 MemoryConsumedBytes;
            double ProcessorTimeSeconds;
            Int32 Revision;

            ExecuteCloudScriptResult() :
                PlayFabResultCommon(),
                APIRequestsIssued(),
                Error(),
                ExecutionTimeSeconds(),
                FunctionName(),
                FunctionResult(),
                FunctionResultTooLarge(),
                HttpRequestsIssued(),
                Logs(),
                LogsTooLarge(),
                MemoryConsumedBytes(),
                ProcessorTimeSeconds(),
                Revision()
            {}

            ExecuteCloudScriptResult(const ExecuteCloudScriptResult& src) :
                PlayFabResultCommon(),
                APIRequestsIssued(src.APIRequestsIssued),
                Error(src.Error),
                ExecutionTimeSeconds(src.ExecutionTimeSeconds),
                FunctionName(src.FunctionName),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge),
                HttpRequestsIssued(src.HttpRequestsIssued),
                Logs(src.Logs),
                LogsTooLarge(src.LogsTooLarge),
                MemoryConsumedBytes(src.MemoryConsumedBytes),
                ProcessorTimeSeconds(src.ProcessorTimeSeconds),
                Revision(src.Revision)
            {}

            ~ExecuteCloudScriptResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("APIRequestsIssued")], APIRequestsIssued);
                FromJsonUtilO(input[U("Error")], Error);
                FromJsonUtilP(input[U("ExecutionTimeSeconds")], ExecutionTimeSeconds);
                FromJsonUtilS(input[U("FunctionName")], FunctionName);
                FunctionResult = input[U("FunctionResult")];
                FromJsonUtilP(input[U("FunctionResultTooLarge")], FunctionResultTooLarge);
                FromJsonUtilP(input[U("HttpRequestsIssued")], HttpRequestsIssued);
                FromJsonUtilO(input[U("Logs")], Logs);
                FromJsonUtilP(input[U("LogsTooLarge")], LogsTooLarge);
                FromJsonUtilP(input[U("MemoryConsumedBytes")], MemoryConsumedBytes);
                FromJsonUtilP(input[U("ProcessorTimeSeconds")], ProcessorTimeSeconds);
                FromJsonUtilP(input[U("Revision")], Revision);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_APIRequestsIssued; ToJsonUtilP(APIRequestsIssued, each_APIRequestsIssued); output[U("APIRequestsIssued")] = each_APIRequestsIssued;
                web::json::value each_Error; ToJsonUtilO(Error, each_Error); output[U("Error")] = each_Error;
                web::json::value each_ExecutionTimeSeconds; ToJsonUtilP(ExecutionTimeSeconds, each_ExecutionTimeSeconds); output[U("ExecutionTimeSeconds")] = each_ExecutionTimeSeconds;
                web::json::value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output[U("FunctionName")] = each_FunctionName;
                output[U("FunctionResult")] = FunctionResult;
                web::json::value each_FunctionResultTooLarge; ToJsonUtilP(FunctionResultTooLarge, each_FunctionResultTooLarge); output[U("FunctionResultTooLarge")] = each_FunctionResultTooLarge;
                web::json::value each_HttpRequestsIssued; ToJsonUtilP(HttpRequestsIssued, each_HttpRequestsIssued); output[U("HttpRequestsIssued")] = each_HttpRequestsIssued;
                web::json::value each_Logs; ToJsonUtilO(Logs, each_Logs); output[U("Logs")] = each_Logs;
                web::json::value each_LogsTooLarge; ToJsonUtilP(LogsTooLarge, each_LogsTooLarge); output[U("LogsTooLarge")] = each_LogsTooLarge;
                web::json::value each_MemoryConsumedBytes; ToJsonUtilP(MemoryConsumedBytes, each_MemoryConsumedBytes); output[U("MemoryConsumedBytes")] = each_MemoryConsumedBytes;
                web::json::value each_ProcessorTimeSeconds; ToJsonUtilP(ProcessorTimeSeconds, each_ProcessorTimeSeconds); output[U("ProcessorTimeSeconds")] = each_ProcessorTimeSeconds;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[U("Revision")] = each_Revision;
                return output;
            }
        };

        struct FacebookPlayFabIdPair : public PlayFabBaseModel
        {
            std::string FacebookId;
            std::string PlayFabId;

            FacebookPlayFabIdPair() :
                PlayFabBaseModel(),
                FacebookId(),
                PlayFabId()
            {}

            FacebookPlayFabIdPair(const FacebookPlayFabIdPair& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                PlayFabId(src.PlayFabId)
            {}

            ~FacebookPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FacebookId")], FacebookId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FacebookId; ToJsonUtilS(FacebookId, each_FacebookId); output[U("FacebookId")] = each_FacebookId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct UserFacebookInfo : public PlayFabBaseModel
        {
            std::string FacebookId;
            std::string FullName;

            UserFacebookInfo() :
                PlayFabBaseModel(),
                FacebookId(),
                FullName()
            {}

            UserFacebookInfo(const UserFacebookInfo& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                FullName(src.FullName)
            {}

            ~UserFacebookInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FacebookId")], FacebookId);
                FromJsonUtilS(input[U("FullName")], FullName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FacebookId; ToJsonUtilS(FacebookId, each_FacebookId); output[U("FacebookId")] = each_FacebookId;
                web::json::value each_FullName; ToJsonUtilS(FullName, each_FullName); output[U("FullName")] = each_FullName;
                return output;
            }
        };

        struct UserGameCenterInfo : public PlayFabBaseModel
        {
            std::string GameCenterId;

            UserGameCenterInfo() :
                PlayFabBaseModel(),
                GameCenterId()
            {}

            UserGameCenterInfo(const UserGameCenterInfo& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId)
            {}

            ~UserGameCenterInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("GameCenterId")], GameCenterId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameCenterId; ToJsonUtilS(GameCenterId, each_GameCenterId); output[U("GameCenterId")] = each_GameCenterId;
                return output;
            }
        };

        struct LinkedPlatformAccountModel : public PlayFabBaseModel
        {
            std::string Email;
            Boxed<LoginIdentityProvider> Platform;
            std::string PlatformUserId;
            std::string Username;

            LinkedPlatformAccountModel() :
                PlayFabBaseModel(),
                Email(),
                Platform(),
                PlatformUserId(),
                Username()
            {}

            LinkedPlatformAccountModel(const LinkedPlatformAccountModel& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username)
            {}

            ~LinkedPlatformAccountModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Email")], Email);
                FromJsonUtilE(input[U("Platform")], Platform);
                FromJsonUtilS(input[U("PlatformUserId")], PlatformUserId);
                FromJsonUtilS(input[U("Username")], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[U("Email")] = each_Email;
                web::json::value each_Platform; ToJsonUtilE(Platform, each_Platform); output[U("Platform")] = each_Platform;
                web::json::value each_PlatformUserId; ToJsonUtilS(PlatformUserId, each_PlatformUserId); output[U("PlatformUserId")] = each_PlatformUserId;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                return output;
            }
        };

        struct LocationModel : public PlayFabBaseModel
        {
            std::string City;
            Boxed<ContinentCode> pfContinentCode;
            Boxed<CountryCode> pfCountryCode;
            Boxed<double> Latitude;
            Boxed<double> Longitude;

            LocationModel() :
                PlayFabBaseModel(),
                City(),
                pfContinentCode(),
                pfCountryCode(),
                Latitude(),
                Longitude()
            {}

            LocationModel(const LocationModel& src) :
                PlayFabBaseModel(),
                City(src.City),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            ~LocationModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("City")], City);
                FromJsonUtilE(input[U("pfContinentCode")], pfContinentCode);
                FromJsonUtilE(input[U("pfCountryCode")], pfCountryCode);
                FromJsonUtilP(input[U("Latitude")], Latitude);
                FromJsonUtilP(input[U("Longitude")], Longitude);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_City; ToJsonUtilS(City, each_City); output[U("City")] = each_City;
                web::json::value each_pfContinentCode; ToJsonUtilE(pfContinentCode, each_pfContinentCode); output[U("ContinentCode")] = each_pfContinentCode;
                web::json::value each_pfCountryCode; ToJsonUtilE(pfCountryCode, each_pfCountryCode); output[U("CountryCode")] = each_pfCountryCode;
                web::json::value each_Latitude; ToJsonUtilP(Latitude, each_Latitude); output[U("Latitude")] = each_Latitude;
                web::json::value each_Longitude; ToJsonUtilP(Longitude, each_Longitude); output[U("Longitude")] = each_Longitude;
                return output;
            }
        };

        struct SubscriptionModel : public PlayFabBaseModel
        {
            time_t Expiration;
            time_t InitialSubscriptionTime;
            bool IsActive;
            Boxed<SubscriptionProviderStatus> Status;
            std::string SubscriptionId;
            std::string SubscriptionItemId;
            std::string SubscriptionProvider;

            SubscriptionModel() :
                PlayFabBaseModel(),
                Expiration(),
                InitialSubscriptionTime(),
                IsActive(),
                Status(),
                SubscriptionId(),
                SubscriptionItemId(),
                SubscriptionProvider()
            {}

            SubscriptionModel(const SubscriptionModel& src) :
                PlayFabBaseModel(),
                Expiration(src.Expiration),
                InitialSubscriptionTime(src.InitialSubscriptionTime),
                IsActive(src.IsActive),
                Status(src.Status),
                SubscriptionId(src.SubscriptionId),
                SubscriptionItemId(src.SubscriptionItemId),
                SubscriptionProvider(src.SubscriptionProvider)
            {}

            ~SubscriptionModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("Expiration")], Expiration);
                FromJsonUtilT(input[U("InitialSubscriptionTime")], InitialSubscriptionTime);
                FromJsonUtilP(input[U("IsActive")], IsActive);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilS(input[U("SubscriptionId")], SubscriptionId);
                FromJsonUtilS(input[U("SubscriptionItemId")], SubscriptionItemId);
                FromJsonUtilS(input[U("SubscriptionProvider")], SubscriptionProvider);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Expiration; ToJsonUtilT(Expiration, each_Expiration); output[U("Expiration")] = each_Expiration;
                web::json::value each_InitialSubscriptionTime; ToJsonUtilT(InitialSubscriptionTime, each_InitialSubscriptionTime); output[U("InitialSubscriptionTime")] = each_InitialSubscriptionTime;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[U("IsActive")] = each_IsActive;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
                web::json::value each_SubscriptionId; ToJsonUtilS(SubscriptionId, each_SubscriptionId); output[U("SubscriptionId")] = each_SubscriptionId;
                web::json::value each_SubscriptionItemId; ToJsonUtilS(SubscriptionItemId, each_SubscriptionItemId); output[U("SubscriptionItemId")] = each_SubscriptionItemId;
                web::json::value each_SubscriptionProvider; ToJsonUtilS(SubscriptionProvider, each_SubscriptionProvider); output[U("SubscriptionProvider")] = each_SubscriptionProvider;
                return output;
            }
        };

        struct MembershipModel : public PlayFabBaseModel
        {
            bool IsActive;
            time_t MembershipExpiration;
            std::string MembershipId;
            Boxed<time_t> OverrideExpiration;
            std::list<SubscriptionModel> Subscriptions;

            MembershipModel() :
                PlayFabBaseModel(),
                IsActive(),
                MembershipExpiration(),
                MembershipId(),
                OverrideExpiration(),
                Subscriptions()
            {}

            MembershipModel(const MembershipModel& src) :
                PlayFabBaseModel(),
                IsActive(src.IsActive),
                MembershipExpiration(src.MembershipExpiration),
                MembershipId(src.MembershipId),
                OverrideExpiration(src.OverrideExpiration),
                Subscriptions(src.Subscriptions)
            {}

            ~MembershipModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("IsActive")], IsActive);
                FromJsonUtilT(input[U("MembershipExpiration")], MembershipExpiration);
                FromJsonUtilS(input[U("MembershipId")], MembershipId);
                FromJsonUtilT(input[U("OverrideExpiration")], OverrideExpiration);
                FromJsonUtilO(input[U("Subscriptions")], Subscriptions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[U("IsActive")] = each_IsActive;
                web::json::value each_MembershipExpiration; ToJsonUtilT(MembershipExpiration, each_MembershipExpiration); output[U("MembershipExpiration")] = each_MembershipExpiration;
                web::json::value each_MembershipId; ToJsonUtilS(MembershipId, each_MembershipId); output[U("MembershipId")] = each_MembershipId;
                web::json::value each_OverrideExpiration; ToJsonUtilT(OverrideExpiration, each_OverrideExpiration); output[U("OverrideExpiration")] = each_OverrideExpiration;
                web::json::value each_Subscriptions; ToJsonUtilO(Subscriptions, each_Subscriptions); output[U("Subscriptions")] = each_Subscriptions;
                return output;
            }
        };

        struct PushNotificationRegistrationModel : public PlayFabBaseModel
        {
            std::string NotificationEndpointARN;
            Boxed<PushNotificationPlatform> Platform;

            PushNotificationRegistrationModel() :
                PlayFabBaseModel(),
                NotificationEndpointARN(),
                Platform()
            {}

            PushNotificationRegistrationModel(const PushNotificationRegistrationModel& src) :
                PlayFabBaseModel(),
                NotificationEndpointARN(src.NotificationEndpointARN),
                Platform(src.Platform)
            {}

            ~PushNotificationRegistrationModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("NotificationEndpointARN")], NotificationEndpointARN);
                FromJsonUtilE(input[U("Platform")], Platform);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_NotificationEndpointARN; ToJsonUtilS(NotificationEndpointARN, each_NotificationEndpointARN); output[U("NotificationEndpointARN")] = each_NotificationEndpointARN;
                web::json::value each_Platform; ToJsonUtilE(Platform, each_Platform); output[U("Platform")] = each_Platform;
                return output;
            }
        };

        struct StatisticModel : public PlayFabBaseModel
        {
            std::string Name;
            Int32 Value;
            Int32 Version;

            StatisticModel() :
                PlayFabBaseModel(),
                Name(),
                Value(),
                Version()
            {}

            StatisticModel(const StatisticModel& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Value(src.Value),
                Version(src.Version)
            {}

            ~StatisticModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Name")], Name);
                FromJsonUtilP(input[U("Value")], Value);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                web::json::value each_Value; ToJsonUtilP(Value, each_Value); output[U("Value")] = each_Value;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct TagModel : public PlayFabBaseModel
        {
            std::string TagValue;

            TagModel() :
                PlayFabBaseModel(),
                TagValue()
            {}

            TagModel(const TagModel& src) :
                PlayFabBaseModel(),
                TagValue(src.TagValue)
            {}

            ~TagModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("TagValue")], TagValue);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TagValue; ToJsonUtilS(TagValue, each_TagValue); output[U("TagValue")] = each_TagValue;
                return output;
            }
        };

        struct ValueToDateModel : public PlayFabBaseModel
        {
            std::string Currency;
            Uint32 TotalValue;
            std::string TotalValueAsDecimal;

            ValueToDateModel() :
                PlayFabBaseModel(),
                Currency(),
                TotalValue(),
                TotalValueAsDecimal()
            {}

            ValueToDateModel(const ValueToDateModel& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                TotalValue(src.TotalValue),
                TotalValueAsDecimal(src.TotalValueAsDecimal)
            {}

            ~ValueToDateModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Currency")], Currency);
                FromJsonUtilP(input[U("TotalValue")], TotalValue);
                FromJsonUtilS(input[U("TotalValueAsDecimal")], TotalValueAsDecimal);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Currency; ToJsonUtilS(Currency, each_Currency); output[U("Currency")] = each_Currency;
                web::json::value each_TotalValue; ToJsonUtilP(TotalValue, each_TotalValue); output[U("TotalValue")] = each_TotalValue;
                web::json::value each_TotalValueAsDecimal; ToJsonUtilS(TotalValueAsDecimal, each_TotalValueAsDecimal); output[U("TotalValueAsDecimal")] = each_TotalValueAsDecimal;
                return output;
            }
        };

        struct PlayerProfileModel : public PlayFabBaseModel
        {
            std::list<AdCampaignAttributionModel> AdCampaignAttributions;
            std::string AvatarUrl;
            Boxed<time_t> BannedUntil;
            std::list<ContactEmailInfoModel> ContactEmailAddresses;
            Boxed<time_t> Created;
            std::string DisplayName;
            Boxed<time_t> LastLogin;
            std::list<LinkedPlatformAccountModel> LinkedAccounts;
            std::list<LocationModel> Locations;
            std::list<MembershipModel> Memberships;
            Boxed<LoginIdentityProvider> Origination;
            std::string PlayerId;
            std::string PublisherId;
            std::list<PushNotificationRegistrationModel> PushNotificationRegistrations;
            std::list<StatisticModel> Statistics;
            std::list<TagModel> Tags;
            std::string TitleId;
            Boxed<Uint32> TotalValueToDateInUSD;
            std::list<ValueToDateModel> ValuesToDate;

            PlayerProfileModel() :
                PlayFabBaseModel(),
                AdCampaignAttributions(),
                AvatarUrl(),
                BannedUntil(),
                ContactEmailAddresses(),
                Created(),
                DisplayName(),
                LastLogin(),
                LinkedAccounts(),
                Locations(),
                Memberships(),
                Origination(),
                PlayerId(),
                PublisherId(),
                PushNotificationRegistrations(),
                Statistics(),
                Tags(),
                TitleId(),
                TotalValueToDateInUSD(),
                ValuesToDate()
            {}

            PlayerProfileModel(const PlayerProfileModel& src) :
                PlayFabBaseModel(),
                AdCampaignAttributions(src.AdCampaignAttributions),
                AvatarUrl(src.AvatarUrl),
                BannedUntil(src.BannedUntil),
                ContactEmailAddresses(src.ContactEmailAddresses),
                Created(src.Created),
                DisplayName(src.DisplayName),
                LastLogin(src.LastLogin),
                LinkedAccounts(src.LinkedAccounts),
                Locations(src.Locations),
                Memberships(src.Memberships),
                Origination(src.Origination),
                PlayerId(src.PlayerId),
                PublisherId(src.PublisherId),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                Statistics(src.Statistics),
                Tags(src.Tags),
                TitleId(src.TitleId),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate)
            {}

            ~PlayerProfileModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("AdCampaignAttributions")], AdCampaignAttributions);
                FromJsonUtilS(input[U("AvatarUrl")], AvatarUrl);
                FromJsonUtilT(input[U("BannedUntil")], BannedUntil);
                FromJsonUtilO(input[U("ContactEmailAddresses")], ContactEmailAddresses);
                FromJsonUtilT(input[U("Created")], Created);
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilT(input[U("LastLogin")], LastLogin);
                FromJsonUtilO(input[U("LinkedAccounts")], LinkedAccounts);
                FromJsonUtilO(input[U("Locations")], Locations);
                FromJsonUtilO(input[U("Memberships")], Memberships);
                FromJsonUtilE(input[U("Origination")], Origination);
                FromJsonUtilS(input[U("PlayerId")], PlayerId);
                FromJsonUtilS(input[U("PublisherId")], PublisherId);
                FromJsonUtilO(input[U("PushNotificationRegistrations")], PushNotificationRegistrations);
                FromJsonUtilO(input[U("Statistics")], Statistics);
                FromJsonUtilO(input[U("Tags")], Tags);
                FromJsonUtilS(input[U("TitleId")], TitleId);
                FromJsonUtilP(input[U("TotalValueToDateInUSD")], TotalValueToDateInUSD);
                FromJsonUtilO(input[U("ValuesToDate")], ValuesToDate);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AdCampaignAttributions; ToJsonUtilO(AdCampaignAttributions, each_AdCampaignAttributions); output[U("AdCampaignAttributions")] = each_AdCampaignAttributions;
                web::json::value each_AvatarUrl; ToJsonUtilS(AvatarUrl, each_AvatarUrl); output[U("AvatarUrl")] = each_AvatarUrl;
                web::json::value each_BannedUntil; ToJsonUtilT(BannedUntil, each_BannedUntil); output[U("BannedUntil")] = each_BannedUntil;
                web::json::value each_ContactEmailAddresses; ToJsonUtilO(ContactEmailAddresses, each_ContactEmailAddresses); output[U("ContactEmailAddresses")] = each_ContactEmailAddresses;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[U("Created")] = each_Created;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_LastLogin; ToJsonUtilT(LastLogin, each_LastLogin); output[U("LastLogin")] = each_LastLogin;
                web::json::value each_LinkedAccounts; ToJsonUtilO(LinkedAccounts, each_LinkedAccounts); output[U("LinkedAccounts")] = each_LinkedAccounts;
                web::json::value each_Locations; ToJsonUtilO(Locations, each_Locations); output[U("Locations")] = each_Locations;
                web::json::value each_Memberships; ToJsonUtilO(Memberships, each_Memberships); output[U("Memberships")] = each_Memberships;
                web::json::value each_Origination; ToJsonUtilE(Origination, each_Origination); output[U("Origination")] = each_Origination;
                web::json::value each_PlayerId; ToJsonUtilS(PlayerId, each_PlayerId); output[U("PlayerId")] = each_PlayerId;
                web::json::value each_PublisherId; ToJsonUtilS(PublisherId, each_PublisherId); output[U("PublisherId")] = each_PublisherId;
                web::json::value each_PushNotificationRegistrations; ToJsonUtilO(PushNotificationRegistrations, each_PushNotificationRegistrations); output[U("PushNotificationRegistrations")] = each_PushNotificationRegistrations;
                web::json::value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output[U("Statistics")] = each_Statistics;
                web::json::value each_Tags; ToJsonUtilO(Tags, each_Tags); output[U("Tags")] = each_Tags;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                web::json::value each_TotalValueToDateInUSD; ToJsonUtilP(TotalValueToDateInUSD, each_TotalValueToDateInUSD); output[U("TotalValueToDateInUSD")] = each_TotalValueToDateInUSD;
                web::json::value each_ValuesToDate; ToJsonUtilO(ValuesToDate, each_ValuesToDate); output[U("ValuesToDate")] = each_ValuesToDate;
                return output;
            }
        };

        struct UserSteamInfo : public PlayFabBaseModel
        {
            Boxed<TitleActivationStatus> SteamActivationStatus;
            std::string SteamCountry;
            Boxed<Currency> SteamCurrency;
            std::string SteamId;

            UserSteamInfo() :
                PlayFabBaseModel(),
                SteamActivationStatus(),
                SteamCountry(),
                SteamCurrency(),
                SteamId()
            {}

            UserSteamInfo(const UserSteamInfo& src) :
                PlayFabBaseModel(),
                SteamActivationStatus(src.SteamActivationStatus),
                SteamCountry(src.SteamCountry),
                SteamCurrency(src.SteamCurrency),
                SteamId(src.SteamId)
            {}

            ~UserSteamInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("SteamActivationStatus")], SteamActivationStatus);
                FromJsonUtilS(input[U("SteamCountry")], SteamCountry);
                FromJsonUtilE(input[U("SteamCurrency")], SteamCurrency);
                FromJsonUtilS(input[U("SteamId")], SteamId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SteamActivationStatus; ToJsonUtilE(SteamActivationStatus, each_SteamActivationStatus); output[U("SteamActivationStatus")] = each_SteamActivationStatus;
                web::json::value each_SteamCountry; ToJsonUtilS(SteamCountry, each_SteamCountry); output[U("SteamCountry")] = each_SteamCountry;
                web::json::value each_SteamCurrency; ToJsonUtilE(SteamCurrency, each_SteamCurrency); output[U("SteamCurrency")] = each_SteamCurrency;
                web::json::value each_SteamId; ToJsonUtilS(SteamId, each_SteamId); output[U("SteamId")] = each_SteamId;
                return output;
            }
        };

        struct FriendInfo : public PlayFabBaseModel
        {
            std::string CurrentMatchmakerLobbyId;
            Boxed<UserFacebookInfo> FacebookInfo;
            std::string FriendPlayFabId;
            Boxed<UserGameCenterInfo> GameCenterInfo;
            Boxed<PlayerProfileModel> Profile;
            Boxed<UserSteamInfo> SteamInfo;
            std::list<std::string> Tags;
            std::string TitleDisplayName;
            std::string Username;

            FriendInfo() :
                PlayFabBaseModel(),
                CurrentMatchmakerLobbyId(),
                FacebookInfo(),
                FriendPlayFabId(),
                GameCenterInfo(),
                Profile(),
                SteamInfo(),
                Tags(),
                TitleDisplayName(),
                Username()
            {}

            FriendInfo(const FriendInfo& src) :
                PlayFabBaseModel(),
                CurrentMatchmakerLobbyId(src.CurrentMatchmakerLobbyId),
                FacebookInfo(src.FacebookInfo),
                FriendPlayFabId(src.FriendPlayFabId),
                GameCenterInfo(src.GameCenterInfo),
                Profile(src.Profile),
                SteamInfo(src.SteamInfo),
                Tags(src.Tags),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username)
            {}

            ~FriendInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CurrentMatchmakerLobbyId")], CurrentMatchmakerLobbyId);
                FromJsonUtilO(input[U("FacebookInfo")], FacebookInfo);
                FromJsonUtilS(input[U("FriendPlayFabId")], FriendPlayFabId);
                FromJsonUtilO(input[U("GameCenterInfo")], GameCenterInfo);
                FromJsonUtilO(input[U("Profile")], Profile);
                FromJsonUtilO(input[U("SteamInfo")], SteamInfo);
                FromJsonUtilS(input[U("Tags")], Tags);
                FromJsonUtilS(input[U("TitleDisplayName")], TitleDisplayName);
                FromJsonUtilS(input[U("Username")], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CurrentMatchmakerLobbyId; ToJsonUtilS(CurrentMatchmakerLobbyId, each_CurrentMatchmakerLobbyId); output[U("CurrentMatchmakerLobbyId")] = each_CurrentMatchmakerLobbyId;
                web::json::value each_FacebookInfo; ToJsonUtilO(FacebookInfo, each_FacebookInfo); output[U("FacebookInfo")] = each_FacebookInfo;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[U("FriendPlayFabId")] = each_FriendPlayFabId;
                web::json::value each_GameCenterInfo; ToJsonUtilO(GameCenterInfo, each_GameCenterInfo); output[U("GameCenterInfo")] = each_GameCenterInfo;
                web::json::value each_Profile; ToJsonUtilO(Profile, each_Profile); output[U("Profile")] = each_Profile;
                web::json::value each_SteamInfo; ToJsonUtilO(SteamInfo, each_SteamInfo); output[U("SteamInfo")] = each_SteamInfo;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[U("Tags")] = each_Tags;
                web::json::value each_TitleDisplayName; ToJsonUtilS(TitleDisplayName, each_TitleDisplayName); output[U("TitleDisplayName")] = each_TitleDisplayName;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                return output;
            }
        };

        struct GameCenterPlayFabIdPair : public PlayFabBaseModel
        {
            std::string GameCenterId;
            std::string PlayFabId;

            GameCenterPlayFabIdPair() :
                PlayFabBaseModel(),
                GameCenterId(),
                PlayFabId()
            {}

            GameCenterPlayFabIdPair(const GameCenterPlayFabIdPair& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId),
                PlayFabId(src.PlayFabId)
            {}

            ~GameCenterPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("GameCenterId")], GameCenterId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameCenterId; ToJsonUtilS(GameCenterId, each_GameCenterId); output[U("GameCenterId")] = each_GameCenterId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GameServerRegionsRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;
            std::string TitleId;

            GameServerRegionsRequest() :
                PlayFabRequestCommon(),
                BuildVersion(),
                TitleId()
            {}

            GameServerRegionsRequest(const GameServerRegionsRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion),
                TitleId(src.TitleId)
            {}

            ~GameServerRegionsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildVersion")], BuildVersion);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[U("BuildVersion")] = each_BuildVersion;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct RegionInfo : public PlayFabBaseModel
        {
            bool Available;
            std::string Name;
            std::string PingUrl;
            Boxed<Region> pfRegion;

            RegionInfo() :
                PlayFabBaseModel(),
                Available(),
                Name(),
                PingUrl(),
                pfRegion()
            {}

            RegionInfo(const RegionInfo& src) :
                PlayFabBaseModel(),
                Available(src.Available),
                Name(src.Name),
                PingUrl(src.PingUrl),
                pfRegion(src.pfRegion)
            {}

            ~RegionInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Available")], Available);
                FromJsonUtilS(input[U("Name")], Name);
                FromJsonUtilS(input[U("PingUrl")], PingUrl);
                FromJsonUtilE(input[U("pfRegion")], pfRegion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Available; ToJsonUtilP(Available, each_Available); output[U("Available")] = each_Available;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                web::json::value each_PingUrl; ToJsonUtilS(PingUrl, each_PingUrl); output[U("PingUrl")] = each_PingUrl;
                web::json::value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output[U("Region")] = each_pfRegion;
                return output;
            }
        };

        struct GameServerRegionsResult : public PlayFabResultCommon
        {
            std::list<RegionInfo> Regions;

            GameServerRegionsResult() :
                PlayFabResultCommon(),
                Regions()
            {}

            GameServerRegionsResult(const GameServerRegionsResult& src) :
                PlayFabResultCommon(),
                Regions(src.Regions)
            {}

            ~GameServerRegionsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Regions")], Regions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Regions; ToJsonUtilO(Regions, each_Regions); output[U("Regions")] = each_Regions;
                return output;
            }
        };

        struct GenericPlayFabIdPair : public PlayFabBaseModel
        {
            Boxed<GenericServiceId> GenericId;
            std::string PlayFabId;

            GenericPlayFabIdPair() :
                PlayFabBaseModel(),
                GenericId(),
                PlayFabId()
            {}

            GenericPlayFabIdPair(const GenericPlayFabIdPair& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId),
                PlayFabId(src.PlayFabId)
            {}

            ~GenericPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("GenericId")], GenericId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GenericId; ToJsonUtilO(GenericId, each_GenericId); output[U("GenericId")] = each_GenericId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GetAccountInfoRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string PlayFabId;
            std::string TitleDisplayName;
            std::string Username;

            GetAccountInfoRequest() :
                PlayFabRequestCommon(),
                Email(),
                PlayFabId(),
                TitleDisplayName(),
                Username()
            {}

            GetAccountInfoRequest(const GetAccountInfoRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                PlayFabId(src.PlayFabId),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username)
            {}

            ~GetAccountInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Email")], Email);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("TitleDisplayName")], TitleDisplayName);
                FromJsonUtilS(input[U("Username")], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[U("Email")] = each_Email;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_TitleDisplayName; ToJsonUtilS(TitleDisplayName, each_TitleDisplayName); output[U("TitleDisplayName")] = each_TitleDisplayName;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                return output;
            }
        };

        struct UserAndroidDeviceInfo : public PlayFabBaseModel
        {
            std::string AndroidDeviceId;

            UserAndroidDeviceInfo() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UserAndroidDeviceInfo(const UserAndroidDeviceInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            ~UserAndroidDeviceInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AndroidDeviceId")], AndroidDeviceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output[U("AndroidDeviceId")] = each_AndroidDeviceId;
                return output;
            }
        };

        struct UserCustomIdInfo : public PlayFabBaseModel
        {
            std::string CustomId;

            UserCustomIdInfo() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UserCustomIdInfo(const UserCustomIdInfo& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            ~UserCustomIdInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CustomId")], CustomId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output[U("CustomId")] = each_CustomId;
                return output;
            }
        };

        struct UserGoogleInfo : public PlayFabBaseModel
        {
            std::string GoogleEmail;
            std::string GoogleGender;
            std::string GoogleId;
            std::string GoogleLocale;

            UserGoogleInfo() :
                PlayFabBaseModel(),
                GoogleEmail(),
                GoogleGender(),
                GoogleId(),
                GoogleLocale()
            {}

            UserGoogleInfo(const UserGoogleInfo& src) :
                PlayFabBaseModel(),
                GoogleEmail(src.GoogleEmail),
                GoogleGender(src.GoogleGender),
                GoogleId(src.GoogleId),
                GoogleLocale(src.GoogleLocale)
            {}

            ~UserGoogleInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("GoogleEmail")], GoogleEmail);
                FromJsonUtilS(input[U("GoogleGender")], GoogleGender);
                FromJsonUtilS(input[U("GoogleId")], GoogleId);
                FromJsonUtilS(input[U("GoogleLocale")], GoogleLocale);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GoogleEmail; ToJsonUtilS(GoogleEmail, each_GoogleEmail); output[U("GoogleEmail")] = each_GoogleEmail;
                web::json::value each_GoogleGender; ToJsonUtilS(GoogleGender, each_GoogleGender); output[U("GoogleGender")] = each_GoogleGender;
                web::json::value each_GoogleId; ToJsonUtilS(GoogleId, each_GoogleId); output[U("GoogleId")] = each_GoogleId;
                web::json::value each_GoogleLocale; ToJsonUtilS(GoogleLocale, each_GoogleLocale); output[U("GoogleLocale")] = each_GoogleLocale;
                return output;
            }
        };

        struct UserIosDeviceInfo : public PlayFabBaseModel
        {
            std::string IosDeviceId;

            UserIosDeviceInfo() :
                PlayFabBaseModel(),
                IosDeviceId()
            {}

            UserIosDeviceInfo(const UserIosDeviceInfo& src) :
                PlayFabBaseModel(),
                IosDeviceId(src.IosDeviceId)
            {}

            ~UserIosDeviceInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("IosDeviceId")], IosDeviceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IosDeviceId; ToJsonUtilS(IosDeviceId, each_IosDeviceId); output[U("IosDeviceId")] = each_IosDeviceId;
                return output;
            }
        };

        struct UserKongregateInfo : public PlayFabBaseModel
        {
            std::string KongregateId;
            std::string KongregateName;

            UserKongregateInfo() :
                PlayFabBaseModel(),
                KongregateId(),
                KongregateName()
            {}

            UserKongregateInfo(const UserKongregateInfo& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                KongregateName(src.KongregateName)
            {}

            ~UserKongregateInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("KongregateId")], KongregateId);
                FromJsonUtilS(input[U("KongregateName")], KongregateName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output[U("KongregateId")] = each_KongregateId;
                web::json::value each_KongregateName; ToJsonUtilS(KongregateName, each_KongregateName); output[U("KongregateName")] = each_KongregateName;
                return output;
            }
        };

        struct UserPrivateAccountInfo : public PlayFabBaseModel
        {
            std::string Email;

            UserPrivateAccountInfo() :
                PlayFabBaseModel(),
                Email()
            {}

            UserPrivateAccountInfo(const UserPrivateAccountInfo& src) :
                PlayFabBaseModel(),
                Email(src.Email)
            {}

            ~UserPrivateAccountInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Email")], Email);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[U("Email")] = each_Email;
                return output;
            }
        };

        struct UserPsnInfo : public PlayFabBaseModel
        {
            std::string PsnAccountId;
            std::string PsnOnlineId;

            UserPsnInfo() :
                PlayFabBaseModel(),
                PsnAccountId(),
                PsnOnlineId()
            {}

            UserPsnInfo(const UserPsnInfo& src) :
                PlayFabBaseModel(),
                PsnAccountId(src.PsnAccountId),
                PsnOnlineId(src.PsnOnlineId)
            {}

            ~UserPsnInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PsnAccountId")], PsnAccountId);
                FromJsonUtilS(input[U("PsnOnlineId")], PsnOnlineId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PsnAccountId; ToJsonUtilS(PsnAccountId, each_PsnAccountId); output[U("PsnAccountId")] = each_PsnAccountId;
                web::json::value each_PsnOnlineId; ToJsonUtilS(PsnOnlineId, each_PsnOnlineId); output[U("PsnOnlineId")] = each_PsnOnlineId;
                return output;
            }
        };

        struct UserTitleInfo : public PlayFabBaseModel
        {
            std::string AvatarUrl;
            time_t Created;
            std::string DisplayName;
            Boxed<time_t> FirstLogin;
            Boxed<bool> isBanned;
            Boxed<time_t> LastLogin;
            Boxed<UserOrigination> Origination;
            Boxed<EntityKey> TitlePlayerAccount;

            UserTitleInfo() :
                PlayFabBaseModel(),
                AvatarUrl(),
                Created(),
                DisplayName(),
                FirstLogin(),
                isBanned(),
                LastLogin(),
                Origination(),
                TitlePlayerAccount()
            {}

            UserTitleInfo(const UserTitleInfo& src) :
                PlayFabBaseModel(),
                AvatarUrl(src.AvatarUrl),
                Created(src.Created),
                DisplayName(src.DisplayName),
                FirstLogin(src.FirstLogin),
                isBanned(src.isBanned),
                LastLogin(src.LastLogin),
                Origination(src.Origination),
                TitlePlayerAccount(src.TitlePlayerAccount)
            {}

            ~UserTitleInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AvatarUrl")], AvatarUrl);
                FromJsonUtilT(input[U("Created")], Created);
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilT(input[U("FirstLogin")], FirstLogin);
                FromJsonUtilP(input[U("isBanned")], isBanned);
                FromJsonUtilT(input[U("LastLogin")], LastLogin);
                FromJsonUtilE(input[U("Origination")], Origination);
                FromJsonUtilO(input[U("TitlePlayerAccount")], TitlePlayerAccount);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AvatarUrl; ToJsonUtilS(AvatarUrl, each_AvatarUrl); output[U("AvatarUrl")] = each_AvatarUrl;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[U("Created")] = each_Created;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_FirstLogin; ToJsonUtilT(FirstLogin, each_FirstLogin); output[U("FirstLogin")] = each_FirstLogin;
                web::json::value each_isBanned; ToJsonUtilP(isBanned, each_isBanned); output[U("isBanned")] = each_isBanned;
                web::json::value each_LastLogin; ToJsonUtilT(LastLogin, each_LastLogin); output[U("LastLogin")] = each_LastLogin;
                web::json::value each_Origination; ToJsonUtilE(Origination, each_Origination); output[U("Origination")] = each_Origination;
                web::json::value each_TitlePlayerAccount; ToJsonUtilO(TitlePlayerAccount, each_TitlePlayerAccount); output[U("TitlePlayerAccount")] = each_TitlePlayerAccount;
                return output;
            }
        };

        struct UserTwitchInfo : public PlayFabBaseModel
        {
            std::string TwitchId;
            std::string TwitchUserName;

            UserTwitchInfo() :
                PlayFabBaseModel(),
                TwitchId(),
                TwitchUserName()
            {}

            UserTwitchInfo(const UserTwitchInfo& src) :
                PlayFabBaseModel(),
                TwitchId(src.TwitchId),
                TwitchUserName(src.TwitchUserName)
            {}

            ~UserTwitchInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("TwitchId")], TwitchId);
                FromJsonUtilS(input[U("TwitchUserName")], TwitchUserName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TwitchId; ToJsonUtilS(TwitchId, each_TwitchId); output[U("TwitchId")] = each_TwitchId;
                web::json::value each_TwitchUserName; ToJsonUtilS(TwitchUserName, each_TwitchUserName); output[U("TwitchUserName")] = each_TwitchUserName;
                return output;
            }
        };

        struct UserXboxInfo : public PlayFabBaseModel
        {
            std::string XboxUserId;

            UserXboxInfo() :
                PlayFabBaseModel(),
                XboxUserId()
            {}

            UserXboxInfo(const UserXboxInfo& src) :
                PlayFabBaseModel(),
                XboxUserId(src.XboxUserId)
            {}

            ~UserXboxInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("XboxUserId")], XboxUserId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_XboxUserId; ToJsonUtilS(XboxUserId, each_XboxUserId); output[U("XboxUserId")] = each_XboxUserId;
                return output;
            }
        };

        struct UserAccountInfo : public PlayFabBaseModel
        {
            Boxed<UserAndroidDeviceInfo> AndroidDeviceInfo;
            time_t Created;
            Boxed<UserCustomIdInfo> CustomIdInfo;
            Boxed<UserFacebookInfo> FacebookInfo;
            Boxed<UserGameCenterInfo> GameCenterInfo;
            Boxed<UserGoogleInfo> GoogleInfo;
            Boxed<UserIosDeviceInfo> IosDeviceInfo;
            Boxed<UserKongregateInfo> KongregateInfo;
            std::string PlayFabId;
            Boxed<UserPrivateAccountInfo> PrivateInfo;
            Boxed<UserPsnInfo> PsnInfo;
            Boxed<UserSteamInfo> SteamInfo;
            Boxed<UserTitleInfo> TitleInfo;
            Boxed<UserTwitchInfo> TwitchInfo;
            std::string Username;
            Boxed<UserXboxInfo> XboxInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                AndroidDeviceInfo(),
                Created(),
                CustomIdInfo(),
                FacebookInfo(),
                GameCenterInfo(),
                GoogleInfo(),
                IosDeviceInfo(),
                KongregateInfo(),
                PlayFabId(),
                PrivateInfo(),
                PsnInfo(),
                SteamInfo(),
                TitleInfo(),
                TwitchInfo(),
                Username(),
                XboxInfo()
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceInfo(src.AndroidDeviceInfo),
                Created(src.Created),
                CustomIdInfo(src.CustomIdInfo),
                FacebookInfo(src.FacebookInfo),
                GameCenterInfo(src.GameCenterInfo),
                GoogleInfo(src.GoogleInfo),
                IosDeviceInfo(src.IosDeviceInfo),
                KongregateInfo(src.KongregateInfo),
                PlayFabId(src.PlayFabId),
                PrivateInfo(src.PrivateInfo),
                PsnInfo(src.PsnInfo),
                SteamInfo(src.SteamInfo),
                TitleInfo(src.TitleInfo),
                TwitchInfo(src.TwitchInfo),
                Username(src.Username),
                XboxInfo(src.XboxInfo)
            {}

            ~UserAccountInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("AndroidDeviceInfo")], AndroidDeviceInfo);
                FromJsonUtilT(input[U("Created")], Created);
                FromJsonUtilO(input[U("CustomIdInfo")], CustomIdInfo);
                FromJsonUtilO(input[U("FacebookInfo")], FacebookInfo);
                FromJsonUtilO(input[U("GameCenterInfo")], GameCenterInfo);
                FromJsonUtilO(input[U("GoogleInfo")], GoogleInfo);
                FromJsonUtilO(input[U("IosDeviceInfo")], IosDeviceInfo);
                FromJsonUtilO(input[U("KongregateInfo")], KongregateInfo);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilO(input[U("PrivateInfo")], PrivateInfo);
                FromJsonUtilO(input[U("PsnInfo")], PsnInfo);
                FromJsonUtilO(input[U("SteamInfo")], SteamInfo);
                FromJsonUtilO(input[U("TitleInfo")], TitleInfo);
                FromJsonUtilO(input[U("TwitchInfo")], TwitchInfo);
                FromJsonUtilS(input[U("Username")], Username);
                FromJsonUtilO(input[U("XboxInfo")], XboxInfo);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AndroidDeviceInfo; ToJsonUtilO(AndroidDeviceInfo, each_AndroidDeviceInfo); output[U("AndroidDeviceInfo")] = each_AndroidDeviceInfo;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[U("Created")] = each_Created;
                web::json::value each_CustomIdInfo; ToJsonUtilO(CustomIdInfo, each_CustomIdInfo); output[U("CustomIdInfo")] = each_CustomIdInfo;
                web::json::value each_FacebookInfo; ToJsonUtilO(FacebookInfo, each_FacebookInfo); output[U("FacebookInfo")] = each_FacebookInfo;
                web::json::value each_GameCenterInfo; ToJsonUtilO(GameCenterInfo, each_GameCenterInfo); output[U("GameCenterInfo")] = each_GameCenterInfo;
                web::json::value each_GoogleInfo; ToJsonUtilO(GoogleInfo, each_GoogleInfo); output[U("GoogleInfo")] = each_GoogleInfo;
                web::json::value each_IosDeviceInfo; ToJsonUtilO(IosDeviceInfo, each_IosDeviceInfo); output[U("IosDeviceInfo")] = each_IosDeviceInfo;
                web::json::value each_KongregateInfo; ToJsonUtilO(KongregateInfo, each_KongregateInfo); output[U("KongregateInfo")] = each_KongregateInfo;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_PrivateInfo; ToJsonUtilO(PrivateInfo, each_PrivateInfo); output[U("PrivateInfo")] = each_PrivateInfo;
                web::json::value each_PsnInfo; ToJsonUtilO(PsnInfo, each_PsnInfo); output[U("PsnInfo")] = each_PsnInfo;
                web::json::value each_SteamInfo; ToJsonUtilO(SteamInfo, each_SteamInfo); output[U("SteamInfo")] = each_SteamInfo;
                web::json::value each_TitleInfo; ToJsonUtilO(TitleInfo, each_TitleInfo); output[U("TitleInfo")] = each_TitleInfo;
                web::json::value each_TwitchInfo; ToJsonUtilO(TwitchInfo, each_TwitchInfo); output[U("TwitchInfo")] = each_TwitchInfo;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                web::json::value each_XboxInfo; ToJsonUtilO(XboxInfo, each_XboxInfo); output[U("XboxInfo")] = each_XboxInfo;
                return output;
            }
        };

        struct GetAccountInfoResult : public PlayFabResultCommon
        {
            Boxed<UserAccountInfo> AccountInfo;

            GetAccountInfoResult() :
                PlayFabResultCommon(),
                AccountInfo()
            {}

            GetAccountInfoResult(const GetAccountInfoResult& src) :
                PlayFabResultCommon(),
                AccountInfo(src.AccountInfo)
            {}

            ~GetAccountInfoResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("AccountInfo")], AccountInfo);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccountInfo; ToJsonUtilO(AccountInfo, each_AccountInfo); output[U("AccountInfo")] = each_AccountInfo;
                return output;
            }
        };

        struct GetCatalogItemsRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;

            GetCatalogItemsRequest() :
                PlayFabRequestCommon(),
                CatalogVersion()
            {}

            GetCatalogItemsRequest(const GetCatalogItemsRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion)
            {}

            ~GetCatalogItemsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                return output;
            }
        };

        struct GetCatalogItemsResult : public PlayFabResultCommon
        {
            std::list<CatalogItem> Catalog;

            GetCatalogItemsResult() :
                PlayFabResultCommon(),
                Catalog()
            {}

            GetCatalogItemsResult(const GetCatalogItemsResult& src) :
                PlayFabResultCommon(),
                Catalog(src.Catalog)
            {}

            ~GetCatalogItemsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Catalog")], Catalog);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Catalog; ToJsonUtilO(Catalog, each_Catalog); output[U("Catalog")] = each_Catalog;
                return output;
            }
        };

        struct GetCharacterDataRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            Boxed<Uint32> IfChangedFromDataVersion;
            std::list<std::string> Keys;
            std::string PlayFabId;

            GetCharacterDataRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                IfChangedFromDataVersion(),
                Keys(),
                PlayFabId()
            {}

            GetCharacterDataRequest(const GetCharacterDataRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId)
            {}

            ~GetCharacterDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilP(input[U("IfChangedFromDataVersion")], IfChangedFromDataVersion);
                FromJsonUtilS(input[U("Keys")], Keys);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_IfChangedFromDataVersion; ToJsonUtilP(IfChangedFromDataVersion, each_IfChangedFromDataVersion); output[U("IfChangedFromDataVersion")] = each_IfChangedFromDataVersion;
                web::json::value each_Keys; ToJsonUtilS(Keys, each_Keys); output[U("Keys")] = each_Keys;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct UserDataRecord : public PlayFabBaseModel
        {
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;
            std::string Value;

            UserDataRecord() :
                PlayFabBaseModel(),
                LastUpdated(),
                Permission(),
                Value()
            {}

            UserDataRecord(const UserDataRecord& src) :
                PlayFabBaseModel(),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission),
                Value(src.Value)
            {}

            ~UserDataRecord() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("LastUpdated")], LastUpdated);
                FromJsonUtilE(input[U("Permission")], Permission);
                FromJsonUtilS(input[U("Value")], Value);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LastUpdated; ToJsonUtilT(LastUpdated, each_LastUpdated); output[U("LastUpdated")] = each_LastUpdated;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[U("Permission")] = each_Permission;
                web::json::value each_Value; ToJsonUtilS(Value, each_Value); output[U("Value")] = each_Value;
                return output;
            }
        };

        struct GetCharacterDataResult : public PlayFabResultCommon
        {
            std::string CharacterId;
            std::map<std::string, UserDataRecord> Data;
            Uint32 DataVersion;

            GetCharacterDataResult() :
                PlayFabResultCommon(),
                CharacterId(),
                Data(),
                DataVersion()
            {}

            GetCharacterDataResult(const GetCharacterDataResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                DataVersion(src.DataVersion)
            {}

            ~GetCharacterDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilO(input[U("Data")], Data);
                FromJsonUtilP(input[U("DataVersion")], DataVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output[U("DataVersion")] = each_DataVersion;
                return output;
            }
        };

        struct GetCharacterInventoryRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;

            GetCharacterInventoryRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId()
            {}

            GetCharacterInventoryRequest(const GetCharacterInventoryRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId)
            {}

            ~GetCharacterInventoryRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                return output;
            }
        };

        struct VirtualCurrencyRechargeTime : public PlayFabBaseModel
        {
            Int32 RechargeMax;
            time_t RechargeTime;
            Int32 SecondsToRecharge;

            VirtualCurrencyRechargeTime() :
                PlayFabBaseModel(),
                RechargeMax(),
                RechargeTime(),
                SecondsToRecharge()
            {}

            VirtualCurrencyRechargeTime(const VirtualCurrencyRechargeTime& src) :
                PlayFabBaseModel(),
                RechargeMax(src.RechargeMax),
                RechargeTime(src.RechargeTime),
                SecondsToRecharge(src.SecondsToRecharge)
            {}

            ~VirtualCurrencyRechargeTime() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("RechargeMax")], RechargeMax);
                FromJsonUtilT(input[U("RechargeTime")], RechargeTime);
                FromJsonUtilP(input[U("SecondsToRecharge")], SecondsToRecharge);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_RechargeMax; ToJsonUtilP(RechargeMax, each_RechargeMax); output[U("RechargeMax")] = each_RechargeMax;
                web::json::value each_RechargeTime; ToJsonUtilT(RechargeTime, each_RechargeTime); output[U("RechargeTime")] = each_RechargeTime;
                web::json::value each_SecondsToRecharge; ToJsonUtilP(SecondsToRecharge, each_SecondsToRecharge); output[U("SecondsToRecharge")] = each_SecondsToRecharge;
                return output;
            }
        };

        struct GetCharacterInventoryResult : public PlayFabResultCommon
        {
            std::string CharacterId;
            std::list<ItemInstance> Inventory;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetCharacterInventoryResult() :
                PlayFabResultCommon(),
                CharacterId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetCharacterInventoryResult(const GetCharacterInventoryResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            ~GetCharacterInventoryResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilO(input[U("Inventory")], Inventory);
                FromJsonUtilP(input[U("VirtualCurrency")], VirtualCurrency);
                FromJsonUtilO(input[U("VirtualCurrencyRechargeTimes")], VirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[U("Inventory")] = each_Inventory;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                web::json::value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output[U("VirtualCurrencyRechargeTimes")] = each_VirtualCurrencyRechargeTimes;
                return output;
            }
        };

        struct GetCharacterLeaderboardRequest : public PlayFabRequestCommon
        {
            std::string CharacterType;
            Boxed<Int32> MaxResultsCount;
            Int32 StartPosition;
            std::string StatisticName;

            GetCharacterLeaderboardRequest() :
                PlayFabRequestCommon(),
                CharacterType(),
                MaxResultsCount(),
                StartPosition(),
                StatisticName()
            {}

            GetCharacterLeaderboardRequest(const GetCharacterLeaderboardRequest& src) :
                PlayFabRequestCommon(),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName)
            {}

            ~GetCharacterLeaderboardRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterType")], CharacterType);
                FromJsonUtilP(input[U("MaxResultsCount")], MaxResultsCount);
                FromJsonUtilP(input[U("StartPosition")], StartPosition);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[U("CharacterType")] = each_CharacterType;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[U("MaxResultsCount")] = each_MaxResultsCount;
                web::json::value each_StartPosition; ToJsonUtilP(StartPosition, each_StartPosition); output[U("StartPosition")] = each_StartPosition;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                return output;
            }
        };

        struct GetCharacterLeaderboardResult : public PlayFabResultCommon
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetCharacterLeaderboardResult() :
                PlayFabResultCommon(),
                Leaderboard()
            {}

            GetCharacterLeaderboardResult(const GetCharacterLeaderboardResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard)
            {}

            ~GetCharacterLeaderboardResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Leaderboard")], Leaderboard);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[U("Leaderboard")] = each_Leaderboard;
                return output;
            }
        };

        struct GetCharacterStatisticsRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;

            GetCharacterStatisticsRequest() :
                PlayFabRequestCommon(),
                CharacterId()
            {}

            GetCharacterStatisticsRequest(const GetCharacterStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId)
            {}

            ~GetCharacterStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                return output;
            }
        };

        struct GetCharacterStatisticsResult : public PlayFabResultCommon
        {
            std::map<std::string, Int32> CharacterStatistics;

            GetCharacterStatisticsResult() :
                PlayFabResultCommon(),
                CharacterStatistics()
            {}

            GetCharacterStatisticsResult(const GetCharacterStatisticsResult& src) :
                PlayFabResultCommon(),
                CharacterStatistics(src.CharacterStatistics)
            {}

            ~GetCharacterStatisticsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("CharacterStatistics")], CharacterStatistics);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterStatistics; ToJsonUtilP(CharacterStatistics, each_CharacterStatistics); output[U("CharacterStatistics")] = each_CharacterStatistics;
                return output;
            }
        };

        struct GetContentDownloadUrlRequest : public PlayFabRequestCommon
        {
            std::string HttpMethod;
            std::string Key;
            Boxed<bool> ThruCDN;

            GetContentDownloadUrlRequest() :
                PlayFabRequestCommon(),
                HttpMethod(),
                Key(),
                ThruCDN()
            {}

            GetContentDownloadUrlRequest(const GetContentDownloadUrlRequest& src) :
                PlayFabRequestCommon(),
                HttpMethod(src.HttpMethod),
                Key(src.Key),
                ThruCDN(src.ThruCDN)
            {}

            ~GetContentDownloadUrlRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("HttpMethod")], HttpMethod);
                FromJsonUtilS(input[U("Key")], Key);
                FromJsonUtilP(input[U("ThruCDN")], ThruCDN);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_HttpMethod; ToJsonUtilS(HttpMethod, each_HttpMethod); output[U("HttpMethod")] = each_HttpMethod;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[U("Key")] = each_Key;
                web::json::value each_ThruCDN; ToJsonUtilP(ThruCDN, each_ThruCDN); output[U("ThruCDN")] = each_ThruCDN;
                return output;
            }
        };

        struct GetContentDownloadUrlResult : public PlayFabResultCommon
        {
            std::string URL;

            GetContentDownloadUrlResult() :
                PlayFabResultCommon(),
                URL()
            {}

            GetContentDownloadUrlResult(const GetContentDownloadUrlResult& src) :
                PlayFabResultCommon(),
                URL(src.URL)
            {}

            ~GetContentDownloadUrlResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("URL")], URL);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_URL; ToJsonUtilS(URL, each_URL); output[U("URL")] = each_URL;
                return output;
            }
        };

        struct PlayerProfileViewConstraints : public PlayFabBaseModel
        {
            bool ShowAvatarUrl;
            bool ShowBannedUntil;
            bool ShowCampaignAttributions;
            bool ShowContactEmailAddresses;
            bool ShowCreated;
            bool ShowDisplayName;
            bool ShowLastLogin;
            bool ShowLinkedAccounts;
            bool ShowLocations;
            bool ShowMemberships;
            bool ShowOrigination;
            bool ShowPushNotificationRegistrations;
            bool ShowStatistics;
            bool ShowTags;
            bool ShowTotalValueToDateInUsd;
            bool ShowValuesToDate;

            PlayerProfileViewConstraints() :
                PlayFabBaseModel(),
                ShowAvatarUrl(),
                ShowBannedUntil(),
                ShowCampaignAttributions(),
                ShowContactEmailAddresses(),
                ShowCreated(),
                ShowDisplayName(),
                ShowLastLogin(),
                ShowLinkedAccounts(),
                ShowLocations(),
                ShowMemberships(),
                ShowOrigination(),
                ShowPushNotificationRegistrations(),
                ShowStatistics(),
                ShowTags(),
                ShowTotalValueToDateInUsd(),
                ShowValuesToDate()
            {}

            PlayerProfileViewConstraints(const PlayerProfileViewConstraints& src) :
                PlayFabBaseModel(),
                ShowAvatarUrl(src.ShowAvatarUrl),
                ShowBannedUntil(src.ShowBannedUntil),
                ShowCampaignAttributions(src.ShowCampaignAttributions),
                ShowContactEmailAddresses(src.ShowContactEmailAddresses),
                ShowCreated(src.ShowCreated),
                ShowDisplayName(src.ShowDisplayName),
                ShowLastLogin(src.ShowLastLogin),
                ShowLinkedAccounts(src.ShowLinkedAccounts),
                ShowLocations(src.ShowLocations),
                ShowMemberships(src.ShowMemberships),
                ShowOrigination(src.ShowOrigination),
                ShowPushNotificationRegistrations(src.ShowPushNotificationRegistrations),
                ShowStatistics(src.ShowStatistics),
                ShowTags(src.ShowTags),
                ShowTotalValueToDateInUsd(src.ShowTotalValueToDateInUsd),
                ShowValuesToDate(src.ShowValuesToDate)
            {}

            ~PlayerProfileViewConstraints() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("ShowAvatarUrl")], ShowAvatarUrl);
                FromJsonUtilP(input[U("ShowBannedUntil")], ShowBannedUntil);
                FromJsonUtilP(input[U("ShowCampaignAttributions")], ShowCampaignAttributions);
                FromJsonUtilP(input[U("ShowContactEmailAddresses")], ShowContactEmailAddresses);
                FromJsonUtilP(input[U("ShowCreated")], ShowCreated);
                FromJsonUtilP(input[U("ShowDisplayName")], ShowDisplayName);
                FromJsonUtilP(input[U("ShowLastLogin")], ShowLastLogin);
                FromJsonUtilP(input[U("ShowLinkedAccounts")], ShowLinkedAccounts);
                FromJsonUtilP(input[U("ShowLocations")], ShowLocations);
                FromJsonUtilP(input[U("ShowMemberships")], ShowMemberships);
                FromJsonUtilP(input[U("ShowOrigination")], ShowOrigination);
                FromJsonUtilP(input[U("ShowPushNotificationRegistrations")], ShowPushNotificationRegistrations);
                FromJsonUtilP(input[U("ShowStatistics")], ShowStatistics);
                FromJsonUtilP(input[U("ShowTags")], ShowTags);
                FromJsonUtilP(input[U("ShowTotalValueToDateInUsd")], ShowTotalValueToDateInUsd);
                FromJsonUtilP(input[U("ShowValuesToDate")], ShowValuesToDate);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ShowAvatarUrl; ToJsonUtilP(ShowAvatarUrl, each_ShowAvatarUrl); output[U("ShowAvatarUrl")] = each_ShowAvatarUrl;
                web::json::value each_ShowBannedUntil; ToJsonUtilP(ShowBannedUntil, each_ShowBannedUntil); output[U("ShowBannedUntil")] = each_ShowBannedUntil;
                web::json::value each_ShowCampaignAttributions; ToJsonUtilP(ShowCampaignAttributions, each_ShowCampaignAttributions); output[U("ShowCampaignAttributions")] = each_ShowCampaignAttributions;
                web::json::value each_ShowContactEmailAddresses; ToJsonUtilP(ShowContactEmailAddresses, each_ShowContactEmailAddresses); output[U("ShowContactEmailAddresses")] = each_ShowContactEmailAddresses;
                web::json::value each_ShowCreated; ToJsonUtilP(ShowCreated, each_ShowCreated); output[U("ShowCreated")] = each_ShowCreated;
                web::json::value each_ShowDisplayName; ToJsonUtilP(ShowDisplayName, each_ShowDisplayName); output[U("ShowDisplayName")] = each_ShowDisplayName;
                web::json::value each_ShowLastLogin; ToJsonUtilP(ShowLastLogin, each_ShowLastLogin); output[U("ShowLastLogin")] = each_ShowLastLogin;
                web::json::value each_ShowLinkedAccounts; ToJsonUtilP(ShowLinkedAccounts, each_ShowLinkedAccounts); output[U("ShowLinkedAccounts")] = each_ShowLinkedAccounts;
                web::json::value each_ShowLocations; ToJsonUtilP(ShowLocations, each_ShowLocations); output[U("ShowLocations")] = each_ShowLocations;
                web::json::value each_ShowMemberships; ToJsonUtilP(ShowMemberships, each_ShowMemberships); output[U("ShowMemberships")] = each_ShowMemberships;
                web::json::value each_ShowOrigination; ToJsonUtilP(ShowOrigination, each_ShowOrigination); output[U("ShowOrigination")] = each_ShowOrigination;
                web::json::value each_ShowPushNotificationRegistrations; ToJsonUtilP(ShowPushNotificationRegistrations, each_ShowPushNotificationRegistrations); output[U("ShowPushNotificationRegistrations")] = each_ShowPushNotificationRegistrations;
                web::json::value each_ShowStatistics; ToJsonUtilP(ShowStatistics, each_ShowStatistics); output[U("ShowStatistics")] = each_ShowStatistics;
                web::json::value each_ShowTags; ToJsonUtilP(ShowTags, each_ShowTags); output[U("ShowTags")] = each_ShowTags;
                web::json::value each_ShowTotalValueToDateInUsd; ToJsonUtilP(ShowTotalValueToDateInUsd, each_ShowTotalValueToDateInUsd); output[U("ShowTotalValueToDateInUsd")] = each_ShowTotalValueToDateInUsd;
                web::json::value each_ShowValuesToDate; ToJsonUtilP(ShowValuesToDate, each_ShowValuesToDate); output[U("ShowValuesToDate")] = each_ShowValuesToDate;
                return output;
            }
        };

        struct GetFriendLeaderboardAroundPlayerRequest : public PlayFabRequestCommon
        {
            Boxed<bool> IncludeFacebookFriends;
            Boxed<bool> IncludeSteamFriends;
            Boxed<Int32> MaxResultsCount;
            std::string PlayFabId;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            std::string StatisticName;
            Boxed<Int32> Version;

            GetFriendLeaderboardAroundPlayerRequest() :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                MaxResultsCount(),
                PlayFabId(),
                ProfileConstraints(),
                StatisticName(),
                Version()
            {}

            GetFriendLeaderboardAroundPlayerRequest(const GetFriendLeaderboardAroundPlayerRequest& src) :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~GetFriendLeaderboardAroundPlayerRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("IncludeFacebookFriends")], IncludeFacebookFriends);
                FromJsonUtilP(input[U("IncludeSteamFriends")], IncludeSteamFriends);
                FromJsonUtilP(input[U("MaxResultsCount")], MaxResultsCount);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilO(input[U("ProfileConstraints")], ProfileConstraints);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IncludeFacebookFriends; ToJsonUtilP(IncludeFacebookFriends, each_IncludeFacebookFriends); output[U("IncludeFacebookFriends")] = each_IncludeFacebookFriends;
                web::json::value each_IncludeSteamFriends; ToJsonUtilP(IncludeSteamFriends, each_IncludeSteamFriends); output[U("IncludeSteamFriends")] = each_IncludeSteamFriends;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[U("MaxResultsCount")] = each_MaxResultsCount;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[U("ProfileConstraints")] = each_ProfileConstraints;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct PlayerLeaderboardEntry : public PlayFabBaseModel
        {
            std::string DisplayName;
            std::string PlayFabId;
            Int32 Position;
            Boxed<PlayerProfileModel> Profile;
            Int32 StatValue;

            PlayerLeaderboardEntry() :
                PlayFabBaseModel(),
                DisplayName(),
                PlayFabId(),
                Position(),
                Profile(),
                StatValue()
            {}

            PlayerLeaderboardEntry(const PlayerLeaderboardEntry& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId),
                Position(src.Position),
                Profile(src.Profile),
                StatValue(src.StatValue)
            {}

            ~PlayerLeaderboardEntry() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilP(input[U("Position")], Position);
                FromJsonUtilO(input[U("Profile")], Profile);
                FromJsonUtilP(input[U("StatValue")], StatValue);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Position; ToJsonUtilP(Position, each_Position); output[U("Position")] = each_Position;
                web::json::value each_Profile; ToJsonUtilO(Profile, each_Profile); output[U("Profile")] = each_Profile;
                web::json::value each_StatValue; ToJsonUtilP(StatValue, each_StatValue); output[U("StatValue")] = each_StatValue;
                return output;
            }
        };

        struct GetFriendLeaderboardAroundPlayerResult : public PlayFabResultCommon
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            Boxed<time_t> NextReset;
            Int32 Version;

            GetFriendLeaderboardAroundPlayerResult() :
                PlayFabResultCommon(),
                Leaderboard(),
                NextReset(),
                Version()
            {}

            GetFriendLeaderboardAroundPlayerResult(const GetFriendLeaderboardAroundPlayerResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            ~GetFriendLeaderboardAroundPlayerResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Leaderboard")], Leaderboard);
                FromJsonUtilT(input[U("NextReset")], NextReset);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[U("Leaderboard")] = each_Leaderboard;
                web::json::value each_NextReset; ToJsonUtilT(NextReset, each_NextReset); output[U("NextReset")] = each_NextReset;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetFriendLeaderboardRequest : public PlayFabRequestCommon
        {
            Boxed<bool> IncludeFacebookFriends;
            Boxed<bool> IncludeSteamFriends;
            Boxed<Int32> MaxResultsCount;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            Int32 StartPosition;
            std::string StatisticName;
            Boxed<Int32> Version;

            GetFriendLeaderboardRequest() :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                MaxResultsCount(),
                ProfileConstraints(),
                StartPosition(),
                StatisticName(),
                Version()
            {}

            GetFriendLeaderboardRequest(const GetFriendLeaderboardRequest& src) :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~GetFriendLeaderboardRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("IncludeFacebookFriends")], IncludeFacebookFriends);
                FromJsonUtilP(input[U("IncludeSteamFriends")], IncludeSteamFriends);
                FromJsonUtilP(input[U("MaxResultsCount")], MaxResultsCount);
                FromJsonUtilO(input[U("ProfileConstraints")], ProfileConstraints);
                FromJsonUtilP(input[U("StartPosition")], StartPosition);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IncludeFacebookFriends; ToJsonUtilP(IncludeFacebookFriends, each_IncludeFacebookFriends); output[U("IncludeFacebookFriends")] = each_IncludeFacebookFriends;
                web::json::value each_IncludeSteamFriends; ToJsonUtilP(IncludeSteamFriends, each_IncludeSteamFriends); output[U("IncludeSteamFriends")] = each_IncludeSteamFriends;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[U("MaxResultsCount")] = each_MaxResultsCount;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[U("ProfileConstraints")] = each_ProfileConstraints;
                web::json::value each_StartPosition; ToJsonUtilP(StartPosition, each_StartPosition); output[U("StartPosition")] = each_StartPosition;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetFriendsListRequest : public PlayFabRequestCommon
        {
            Boxed<bool> IncludeFacebookFriends;
            Boxed<bool> IncludeSteamFriends;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;

            GetFriendsListRequest() :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                ProfileConstraints()
            {}

            GetFriendsListRequest(const GetFriendsListRequest& src) :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                ProfileConstraints(src.ProfileConstraints)
            {}

            ~GetFriendsListRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("IncludeFacebookFriends")], IncludeFacebookFriends);
                FromJsonUtilP(input[U("IncludeSteamFriends")], IncludeSteamFriends);
                FromJsonUtilO(input[U("ProfileConstraints")], ProfileConstraints);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IncludeFacebookFriends; ToJsonUtilP(IncludeFacebookFriends, each_IncludeFacebookFriends); output[U("IncludeFacebookFriends")] = each_IncludeFacebookFriends;
                web::json::value each_IncludeSteamFriends; ToJsonUtilP(IncludeSteamFriends, each_IncludeSteamFriends); output[U("IncludeSteamFriends")] = each_IncludeSteamFriends;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[U("ProfileConstraints")] = each_ProfileConstraints;
                return output;
            }
        };

        struct GetFriendsListResult : public PlayFabResultCommon
        {
            std::list<FriendInfo> Friends;

            GetFriendsListResult() :
                PlayFabResultCommon(),
                Friends()
            {}

            GetFriendsListResult(const GetFriendsListResult& src) :
                PlayFabResultCommon(),
                Friends(src.Friends)
            {}

            ~GetFriendsListResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Friends")], Friends);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Friends; ToJsonUtilO(Friends, each_Friends); output[U("Friends")] = each_Friends;
                return output;
            }
        };

        struct GetLeaderboardAroundCharacterRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::string CharacterType;
            Boxed<Int32> MaxResultsCount;
            std::string StatisticName;

            GetLeaderboardAroundCharacterRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount(),
                StatisticName()
            {}

            GetLeaderboardAroundCharacterRequest(const GetLeaderboardAroundCharacterRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                StatisticName(src.StatisticName)
            {}

            ~GetLeaderboardAroundCharacterRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("CharacterType")], CharacterType);
                FromJsonUtilP(input[U("MaxResultsCount")], MaxResultsCount);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[U("CharacterType")] = each_CharacterType;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[U("MaxResultsCount")] = each_MaxResultsCount;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                return output;
            }
        };

        struct GetLeaderboardAroundCharacterResult : public PlayFabResultCommon
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetLeaderboardAroundCharacterResult() :
                PlayFabResultCommon(),
                Leaderboard()
            {}

            GetLeaderboardAroundCharacterResult(const GetLeaderboardAroundCharacterResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard)
            {}

            ~GetLeaderboardAroundCharacterResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Leaderboard")], Leaderboard);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[U("Leaderboard")] = each_Leaderboard;
                return output;
            }
        };

        struct GetLeaderboardAroundPlayerRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> MaxResultsCount;
            std::string PlayFabId;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            std::string StatisticName;
            Boxed<Int32> Version;

            GetLeaderboardAroundPlayerRequest() :
                PlayFabRequestCommon(),
                MaxResultsCount(),
                PlayFabId(),
                ProfileConstraints(),
                StatisticName(),
                Version()
            {}

            GetLeaderboardAroundPlayerRequest(const GetLeaderboardAroundPlayerRequest& src) :
                PlayFabRequestCommon(),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~GetLeaderboardAroundPlayerRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("MaxResultsCount")], MaxResultsCount);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilO(input[U("ProfileConstraints")], ProfileConstraints);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[U("MaxResultsCount")] = each_MaxResultsCount;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[U("ProfileConstraints")] = each_ProfileConstraints;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetLeaderboardAroundPlayerResult : public PlayFabResultCommon
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            Boxed<time_t> NextReset;
            Int32 Version;

            GetLeaderboardAroundPlayerResult() :
                PlayFabResultCommon(),
                Leaderboard(),
                NextReset(),
                Version()
            {}

            GetLeaderboardAroundPlayerResult(const GetLeaderboardAroundPlayerResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            ~GetLeaderboardAroundPlayerResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Leaderboard")], Leaderboard);
                FromJsonUtilT(input[U("NextReset")], NextReset);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[U("Leaderboard")] = each_Leaderboard;
                web::json::value each_NextReset; ToJsonUtilT(NextReset, each_NextReset); output[U("NextReset")] = each_NextReset;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetLeaderboardForUsersCharactersRequest : public PlayFabRequestCommon
        {
            Int32 MaxResultsCount;
            std::string StatisticName;

            GetLeaderboardForUsersCharactersRequest() :
                PlayFabRequestCommon(),
                MaxResultsCount(),
                StatisticName()
            {}

            GetLeaderboardForUsersCharactersRequest(const GetLeaderboardForUsersCharactersRequest& src) :
                PlayFabRequestCommon(),
                MaxResultsCount(src.MaxResultsCount),
                StatisticName(src.StatisticName)
            {}

            ~GetLeaderboardForUsersCharactersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("MaxResultsCount")], MaxResultsCount);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[U("MaxResultsCount")] = each_MaxResultsCount;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                return output;
            }
        };

        struct GetLeaderboardForUsersCharactersResult : public PlayFabResultCommon
        {
            std::list<CharacterLeaderboardEntry> Leaderboard;

            GetLeaderboardForUsersCharactersResult() :
                PlayFabResultCommon(),
                Leaderboard()
            {}

            GetLeaderboardForUsersCharactersResult(const GetLeaderboardForUsersCharactersResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard)
            {}

            ~GetLeaderboardForUsersCharactersResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Leaderboard")], Leaderboard);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[U("Leaderboard")] = each_Leaderboard;
                return output;
            }
        };

        struct GetLeaderboardRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> MaxResultsCount;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            Int32 StartPosition;
            std::string StatisticName;
            Boxed<Int32> Version;

            GetLeaderboardRequest() :
                PlayFabRequestCommon(),
                MaxResultsCount(),
                ProfileConstraints(),
                StartPosition(),
                StatisticName(),
                Version()
            {}

            GetLeaderboardRequest(const GetLeaderboardRequest& src) :
                PlayFabRequestCommon(),
                MaxResultsCount(src.MaxResultsCount),
                ProfileConstraints(src.ProfileConstraints),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~GetLeaderboardRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("MaxResultsCount")], MaxResultsCount);
                FromJsonUtilO(input[U("ProfileConstraints")], ProfileConstraints);
                FromJsonUtilP(input[U("StartPosition")], StartPosition);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[U("MaxResultsCount")] = each_MaxResultsCount;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[U("ProfileConstraints")] = each_ProfileConstraints;
                web::json::value each_StartPosition; ToJsonUtilP(StartPosition, each_StartPosition); output[U("StartPosition")] = each_StartPosition;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetLeaderboardResult : public PlayFabResultCommon
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            Boxed<time_t> NextReset;
            Int32 Version;

            GetLeaderboardResult() :
                PlayFabResultCommon(),
                Leaderboard(),
                NextReset(),
                Version()
            {}

            GetLeaderboardResult(const GetLeaderboardResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            ~GetLeaderboardResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Leaderboard")], Leaderboard);
                FromJsonUtilT(input[U("NextReset")], NextReset);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Leaderboard; ToJsonUtilO(Leaderboard, each_Leaderboard); output[U("Leaderboard")] = each_Leaderboard;
                web::json::value each_NextReset; ToJsonUtilT(NextReset, each_NextReset); output[U("NextReset")] = each_NextReset;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetPaymentTokenRequest : public PlayFabRequestCommon
        {
            std::string TokenProvider;

            GetPaymentTokenRequest() :
                PlayFabRequestCommon(),
                TokenProvider()
            {}

            GetPaymentTokenRequest(const GetPaymentTokenRequest& src) :
                PlayFabRequestCommon(),
                TokenProvider(src.TokenProvider)
            {}

            ~GetPaymentTokenRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("TokenProvider")], TokenProvider);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TokenProvider; ToJsonUtilS(TokenProvider, each_TokenProvider); output[U("TokenProvider")] = each_TokenProvider;
                return output;
            }
        };

        struct GetPaymentTokenResult : public PlayFabResultCommon
        {
            std::string OrderId;
            std::string ProviderToken;

            GetPaymentTokenResult() :
                PlayFabResultCommon(),
                OrderId(),
                ProviderToken()
            {}

            GetPaymentTokenResult(const GetPaymentTokenResult& src) :
                PlayFabResultCommon(),
                OrderId(src.OrderId),
                ProviderToken(src.ProviderToken)
            {}

            ~GetPaymentTokenResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("OrderId")], OrderId);
                FromJsonUtilS(input[U("ProviderToken")], ProviderToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[U("OrderId")] = each_OrderId;
                web::json::value each_ProviderToken; ToJsonUtilS(ProviderToken, each_ProviderToken); output[U("ProviderToken")] = each_ProviderToken;
                return output;
            }
        };

        struct GetPhotonAuthenticationTokenRequest : public PlayFabRequestCommon
        {
            std::string PhotonApplicationId;

            GetPhotonAuthenticationTokenRequest() :
                PlayFabRequestCommon(),
                PhotonApplicationId()
            {}

            GetPhotonAuthenticationTokenRequest(const GetPhotonAuthenticationTokenRequest& src) :
                PlayFabRequestCommon(),
                PhotonApplicationId(src.PhotonApplicationId)
            {}

            ~GetPhotonAuthenticationTokenRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PhotonApplicationId")], PhotonApplicationId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PhotonApplicationId; ToJsonUtilS(PhotonApplicationId, each_PhotonApplicationId); output[U("PhotonApplicationId")] = each_PhotonApplicationId;
                return output;
            }
        };

        struct GetPhotonAuthenticationTokenResult : public PlayFabResultCommon
        {
            std::string PhotonCustomAuthenticationToken;

            GetPhotonAuthenticationTokenResult() :
                PlayFabResultCommon(),
                PhotonCustomAuthenticationToken()
            {}

            GetPhotonAuthenticationTokenResult(const GetPhotonAuthenticationTokenResult& src) :
                PlayFabResultCommon(),
                PhotonCustomAuthenticationToken(src.PhotonCustomAuthenticationToken)
            {}

            ~GetPhotonAuthenticationTokenResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PhotonCustomAuthenticationToken")], PhotonCustomAuthenticationToken);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PhotonCustomAuthenticationToken; ToJsonUtilS(PhotonCustomAuthenticationToken, each_PhotonCustomAuthenticationToken); output[U("PhotonCustomAuthenticationToken")] = each_PhotonCustomAuthenticationToken;
                return output;
            }
        };

        struct GetPlayerCombinedInfoRequestParams : public PlayFabBaseModel
        {
            bool GetCharacterInventories;
            bool GetCharacterList;
            bool GetPlayerProfile;
            bool GetPlayerStatistics;
            bool GetTitleData;
            bool GetUserAccountInfo;
            bool GetUserData;
            bool GetUserInventory;
            bool GetUserReadOnlyData;
            bool GetUserVirtualCurrency;
            std::list<std::string> PlayerStatisticNames;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            std::list<std::string> TitleDataKeys;
            std::list<std::string> UserDataKeys;
            std::list<std::string> UserReadOnlyDataKeys;

            GetPlayerCombinedInfoRequestParams() :
                PlayFabBaseModel(),
                GetCharacterInventories(),
                GetCharacterList(),
                GetPlayerProfile(),
                GetPlayerStatistics(),
                GetTitleData(),
                GetUserAccountInfo(),
                GetUserData(),
                GetUserInventory(),
                GetUserReadOnlyData(),
                GetUserVirtualCurrency(),
                PlayerStatisticNames(),
                ProfileConstraints(),
                TitleDataKeys(),
                UserDataKeys(),
                UserReadOnlyDataKeys()
            {}

            GetPlayerCombinedInfoRequestParams(const GetPlayerCombinedInfoRequestParams& src) :
                PlayFabBaseModel(),
                GetCharacterInventories(src.GetCharacterInventories),
                GetCharacterList(src.GetCharacterList),
                GetPlayerProfile(src.GetPlayerProfile),
                GetPlayerStatistics(src.GetPlayerStatistics),
                GetTitleData(src.GetTitleData),
                GetUserAccountInfo(src.GetUserAccountInfo),
                GetUserData(src.GetUserData),
                GetUserInventory(src.GetUserInventory),
                GetUserReadOnlyData(src.GetUserReadOnlyData),
                GetUserVirtualCurrency(src.GetUserVirtualCurrency),
                PlayerStatisticNames(src.PlayerStatisticNames),
                ProfileConstraints(src.ProfileConstraints),
                TitleDataKeys(src.TitleDataKeys),
                UserDataKeys(src.UserDataKeys),
                UserReadOnlyDataKeys(src.UserReadOnlyDataKeys)
            {}

            ~GetPlayerCombinedInfoRequestParams() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("GetCharacterInventories")], GetCharacterInventories);
                FromJsonUtilP(input[U("GetCharacterList")], GetCharacterList);
                FromJsonUtilP(input[U("GetPlayerProfile")], GetPlayerProfile);
                FromJsonUtilP(input[U("GetPlayerStatistics")], GetPlayerStatistics);
                FromJsonUtilP(input[U("GetTitleData")], GetTitleData);
                FromJsonUtilP(input[U("GetUserAccountInfo")], GetUserAccountInfo);
                FromJsonUtilP(input[U("GetUserData")], GetUserData);
                FromJsonUtilP(input[U("GetUserInventory")], GetUserInventory);
                FromJsonUtilP(input[U("GetUserReadOnlyData")], GetUserReadOnlyData);
                FromJsonUtilP(input[U("GetUserVirtualCurrency")], GetUserVirtualCurrency);
                FromJsonUtilS(input[U("PlayerStatisticNames")], PlayerStatisticNames);
                FromJsonUtilO(input[U("ProfileConstraints")], ProfileConstraints);
                FromJsonUtilS(input[U("TitleDataKeys")], TitleDataKeys);
                FromJsonUtilS(input[U("UserDataKeys")], UserDataKeys);
                FromJsonUtilS(input[U("UserReadOnlyDataKeys")], UserReadOnlyDataKeys);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GetCharacterInventories; ToJsonUtilP(GetCharacterInventories, each_GetCharacterInventories); output[U("GetCharacterInventories")] = each_GetCharacterInventories;
                web::json::value each_GetCharacterList; ToJsonUtilP(GetCharacterList, each_GetCharacterList); output[U("GetCharacterList")] = each_GetCharacterList;
                web::json::value each_GetPlayerProfile; ToJsonUtilP(GetPlayerProfile, each_GetPlayerProfile); output[U("GetPlayerProfile")] = each_GetPlayerProfile;
                web::json::value each_GetPlayerStatistics; ToJsonUtilP(GetPlayerStatistics, each_GetPlayerStatistics); output[U("GetPlayerStatistics")] = each_GetPlayerStatistics;
                web::json::value each_GetTitleData; ToJsonUtilP(GetTitleData, each_GetTitleData); output[U("GetTitleData")] = each_GetTitleData;
                web::json::value each_GetUserAccountInfo; ToJsonUtilP(GetUserAccountInfo, each_GetUserAccountInfo); output[U("GetUserAccountInfo")] = each_GetUserAccountInfo;
                web::json::value each_GetUserData; ToJsonUtilP(GetUserData, each_GetUserData); output[U("GetUserData")] = each_GetUserData;
                web::json::value each_GetUserInventory; ToJsonUtilP(GetUserInventory, each_GetUserInventory); output[U("GetUserInventory")] = each_GetUserInventory;
                web::json::value each_GetUserReadOnlyData; ToJsonUtilP(GetUserReadOnlyData, each_GetUserReadOnlyData); output[U("GetUserReadOnlyData")] = each_GetUserReadOnlyData;
                web::json::value each_GetUserVirtualCurrency; ToJsonUtilP(GetUserVirtualCurrency, each_GetUserVirtualCurrency); output[U("GetUserVirtualCurrency")] = each_GetUserVirtualCurrency;
                web::json::value each_PlayerStatisticNames; ToJsonUtilS(PlayerStatisticNames, each_PlayerStatisticNames); output[U("PlayerStatisticNames")] = each_PlayerStatisticNames;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[U("ProfileConstraints")] = each_ProfileConstraints;
                web::json::value each_TitleDataKeys; ToJsonUtilS(TitleDataKeys, each_TitleDataKeys); output[U("TitleDataKeys")] = each_TitleDataKeys;
                web::json::value each_UserDataKeys; ToJsonUtilS(UserDataKeys, each_UserDataKeys); output[U("UserDataKeys")] = each_UserDataKeys;
                web::json::value each_UserReadOnlyDataKeys; ToJsonUtilS(UserReadOnlyDataKeys, each_UserReadOnlyDataKeys); output[U("UserReadOnlyDataKeys")] = each_UserReadOnlyDataKeys;
                return output;
            }
        };

        struct GetPlayerCombinedInfoRequest : public PlayFabRequestCommon
        {
            GetPlayerCombinedInfoRequestParams InfoRequestParameters;
            std::string PlayFabId;

            GetPlayerCombinedInfoRequest() :
                PlayFabRequestCommon(),
                InfoRequestParameters(),
                PlayFabId()
            {}

            GetPlayerCombinedInfoRequest(const GetPlayerCombinedInfoRequest& src) :
                PlayFabRequestCommon(),
                InfoRequestParameters(src.InfoRequestParameters),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayerCombinedInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct StatisticValue : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 Value;
            Uint32 Version;

            StatisticValue() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(),
                Version()
            {}

            StatisticValue(const StatisticValue& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            ~StatisticValue() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilP(input[U("Value")], Value);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_Value; ToJsonUtilP(Value, each_Value); output[U("Value")] = each_Value;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetPlayerCombinedInfoResultPayload : public PlayFabBaseModel
        {
            Boxed<UserAccountInfo> AccountInfo;
            std::list<CharacterInventory> CharacterInventories;
            std::list<CharacterResult> CharacterList;
            Boxed<PlayerProfileModel> PlayerProfile;
            std::list<StatisticValue> PlayerStatistics;
            std::map<std::string, std::string> TitleData;
            std::map<std::string, UserDataRecord> UserData;
            Uint32 UserDataVersion;
            std::list<ItemInstance> UserInventory;
            std::map<std::string, UserDataRecord> UserReadOnlyData;
            Uint32 UserReadOnlyDataVersion;
            std::map<std::string, Int32> UserVirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> UserVirtualCurrencyRechargeTimes;

            GetPlayerCombinedInfoResultPayload() :
                PlayFabBaseModel(),
                AccountInfo(),
                CharacterInventories(),
                CharacterList(),
                PlayerProfile(),
                PlayerStatistics(),
                TitleData(),
                UserData(),
                UserDataVersion(),
                UserInventory(),
                UserReadOnlyData(),
                UserReadOnlyDataVersion(),
                UserVirtualCurrency(),
                UserVirtualCurrencyRechargeTimes()
            {}

            GetPlayerCombinedInfoResultPayload(const GetPlayerCombinedInfoResultPayload& src) :
                PlayFabBaseModel(),
                AccountInfo(src.AccountInfo),
                CharacterInventories(src.CharacterInventories),
                CharacterList(src.CharacterList),
                PlayerProfile(src.PlayerProfile),
                PlayerStatistics(src.PlayerStatistics),
                TitleData(src.TitleData),
                UserData(src.UserData),
                UserDataVersion(src.UserDataVersion),
                UserInventory(src.UserInventory),
                UserReadOnlyData(src.UserReadOnlyData),
                UserReadOnlyDataVersion(src.UserReadOnlyDataVersion),
                UserVirtualCurrency(src.UserVirtualCurrency),
                UserVirtualCurrencyRechargeTimes(src.UserVirtualCurrencyRechargeTimes)
            {}

            ~GetPlayerCombinedInfoResultPayload() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("AccountInfo")], AccountInfo);
                FromJsonUtilO(input[U("CharacterInventories")], CharacterInventories);
                FromJsonUtilO(input[U("CharacterList")], CharacterList);
                FromJsonUtilO(input[U("PlayerProfile")], PlayerProfile);
                FromJsonUtilO(input[U("PlayerStatistics")], PlayerStatistics);
                FromJsonUtilS(input[U("TitleData")], TitleData);
                FromJsonUtilO(input[U("UserData")], UserData);
                FromJsonUtilP(input[U("UserDataVersion")], UserDataVersion);
                FromJsonUtilO(input[U("UserInventory")], UserInventory);
                FromJsonUtilO(input[U("UserReadOnlyData")], UserReadOnlyData);
                FromJsonUtilP(input[U("UserReadOnlyDataVersion")], UserReadOnlyDataVersion);
                FromJsonUtilP(input[U("UserVirtualCurrency")], UserVirtualCurrency);
                FromJsonUtilO(input[U("UserVirtualCurrencyRechargeTimes")], UserVirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccountInfo; ToJsonUtilO(AccountInfo, each_AccountInfo); output[U("AccountInfo")] = each_AccountInfo;
                web::json::value each_CharacterInventories; ToJsonUtilO(CharacterInventories, each_CharacterInventories); output[U("CharacterInventories")] = each_CharacterInventories;
                web::json::value each_CharacterList; ToJsonUtilO(CharacterList, each_CharacterList); output[U("CharacterList")] = each_CharacterList;
                web::json::value each_PlayerProfile; ToJsonUtilO(PlayerProfile, each_PlayerProfile); output[U("PlayerProfile")] = each_PlayerProfile;
                web::json::value each_PlayerStatistics; ToJsonUtilO(PlayerStatistics, each_PlayerStatistics); output[U("PlayerStatistics")] = each_PlayerStatistics;
                web::json::value each_TitleData; ToJsonUtilS(TitleData, each_TitleData); output[U("TitleData")] = each_TitleData;
                web::json::value each_UserData; ToJsonUtilO(UserData, each_UserData); output[U("UserData")] = each_UserData;
                web::json::value each_UserDataVersion; ToJsonUtilP(UserDataVersion, each_UserDataVersion); output[U("UserDataVersion")] = each_UserDataVersion;
                web::json::value each_UserInventory; ToJsonUtilO(UserInventory, each_UserInventory); output[U("UserInventory")] = each_UserInventory;
                web::json::value each_UserReadOnlyData; ToJsonUtilO(UserReadOnlyData, each_UserReadOnlyData); output[U("UserReadOnlyData")] = each_UserReadOnlyData;
                web::json::value each_UserReadOnlyDataVersion; ToJsonUtilP(UserReadOnlyDataVersion, each_UserReadOnlyDataVersion); output[U("UserReadOnlyDataVersion")] = each_UserReadOnlyDataVersion;
                web::json::value each_UserVirtualCurrency; ToJsonUtilP(UserVirtualCurrency, each_UserVirtualCurrency); output[U("UserVirtualCurrency")] = each_UserVirtualCurrency;
                web::json::value each_UserVirtualCurrencyRechargeTimes; ToJsonUtilO(UserVirtualCurrencyRechargeTimes, each_UserVirtualCurrencyRechargeTimes); output[U("UserVirtualCurrencyRechargeTimes")] = each_UserVirtualCurrencyRechargeTimes;
                return output;
            }
        };

        struct GetPlayerCombinedInfoResult : public PlayFabResultCommon
        {
            Boxed<GetPlayerCombinedInfoResultPayload> InfoResultPayload;
            std::string PlayFabId;

            GetPlayerCombinedInfoResult() :
                PlayFabResultCommon(),
                InfoResultPayload(),
                PlayFabId()
            {}

            GetPlayerCombinedInfoResult(const GetPlayerCombinedInfoResult& src) :
                PlayFabResultCommon(),
                InfoResultPayload(src.InfoResultPayload),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayerCombinedInfoResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("InfoResultPayload")], InfoResultPayload);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_InfoResultPayload; ToJsonUtilO(InfoResultPayload, each_InfoResultPayload); output[U("InfoResultPayload")] = each_InfoResultPayload;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GetPlayerProfileRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;

            GetPlayerProfileRequest() :
                PlayFabRequestCommon(),
                PlayFabId(),
                ProfileConstraints()
            {}

            GetPlayerProfileRequest(const GetPlayerProfileRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints)
            {}

            ~GetPlayerProfileRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilO(input[U("ProfileConstraints")], ProfileConstraints);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_ProfileConstraints; ToJsonUtilO(ProfileConstraints, each_ProfileConstraints); output[U("ProfileConstraints")] = each_ProfileConstraints;
                return output;
            }
        };

        struct GetPlayerProfileResult : public PlayFabResultCommon
        {
            Boxed<PlayerProfileModel> PlayerProfile;

            GetPlayerProfileResult() :
                PlayFabResultCommon(),
                PlayerProfile()
            {}

            GetPlayerProfileResult(const GetPlayerProfileResult& src) :
                PlayFabResultCommon(),
                PlayerProfile(src.PlayerProfile)
            {}

            ~GetPlayerProfileResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("PlayerProfile")], PlayerProfile);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayerProfile; ToJsonUtilO(PlayerProfile, each_PlayerProfile); output[U("PlayerProfile")] = each_PlayerProfile;
                return output;
            }
        };

        struct GetPlayerSegmentsRequest : public PlayFabRequestCommon
        {

            GetPlayerSegmentsRequest() :
                PlayFabRequestCommon()
            {}

            GetPlayerSegmentsRequest(const GetPlayerSegmentsRequest& src) :
                PlayFabRequestCommon()
            {}

            ~GetPlayerSegmentsRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetSegmentResult : public PlayFabResultCommon
        {
            std::string ABTestParent;
            std::string Id;
            std::string Name;

            GetSegmentResult() :
                PlayFabResultCommon(),
                ABTestParent(),
                Id(),
                Name()
            {}

            GetSegmentResult(const GetSegmentResult& src) :
                PlayFabResultCommon(),
                ABTestParent(src.ABTestParent),
                Id(src.Id),
                Name(src.Name)
            {}

            ~GetSegmentResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ABTestParent")], ABTestParent);
                FromJsonUtilS(input[U("Id")], Id);
                FromJsonUtilS(input[U("Name")], Name);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ABTestParent; ToJsonUtilS(ABTestParent, each_ABTestParent); output[U("ABTestParent")] = each_ABTestParent;
                web::json::value each_Id; ToJsonUtilS(Id, each_Id); output[U("Id")] = each_Id;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                return output;
            }
        };

        struct GetPlayerSegmentsResult : public PlayFabResultCommon
        {
            std::list<GetSegmentResult> Segments;

            GetPlayerSegmentsResult() :
                PlayFabResultCommon(),
                Segments()
            {}

            GetPlayerSegmentsResult(const GetPlayerSegmentsResult& src) :
                PlayFabResultCommon(),
                Segments(src.Segments)
            {}

            ~GetPlayerSegmentsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Segments")], Segments);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Segments; ToJsonUtilO(Segments, each_Segments); output[U("Segments")] = each_Segments;
                return output;
            }
        };

        struct StatisticNameVersion : public PlayFabBaseModel
        {
            std::string StatisticName;
            Uint32 Version;

            StatisticNameVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version()
            {}

            StatisticNameVersion(const StatisticNameVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~StatisticNameVersion() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetPlayerStatisticsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> StatisticNames;
            std::list<StatisticNameVersion> StatisticNameVersions;

            GetPlayerStatisticsRequest() :
                PlayFabRequestCommon(),
                StatisticNames(),
                StatisticNameVersions()
            {}

            GetPlayerStatisticsRequest(const GetPlayerStatisticsRequest& src) :
                PlayFabRequestCommon(),
                StatisticNames(src.StatisticNames),
                StatisticNameVersions(src.StatisticNameVersions)
            {}

            ~GetPlayerStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("StatisticNames")], StatisticNames);
                FromJsonUtilO(input[U("StatisticNameVersions")], StatisticNameVersions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticNames; ToJsonUtilS(StatisticNames, each_StatisticNames); output[U("StatisticNames")] = each_StatisticNames;
                web::json::value each_StatisticNameVersions; ToJsonUtilO(StatisticNameVersions, each_StatisticNameVersions); output[U("StatisticNameVersions")] = each_StatisticNameVersions;
                return output;
            }
        };

        struct GetPlayerStatisticsResult : public PlayFabResultCommon
        {
            std::list<StatisticValue> Statistics;

            GetPlayerStatisticsResult() :
                PlayFabResultCommon(),
                Statistics()
            {}

            GetPlayerStatisticsResult(const GetPlayerStatisticsResult& src) :
                PlayFabResultCommon(),
                Statistics(src.Statistics)
            {}

            ~GetPlayerStatisticsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Statistics")], Statistics);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output[U("Statistics")] = each_Statistics;
                return output;
            }
        };

        struct GetPlayerStatisticVersionsRequest : public PlayFabRequestCommon
        {
            std::string StatisticName;

            GetPlayerStatisticVersionsRequest() :
                PlayFabRequestCommon(),
                StatisticName()
            {}

            GetPlayerStatisticVersionsRequest(const GetPlayerStatisticVersionsRequest& src) :
                PlayFabRequestCommon(),
                StatisticName(src.StatisticName)
            {}

            ~GetPlayerStatisticVersionsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                return output;
            }
        };

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
            time_t ActivationTime;
            Boxed<time_t> DeactivationTime;
            Boxed<time_t> ScheduledActivationTime;
            Boxed<time_t> ScheduledDeactivationTime;
            std::string StatisticName;
            Uint32 Version;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                ActivationTime(),
                DeactivationTime(),
                ScheduledActivationTime(),
                ScheduledDeactivationTime(),
                StatisticName(),
                Version()
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                ActivationTime(src.ActivationTime),
                DeactivationTime(src.DeactivationTime),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~PlayerStatisticVersion() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("ActivationTime")], ActivationTime);
                FromJsonUtilT(input[U("DeactivationTime")], DeactivationTime);
                FromJsonUtilT(input[U("ScheduledActivationTime")], ScheduledActivationTime);
                FromJsonUtilT(input[U("ScheduledDeactivationTime")], ScheduledDeactivationTime);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActivationTime; ToJsonUtilT(ActivationTime, each_ActivationTime); output[U("ActivationTime")] = each_ActivationTime;
                web::json::value each_DeactivationTime; ToJsonUtilT(DeactivationTime, each_DeactivationTime); output[U("DeactivationTime")] = each_DeactivationTime;
                web::json::value each_ScheduledActivationTime; ToJsonUtilT(ScheduledActivationTime, each_ScheduledActivationTime); output[U("ScheduledActivationTime")] = each_ScheduledActivationTime;
                web::json::value each_ScheduledDeactivationTime; ToJsonUtilT(ScheduledDeactivationTime, each_ScheduledDeactivationTime); output[U("ScheduledDeactivationTime")] = each_ScheduledDeactivationTime;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetPlayerStatisticVersionsResult : public PlayFabResultCommon
        {
            std::list<PlayerStatisticVersion> StatisticVersions;

            GetPlayerStatisticVersionsResult() :
                PlayFabResultCommon(),
                StatisticVersions()
            {}

            GetPlayerStatisticVersionsResult(const GetPlayerStatisticVersionsResult& src) :
                PlayFabResultCommon(),
                StatisticVersions(src.StatisticVersions)
            {}

            ~GetPlayerStatisticVersionsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("StatisticVersions")], StatisticVersions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticVersions; ToJsonUtilO(StatisticVersions, each_StatisticVersions); output[U("StatisticVersions")] = each_StatisticVersions;
                return output;
            }
        };

        struct GetPlayerTagsRequest : public PlayFabRequestCommon
        {
            std::string Namespace;
            std::string PlayFabId;

            GetPlayerTagsRequest() :
                PlayFabRequestCommon(),
                Namespace(),
                PlayFabId()
            {}

            GetPlayerTagsRequest(const GetPlayerTagsRequest& src) :
                PlayFabRequestCommon(),
                Namespace(src.Namespace),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayerTagsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Namespace")], Namespace);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Namespace; ToJsonUtilS(Namespace, each_Namespace); output[U("Namespace")] = each_Namespace;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GetPlayerTagsResult : public PlayFabResultCommon
        {
            std::string PlayFabId;
            std::list<std::string> Tags;

            GetPlayerTagsResult() :
                PlayFabResultCommon(),
                PlayFabId(),
                Tags()
            {}

            GetPlayerTagsResult(const GetPlayerTagsResult& src) :
                PlayFabResultCommon(),
                PlayFabId(src.PlayFabId),
                Tags(src.Tags)
            {}

            ~GetPlayerTagsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("Tags")], Tags);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[U("Tags")] = each_Tags;
                return output;
            }
        };

        struct GetPlayerTradesRequest : public PlayFabRequestCommon
        {
            Boxed<TradeStatus> StatusFilter;

            GetPlayerTradesRequest() :
                PlayFabRequestCommon(),
                StatusFilter()
            {}

            GetPlayerTradesRequest(const GetPlayerTradesRequest& src) :
                PlayFabRequestCommon(),
                StatusFilter(src.StatusFilter)
            {}

            ~GetPlayerTradesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("StatusFilter")], StatusFilter);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatusFilter; ToJsonUtilE(StatusFilter, each_StatusFilter); output[U("StatusFilter")] = each_StatusFilter;
                return output;
            }
        };

        struct GetPlayerTradesResponse : public PlayFabResultCommon
        {
            std::list<TradeInfo> AcceptedTrades;
            std::list<TradeInfo> OpenedTrades;

            GetPlayerTradesResponse() :
                PlayFabResultCommon(),
                AcceptedTrades(),
                OpenedTrades()
            {}

            GetPlayerTradesResponse(const GetPlayerTradesResponse& src) :
                PlayFabResultCommon(),
                AcceptedTrades(src.AcceptedTrades),
                OpenedTrades(src.OpenedTrades)
            {}

            ~GetPlayerTradesResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("AcceptedTrades")], AcceptedTrades);
                FromJsonUtilO(input[U("OpenedTrades")], OpenedTrades);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AcceptedTrades; ToJsonUtilO(AcceptedTrades, each_AcceptedTrades); output[U("AcceptedTrades")] = each_AcceptedTrades;
                web::json::value each_OpenedTrades; ToJsonUtilO(OpenedTrades, each_OpenedTrades); output[U("OpenedTrades")] = each_OpenedTrades;
                return output;
            }
        };

        struct GetPlayFabIDsFromFacebookIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> FacebookIDs;

            GetPlayFabIDsFromFacebookIDsRequest() :
                PlayFabRequestCommon(),
                FacebookIDs()
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const GetPlayFabIDsFromFacebookIDsRequest& src) :
                PlayFabRequestCommon(),
                FacebookIDs(src.FacebookIDs)
            {}

            ~GetPlayFabIDsFromFacebookIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FacebookIDs")], FacebookIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FacebookIDs; ToJsonUtilS(FacebookIDs, each_FacebookIDs); output[U("FacebookIDs")] = each_FacebookIDs;
                return output;
            }
        };

        struct GetPlayFabIDsFromFacebookIDsResult : public PlayFabResultCommon
        {
            std::list<FacebookPlayFabIdPair> Data;

            GetPlayFabIDsFromFacebookIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromFacebookIDsResult(const GetPlayFabIDsFromFacebookIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromFacebookIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Data")], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromGameCenterIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> GameCenterIDs;

            GetPlayFabIDsFromGameCenterIDsRequest() :
                PlayFabRequestCommon(),
                GameCenterIDs()
            {}

            GetPlayFabIDsFromGameCenterIDsRequest(const GetPlayFabIDsFromGameCenterIDsRequest& src) :
                PlayFabRequestCommon(),
                GameCenterIDs(src.GameCenterIDs)
            {}

            ~GetPlayFabIDsFromGameCenterIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("GameCenterIDs")], GameCenterIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameCenterIDs; ToJsonUtilS(GameCenterIDs, each_GameCenterIDs); output[U("GameCenterIDs")] = each_GameCenterIDs;
                return output;
            }
        };

        struct GetPlayFabIDsFromGameCenterIDsResult : public PlayFabResultCommon
        {
            std::list<GameCenterPlayFabIdPair> Data;

            GetPlayFabIDsFromGameCenterIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromGameCenterIDsResult(const GetPlayFabIDsFromGameCenterIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromGameCenterIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Data")], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromGenericIDsRequest : public PlayFabRequestCommon
        {
            std::list<GenericServiceId> GenericIDs;

            GetPlayFabIDsFromGenericIDsRequest() :
                PlayFabRequestCommon(),
                GenericIDs()
            {}

            GetPlayFabIDsFromGenericIDsRequest(const GetPlayFabIDsFromGenericIDsRequest& src) :
                PlayFabRequestCommon(),
                GenericIDs(src.GenericIDs)
            {}

            ~GetPlayFabIDsFromGenericIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("GenericIDs")], GenericIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GenericIDs; ToJsonUtilO(GenericIDs, each_GenericIDs); output[U("GenericIDs")] = each_GenericIDs;
                return output;
            }
        };

        struct GetPlayFabIDsFromGenericIDsResult : public PlayFabResultCommon
        {
            std::list<GenericPlayFabIdPair> Data;

            GetPlayFabIDsFromGenericIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromGenericIDsResult(const GetPlayFabIDsFromGenericIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromGenericIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Data")], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromGoogleIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> GoogleIDs;

            GetPlayFabIDsFromGoogleIDsRequest() :
                PlayFabRequestCommon(),
                GoogleIDs()
            {}

            GetPlayFabIDsFromGoogleIDsRequest(const GetPlayFabIDsFromGoogleIDsRequest& src) :
                PlayFabRequestCommon(),
                GoogleIDs(src.GoogleIDs)
            {}

            ~GetPlayFabIDsFromGoogleIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("GoogleIDs")], GoogleIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GoogleIDs; ToJsonUtilS(GoogleIDs, each_GoogleIDs); output[U("GoogleIDs")] = each_GoogleIDs;
                return output;
            }
        };

        struct GooglePlayFabIdPair : public PlayFabBaseModel
        {
            std::string GoogleId;
            std::string PlayFabId;

            GooglePlayFabIdPair() :
                PlayFabBaseModel(),
                GoogleId(),
                PlayFabId()
            {}

            GooglePlayFabIdPair(const GooglePlayFabIdPair& src) :
                PlayFabBaseModel(),
                GoogleId(src.GoogleId),
                PlayFabId(src.PlayFabId)
            {}

            ~GooglePlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("GoogleId")], GoogleId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GoogleId; ToJsonUtilS(GoogleId, each_GoogleId); output[U("GoogleId")] = each_GoogleId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GetPlayFabIDsFromGoogleIDsResult : public PlayFabResultCommon
        {
            std::list<GooglePlayFabIdPair> Data;

            GetPlayFabIDsFromGoogleIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromGoogleIDsResult(const GetPlayFabIDsFromGoogleIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromGoogleIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Data")], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromKongregateIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> KongregateIDs;

            GetPlayFabIDsFromKongregateIDsRequest() :
                PlayFabRequestCommon(),
                KongregateIDs()
            {}

            GetPlayFabIDsFromKongregateIDsRequest(const GetPlayFabIDsFromKongregateIDsRequest& src) :
                PlayFabRequestCommon(),
                KongregateIDs(src.KongregateIDs)
            {}

            ~GetPlayFabIDsFromKongregateIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("KongregateIDs")], KongregateIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_KongregateIDs; ToJsonUtilS(KongregateIDs, each_KongregateIDs); output[U("KongregateIDs")] = each_KongregateIDs;
                return output;
            }
        };

        struct KongregatePlayFabIdPair : public PlayFabBaseModel
        {
            std::string KongregateId;
            std::string PlayFabId;

            KongregatePlayFabIdPair() :
                PlayFabBaseModel(),
                KongregateId(),
                PlayFabId()
            {}

            KongregatePlayFabIdPair(const KongregatePlayFabIdPair& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                PlayFabId(src.PlayFabId)
            {}

            ~KongregatePlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("KongregateId")], KongregateId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output[U("KongregateId")] = each_KongregateId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GetPlayFabIDsFromKongregateIDsResult : public PlayFabResultCommon
        {
            std::list<KongregatePlayFabIdPair> Data;

            GetPlayFabIDsFromKongregateIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromKongregateIDsResult(const GetPlayFabIDsFromKongregateIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromKongregateIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Data")], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromSteamIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> SteamStringIDs;

            GetPlayFabIDsFromSteamIDsRequest() :
                PlayFabRequestCommon(),
                SteamStringIDs()
            {}

            GetPlayFabIDsFromSteamIDsRequest(const GetPlayFabIDsFromSteamIDsRequest& src) :
                PlayFabRequestCommon(),
                SteamStringIDs(src.SteamStringIDs)
            {}

            ~GetPlayFabIDsFromSteamIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("SteamStringIDs")], SteamStringIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SteamStringIDs; ToJsonUtilS(SteamStringIDs, each_SteamStringIDs); output[U("SteamStringIDs")] = each_SteamStringIDs;
                return output;
            }
        };

        struct SteamPlayFabIdPair : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string SteamStringId;

            SteamPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                SteamStringId()
            {}

            SteamPlayFabIdPair(const SteamPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                SteamStringId(src.SteamStringId)
            {}

            ~SteamPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("SteamStringId")], SteamStringId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_SteamStringId; ToJsonUtilS(SteamStringId, each_SteamStringId); output[U("SteamStringId")] = each_SteamStringId;
                return output;
            }
        };

        struct GetPlayFabIDsFromSteamIDsResult : public PlayFabResultCommon
        {
            std::list<SteamPlayFabIdPair> Data;

            GetPlayFabIDsFromSteamIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromSteamIDsResult(const GetPlayFabIDsFromSteamIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromSteamIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Data")], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                return output;
            }
        };

        struct GetPlayFabIDsFromTwitchIDsRequest : public PlayFabRequestCommon
        {
            std::list<std::string> TwitchIds;

            GetPlayFabIDsFromTwitchIDsRequest() :
                PlayFabRequestCommon(),
                TwitchIds()
            {}

            GetPlayFabIDsFromTwitchIDsRequest(const GetPlayFabIDsFromTwitchIDsRequest& src) :
                PlayFabRequestCommon(),
                TwitchIds(src.TwitchIds)
            {}

            ~GetPlayFabIDsFromTwitchIDsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("TwitchIds")], TwitchIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TwitchIds; ToJsonUtilS(TwitchIds, each_TwitchIds); output[U("TwitchIds")] = each_TwitchIds;
                return output;
            }
        };

        struct TwitchPlayFabIdPair : public PlayFabBaseModel
        {
            std::string PlayFabId;
            std::string TwitchId;

            TwitchPlayFabIdPair() :
                PlayFabBaseModel(),
                PlayFabId(),
                TwitchId()
            {}

            TwitchPlayFabIdPair(const TwitchPlayFabIdPair& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                TwitchId(src.TwitchId)
            {}

            ~TwitchPlayFabIdPair() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("TwitchId")], TwitchId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_TwitchId; ToJsonUtilS(TwitchId, each_TwitchId); output[U("TwitchId")] = each_TwitchId;
                return output;
            }
        };

        struct GetPlayFabIDsFromTwitchIDsResult : public PlayFabResultCommon
        {
            std::list<TwitchPlayFabIdPair> Data;

            GetPlayFabIDsFromTwitchIDsResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPlayFabIDsFromTwitchIDsResult(const GetPlayFabIDsFromTwitchIDsResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPlayFabIDsFromTwitchIDsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Data")], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                return output;
            }
        };

        struct GetPublisherDataRequest : public PlayFabRequestCommon
        {
            std::list<std::string> Keys;

            GetPublisherDataRequest() :
                PlayFabRequestCommon(),
                Keys()
            {}

            GetPublisherDataRequest(const GetPublisherDataRequest& src) :
                PlayFabRequestCommon(),
                Keys(src.Keys)
            {}

            ~GetPublisherDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Keys")], Keys);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Keys; ToJsonUtilS(Keys, each_Keys); output[U("Keys")] = each_Keys;
                return output;
            }
        };

        struct GetPublisherDataResult : public PlayFabResultCommon
        {
            std::map<std::string, std::string> Data;

            GetPublisherDataResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetPublisherDataResult(const GetPublisherDataResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetPublisherDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Data")], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                return output;
            }
        };

        struct GetPurchaseRequest : public PlayFabRequestCommon
        {
            std::string OrderId;

            GetPurchaseRequest() :
                PlayFabRequestCommon(),
                OrderId()
            {}

            GetPurchaseRequest(const GetPurchaseRequest& src) :
                PlayFabRequestCommon(),
                OrderId(src.OrderId)
            {}

            ~GetPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("OrderId")], OrderId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[U("OrderId")] = each_OrderId;
                return output;
            }
        };

        struct GetPurchaseResult : public PlayFabResultCommon
        {
            std::string OrderId;
            std::string PaymentProvider;
            time_t PurchaseDate;
            std::string TransactionId;
            std::string TransactionStatus;

            GetPurchaseResult() :
                PlayFabResultCommon(),
                OrderId(),
                PaymentProvider(),
                PurchaseDate(),
                TransactionId(),
                TransactionStatus()
            {}

            GetPurchaseResult(const GetPurchaseResult& src) :
                PlayFabResultCommon(),
                OrderId(src.OrderId),
                PaymentProvider(src.PaymentProvider),
                PurchaseDate(src.PurchaseDate),
                TransactionId(src.TransactionId),
                TransactionStatus(src.TransactionStatus)
            {}

            ~GetPurchaseResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("OrderId")], OrderId);
                FromJsonUtilS(input[U("PaymentProvider")], PaymentProvider);
                FromJsonUtilT(input[U("PurchaseDate")], PurchaseDate);
                FromJsonUtilS(input[U("TransactionId")], TransactionId);
                FromJsonUtilS(input[U("TransactionStatus")], TransactionStatus);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[U("OrderId")] = each_OrderId;
                web::json::value each_PaymentProvider; ToJsonUtilS(PaymentProvider, each_PaymentProvider); output[U("PaymentProvider")] = each_PaymentProvider;
                web::json::value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output[U("PurchaseDate")] = each_PurchaseDate;
                web::json::value each_TransactionId; ToJsonUtilS(TransactionId, each_TransactionId); output[U("TransactionId")] = each_TransactionId;
                web::json::value each_TransactionStatus; ToJsonUtilS(TransactionStatus, each_TransactionStatus); output[U("TransactionStatus")] = each_TransactionStatus;
                return output;
            }
        };

        struct GetSharedGroupDataRequest : public PlayFabRequestCommon
        {
            Boxed<bool> GetMembers;
            std::list<std::string> Keys;
            std::string SharedGroupId;

            GetSharedGroupDataRequest() :
                PlayFabRequestCommon(),
                GetMembers(),
                Keys(),
                SharedGroupId()
            {}

            GetSharedGroupDataRequest(const GetSharedGroupDataRequest& src) :
                PlayFabRequestCommon(),
                GetMembers(src.GetMembers),
                Keys(src.Keys),
                SharedGroupId(src.SharedGroupId)
            {}

            ~GetSharedGroupDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("GetMembers")], GetMembers);
                FromJsonUtilS(input[U("Keys")], Keys);
                FromJsonUtilS(input[U("SharedGroupId")], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GetMembers; ToJsonUtilP(GetMembers, each_GetMembers); output[U("GetMembers")] = each_GetMembers;
                web::json::value each_Keys; ToJsonUtilS(Keys, each_Keys); output[U("Keys")] = each_Keys;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[U("SharedGroupId")] = each_SharedGroupId;
                return output;
            }
        };

        struct SharedGroupDataRecord : public PlayFabBaseModel
        {
            time_t LastUpdated;
            std::string LastUpdatedBy;
            Boxed<UserDataPermission> Permission;
            std::string Value;

            SharedGroupDataRecord() :
                PlayFabBaseModel(),
                LastUpdated(),
                LastUpdatedBy(),
                Permission(),
                Value()
            {}

            SharedGroupDataRecord(const SharedGroupDataRecord& src) :
                PlayFabBaseModel(),
                LastUpdated(src.LastUpdated),
                LastUpdatedBy(src.LastUpdatedBy),
                Permission(src.Permission),
                Value(src.Value)
            {}

            ~SharedGroupDataRecord() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("LastUpdated")], LastUpdated);
                FromJsonUtilS(input[U("LastUpdatedBy")], LastUpdatedBy);
                FromJsonUtilE(input[U("Permission")], Permission);
                FromJsonUtilS(input[U("Value")], Value);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LastUpdated; ToJsonUtilT(LastUpdated, each_LastUpdated); output[U("LastUpdated")] = each_LastUpdated;
                web::json::value each_LastUpdatedBy; ToJsonUtilS(LastUpdatedBy, each_LastUpdatedBy); output[U("LastUpdatedBy")] = each_LastUpdatedBy;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[U("Permission")] = each_Permission;
                web::json::value each_Value; ToJsonUtilS(Value, each_Value); output[U("Value")] = each_Value;
                return output;
            }
        };

        struct GetSharedGroupDataResult : public PlayFabResultCommon
        {
            std::map<std::string, SharedGroupDataRecord> Data;
            std::list<std::string> Members;

            GetSharedGroupDataResult() :
                PlayFabResultCommon(),
                Data(),
                Members()
            {}

            GetSharedGroupDataResult(const GetSharedGroupDataResult& src) :
                PlayFabResultCommon(),
                Data(src.Data),
                Members(src.Members)
            {}

            ~GetSharedGroupDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Data")], Data);
                FromJsonUtilS(input[U("Members")], Members);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_Members; ToJsonUtilS(Members, each_Members); output[U("Members")] = each_Members;
                return output;
            }
        };

        struct GetStoreItemsRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string StoreId;

            GetStoreItemsRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                StoreId()
            {}

            GetStoreItemsRequest(const GetStoreItemsRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId)
            {}

            ~GetStoreItemsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("StoreId")], StoreId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[U("StoreId")] = each_StoreId;
                return output;
            }
        };

        struct StoreMarketingModel : public PlayFabBaseModel
        {
            std::string Description;
            std::string DisplayName;
            web::json::value Metadata;

            StoreMarketingModel() :
                PlayFabBaseModel(),
                Description(),
                DisplayName(),
                Metadata()
            {}

            StoreMarketingModel(const StoreMarketingModel& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                DisplayName(src.DisplayName),
                Metadata(src.Metadata)
            {}

            ~StoreMarketingModel() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Description")], Description);
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                Metadata = input[U("Metadata")];
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[U("Description")] = each_Description;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                output[U("Metadata")] = Metadata;
                return output;
            }
        };

        struct StoreItem : public PlayFabBaseModel
        {
            web::json::value CustomData;
            Boxed<Uint32> DisplayPosition;
            std::string ItemId;
            std::map<std::string, Uint32> RealCurrencyPrices;
            std::map<std::string, Uint32> VirtualCurrencyPrices;

            StoreItem() :
                PlayFabBaseModel(),
                CustomData(),
                DisplayPosition(),
                ItemId(),
                RealCurrencyPrices(),
                VirtualCurrencyPrices()
            {}

            StoreItem(const StoreItem& src) :
                PlayFabBaseModel(),
                CustomData(src.CustomData),
                DisplayPosition(src.DisplayPosition),
                ItemId(src.ItemId),
                RealCurrencyPrices(src.RealCurrencyPrices),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices)
            {}

            ~StoreItem() { }

            void FromJson(web::json::value& input) override
            {
                CustomData = input[U("CustomData")];
                FromJsonUtilP(input[U("DisplayPosition")], DisplayPosition);
                FromJsonUtilS(input[U("ItemId")], ItemId);
                FromJsonUtilP(input[U("RealCurrencyPrices")], RealCurrencyPrices);
                FromJsonUtilP(input[U("VirtualCurrencyPrices")], VirtualCurrencyPrices);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("CustomData")] = CustomData;
                web::json::value each_DisplayPosition; ToJsonUtilP(DisplayPosition, each_DisplayPosition); output[U("DisplayPosition")] = each_DisplayPosition;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                web::json::value each_RealCurrencyPrices; ToJsonUtilP(RealCurrencyPrices, each_RealCurrencyPrices); output[U("RealCurrencyPrices")] = each_RealCurrencyPrices;
                web::json::value each_VirtualCurrencyPrices; ToJsonUtilP(VirtualCurrencyPrices, each_VirtualCurrencyPrices); output[U("VirtualCurrencyPrices")] = each_VirtualCurrencyPrices;
                return output;
            }
        };

        struct GetStoreItemsResult : public PlayFabResultCommon
        {
            std::string CatalogVersion;
            Boxed<StoreMarketingModel> MarketingData;
            Boxed<SourceType> Source;
            std::list<StoreItem> Store;
            std::string StoreId;

            GetStoreItemsResult() :
                PlayFabResultCommon(),
                CatalogVersion(),
                MarketingData(),
                Source(),
                Store(),
                StoreId()
            {}

            GetStoreItemsResult(const GetStoreItemsResult& src) :
                PlayFabResultCommon(),
                CatalogVersion(src.CatalogVersion),
                MarketingData(src.MarketingData),
                Source(src.Source),
                Store(src.Store),
                StoreId(src.StoreId)
            {}

            ~GetStoreItemsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilO(input[U("MarketingData")], MarketingData);
                FromJsonUtilE(input[U("Source")], Source);
                FromJsonUtilO(input[U("Store")], Store);
                FromJsonUtilS(input[U("StoreId")], StoreId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_MarketingData; ToJsonUtilO(MarketingData, each_MarketingData); output[U("MarketingData")] = each_MarketingData;
                web::json::value each_Source; ToJsonUtilE(Source, each_Source); output[U("Source")] = each_Source;
                web::json::value each_Store; ToJsonUtilO(Store, each_Store); output[U("Store")] = each_Store;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[U("StoreId")] = each_StoreId;
                return output;
            }
        };

        struct GetTimeRequest : public PlayFabRequestCommon
        {

            GetTimeRequest() :
                PlayFabRequestCommon()
            {}

            GetTimeRequest(const GetTimeRequest& src) :
                PlayFabRequestCommon()
            {}

            ~GetTimeRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetTimeResult : public PlayFabResultCommon
        {
            time_t Time;

            GetTimeResult() :
                PlayFabResultCommon(),
                Time()
            {}

            GetTimeResult(const GetTimeResult& src) :
                PlayFabResultCommon(),
                Time(src.Time)
            {}

            ~GetTimeResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("Time")], Time);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Time; ToJsonUtilT(Time, each_Time); output[U("Time")] = each_Time;
                return output;
            }
        };

        struct GetTitleDataRequest : public PlayFabRequestCommon
        {
            std::list<std::string> Keys;

            GetTitleDataRequest() :
                PlayFabRequestCommon(),
                Keys()
            {}

            GetTitleDataRequest(const GetTitleDataRequest& src) :
                PlayFabRequestCommon(),
                Keys(src.Keys)
            {}

            ~GetTitleDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Keys")], Keys);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Keys; ToJsonUtilS(Keys, each_Keys); output[U("Keys")] = each_Keys;
                return output;
            }
        };

        struct GetTitleDataResult : public PlayFabResultCommon
        {
            std::map<std::string, std::string> Data;

            GetTitleDataResult() :
                PlayFabResultCommon(),
                Data()
            {}

            GetTitleDataResult(const GetTitleDataResult& src) :
                PlayFabResultCommon(),
                Data(src.Data)
            {}

            ~GetTitleDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Data")], Data);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                return output;
            }
        };

        struct GetTitleNewsRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> Count;

            GetTitleNewsRequest() :
                PlayFabRequestCommon(),
                Count()
            {}

            GetTitleNewsRequest(const GetTitleNewsRequest& src) :
                PlayFabRequestCommon(),
                Count(src.Count)
            {}

            ~GetTitleNewsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Count")], Count);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Count; ToJsonUtilP(Count, each_Count); output[U("Count")] = each_Count;
                return output;
            }
        };

        struct TitleNewsItem : public PlayFabBaseModel
        {
            std::string Body;
            std::string NewsId;
            time_t Timestamp;
            std::string Title;

            TitleNewsItem() :
                PlayFabBaseModel(),
                Body(),
                NewsId(),
                Timestamp(),
                Title()
            {}

            TitleNewsItem(const TitleNewsItem& src) :
                PlayFabBaseModel(),
                Body(src.Body),
                NewsId(src.NewsId),
                Timestamp(src.Timestamp),
                Title(src.Title)
            {}

            ~TitleNewsItem() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Body")], Body);
                FromJsonUtilS(input[U("NewsId")], NewsId);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
                FromJsonUtilS(input[U("Title")], Title);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Body; ToJsonUtilS(Body, each_Body); output[U("Body")] = each_Body;
                web::json::value each_NewsId; ToJsonUtilS(NewsId, each_NewsId); output[U("NewsId")] = each_NewsId;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
                web::json::value each_Title; ToJsonUtilS(Title, each_Title); output[U("Title")] = each_Title;
                return output;
            }
        };

        struct GetTitleNewsResult : public PlayFabResultCommon
        {
            std::list<TitleNewsItem> News;

            GetTitleNewsResult() :
                PlayFabResultCommon(),
                News()
            {}

            GetTitleNewsResult(const GetTitleNewsResult& src) :
                PlayFabResultCommon(),
                News(src.News)
            {}

            ~GetTitleNewsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("News")], News);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_News; ToJsonUtilO(News, each_News); output[U("News")] = each_News;
                return output;
            }
        };

        struct GetTitlePublicKeyRequest : public PlayFabRequestCommon
        {
            std::string TitleId;
            std::string TitleSharedSecret;

            GetTitlePublicKeyRequest() :
                PlayFabRequestCommon(),
                TitleId(),
                TitleSharedSecret()
            {}

            GetTitlePublicKeyRequest(const GetTitlePublicKeyRequest& src) :
                PlayFabRequestCommon(),
                TitleId(src.TitleId),
                TitleSharedSecret(src.TitleSharedSecret)
            {}

            ~GetTitlePublicKeyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("TitleId")], TitleId);
                FromJsonUtilS(input[U("TitleSharedSecret")], TitleSharedSecret);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                web::json::value each_TitleSharedSecret; ToJsonUtilS(TitleSharedSecret, each_TitleSharedSecret); output[U("TitleSharedSecret")] = each_TitleSharedSecret;
                return output;
            }
        };

        struct GetTitlePublicKeyResult : public PlayFabResultCommon
        {
            std::string RSAPublicKey;

            GetTitlePublicKeyResult() :
                PlayFabResultCommon(),
                RSAPublicKey()
            {}

            GetTitlePublicKeyResult(const GetTitlePublicKeyResult& src) :
                PlayFabResultCommon(),
                RSAPublicKey(src.RSAPublicKey)
            {}

            ~GetTitlePublicKeyResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("RSAPublicKey")], RSAPublicKey);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_RSAPublicKey; ToJsonUtilS(RSAPublicKey, each_RSAPublicKey); output[U("RSAPublicKey")] = each_RSAPublicKey;
                return output;
            }
        };

        struct GetTradeStatusRequest : public PlayFabRequestCommon
        {
            std::string OfferingPlayerId;
            std::string TradeId;

            GetTradeStatusRequest() :
                PlayFabRequestCommon(),
                OfferingPlayerId(),
                TradeId()
            {}

            GetTradeStatusRequest(const GetTradeStatusRequest& src) :
                PlayFabRequestCommon(),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId)
            {}

            ~GetTradeStatusRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("OfferingPlayerId")], OfferingPlayerId);
                FromJsonUtilS(input[U("TradeId")], TradeId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OfferingPlayerId; ToJsonUtilS(OfferingPlayerId, each_OfferingPlayerId); output[U("OfferingPlayerId")] = each_OfferingPlayerId;
                web::json::value each_TradeId; ToJsonUtilS(TradeId, each_TradeId); output[U("TradeId")] = each_TradeId;
                return output;
            }
        };

        struct GetTradeStatusResponse : public PlayFabResultCommon
        {
            Boxed<TradeInfo> Trade;

            GetTradeStatusResponse() :
                PlayFabResultCommon(),
                Trade()
            {}

            GetTradeStatusResponse(const GetTradeStatusResponse& src) :
                PlayFabResultCommon(),
                Trade(src.Trade)
            {}

            ~GetTradeStatusResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Trade")], Trade);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Trade; ToJsonUtilO(Trade, each_Trade); output[U("Trade")] = each_Trade;
                return output;
            }
        };

        struct GetUserDataRequest : public PlayFabRequestCommon
        {
            Boxed<Uint32> IfChangedFromDataVersion;
            std::list<std::string> Keys;
            std::string PlayFabId;

            GetUserDataRequest() :
                PlayFabRequestCommon(),
                IfChangedFromDataVersion(),
                Keys(),
                PlayFabId()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabRequestCommon(),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId)
            {}

            ~GetUserDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("IfChangedFromDataVersion")], IfChangedFromDataVersion);
                FromJsonUtilS(input[U("Keys")], Keys);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IfChangedFromDataVersion; ToJsonUtilP(IfChangedFromDataVersion, each_IfChangedFromDataVersion); output[U("IfChangedFromDataVersion")] = each_IfChangedFromDataVersion;
                web::json::value each_Keys; ToJsonUtilS(Keys, each_Keys); output[U("Keys")] = each_Keys;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GetUserDataResult : public PlayFabResultCommon
        {
            std::map<std::string, UserDataRecord> Data;
            Uint32 DataVersion;

            GetUserDataResult() :
                PlayFabResultCommon(),
                Data(),
                DataVersion()
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabResultCommon(),
                Data(src.Data),
                DataVersion(src.DataVersion)
            {}

            ~GetUserDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Data")], Data);
                FromJsonUtilP(input[U("DataVersion")], DataVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output[U("DataVersion")] = each_DataVersion;
                return output;
            }
        };

        struct GetUserInventoryRequest : public PlayFabRequestCommon
        {

            GetUserInventoryRequest() :
                PlayFabRequestCommon()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabRequestCommon()
            {}

            ~GetUserInventoryRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetUserInventoryResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> Inventory;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabResultCommon(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabResultCommon(),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            ~GetUserInventoryResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Inventory")], Inventory);
                FromJsonUtilP(input[U("VirtualCurrency")], VirtualCurrency);
                FromJsonUtilO(input[U("VirtualCurrencyRechargeTimes")], VirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[U("Inventory")] = each_Inventory;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                web::json::value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output[U("VirtualCurrencyRechargeTimes")] = each_VirtualCurrencyRechargeTimes;
                return output;
            }
        };

        struct GetWindowsHelloChallengeRequest : public PlayFabRequestCommon
        {
            std::string PublicKeyHint;
            std::string TitleId;

            GetWindowsHelloChallengeRequest() :
                PlayFabRequestCommon(),
                PublicKeyHint(),
                TitleId()
            {}

            GetWindowsHelloChallengeRequest(const GetWindowsHelloChallengeRequest& src) :
                PlayFabRequestCommon(),
                PublicKeyHint(src.PublicKeyHint),
                TitleId(src.TitleId)
            {}

            ~GetWindowsHelloChallengeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PublicKeyHint")], PublicKeyHint);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PublicKeyHint; ToJsonUtilS(PublicKeyHint, each_PublicKeyHint); output[U("PublicKeyHint")] = each_PublicKeyHint;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct GetWindowsHelloChallengeResponse : public PlayFabResultCommon
        {
            std::string Challenge;

            GetWindowsHelloChallengeResponse() :
                PlayFabResultCommon(),
                Challenge()
            {}

            GetWindowsHelloChallengeResponse(const GetWindowsHelloChallengeResponse& src) :
                PlayFabResultCommon(),
                Challenge(src.Challenge)
            {}

            ~GetWindowsHelloChallengeResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Challenge")], Challenge);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Challenge; ToJsonUtilS(Challenge, each_Challenge); output[U("Challenge")] = each_Challenge;
                return output;
            }
        };

        struct GrantCharacterToUserRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterName;
            std::string ItemId;

            GrantCharacterToUserRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterName(),
                ItemId()
            {}

            GrantCharacterToUserRequest(const GrantCharacterToUserRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterName(src.CharacterName),
                ItemId(src.ItemId)
            {}

            ~GrantCharacterToUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterName")], CharacterName);
                FromJsonUtilS(input[U("ItemId")], ItemId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterName; ToJsonUtilS(CharacterName, each_CharacterName); output[U("CharacterName")] = each_CharacterName;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                return output;
            }
        };

        struct GrantCharacterToUserResult : public PlayFabResultCommon
        {
            std::string CharacterId;
            std::string CharacterType;
            bool Result;

            GrantCharacterToUserResult() :
                PlayFabResultCommon(),
                CharacterId(),
                CharacterType(),
                Result()
            {}

            GrantCharacterToUserResult(const GrantCharacterToUserResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                Result(src.Result)
            {}

            ~GrantCharacterToUserResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("CharacterType")], CharacterType);
                FromJsonUtilP(input[U("Result")], Result);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[U("CharacterType")] = each_CharacterType;
                web::json::value each_Result; ToJsonUtilP(Result, each_Result); output[U("Result")] = each_Result;
                return output;
            }
        };

        struct ItemPurchaseRequest : public PlayFabRequestCommon
        {
            std::string Annotation;
            std::string ItemId;
            Uint32 Quantity;
            std::list<std::string> UpgradeFromItems;

            ItemPurchaseRequest() :
                PlayFabRequestCommon(),
                Annotation(),
                ItemId(),
                Quantity(),
                UpgradeFromItems()
            {}

            ItemPurchaseRequest(const ItemPurchaseRequest& src) :
                PlayFabRequestCommon(),
                Annotation(src.Annotation),
                ItemId(src.ItemId),
                Quantity(src.Quantity),
                UpgradeFromItems(src.UpgradeFromItems)
            {}

            ~ItemPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Annotation")], Annotation);
                FromJsonUtilS(input[U("ItemId")], ItemId);
                FromJsonUtilP(input[U("Quantity")], Quantity);
                FromJsonUtilS(input[U("UpgradeFromItems")], UpgradeFromItems);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output[U("Annotation")] = each_Annotation;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                web::json::value each_Quantity; ToJsonUtilP(Quantity, each_Quantity); output[U("Quantity")] = each_Quantity;
                web::json::value each_UpgradeFromItems; ToJsonUtilS(UpgradeFromItems, each_UpgradeFromItems); output[U("UpgradeFromItems")] = each_UpgradeFromItems;
                return output;
            }
        };

        struct LinkAndroidDeviceIDRequest : public PlayFabRequestCommon
        {
            std::string AndroidDevice;
            std::string AndroidDeviceId;
            Boxed<bool> ForceLink;
            std::string OS;

            LinkAndroidDeviceIDRequest() :
                PlayFabRequestCommon(),
                AndroidDevice(),
                AndroidDeviceId(),
                ForceLink(),
                OS()
            {}

            LinkAndroidDeviceIDRequest(const LinkAndroidDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                AndroidDevice(src.AndroidDevice),
                AndroidDeviceId(src.AndroidDeviceId),
                ForceLink(src.ForceLink),
                OS(src.OS)
            {}

            ~LinkAndroidDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AndroidDevice")], AndroidDevice);
                FromJsonUtilS(input[U("AndroidDeviceId")], AndroidDeviceId);
                FromJsonUtilP(input[U("ForceLink")], ForceLink);
                FromJsonUtilS(input[U("OS")], OS);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AndroidDevice; ToJsonUtilS(AndroidDevice, each_AndroidDevice); output[U("AndroidDevice")] = each_AndroidDevice;
                web::json::value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output[U("AndroidDeviceId")] = each_AndroidDeviceId;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[U("ForceLink")] = each_ForceLink;
                web::json::value each_OS; ToJsonUtilS(OS, each_OS); output[U("OS")] = each_OS;
                return output;
            }
        };

        struct LinkAndroidDeviceIDResult : public PlayFabResultCommon
        {

            LinkAndroidDeviceIDResult() :
                PlayFabResultCommon()
            {}

            LinkAndroidDeviceIDResult(const LinkAndroidDeviceIDResult& src) :
                PlayFabResultCommon()
            {}

            ~LinkAndroidDeviceIDResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkCustomIDRequest : public PlayFabRequestCommon
        {
            std::string CustomId;
            Boxed<bool> ForceLink;

            LinkCustomIDRequest() :
                PlayFabRequestCommon(),
                CustomId(),
                ForceLink()
            {}

            LinkCustomIDRequest(const LinkCustomIDRequest& src) :
                PlayFabRequestCommon(),
                CustomId(src.CustomId),
                ForceLink(src.ForceLink)
            {}

            ~LinkCustomIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CustomId")], CustomId);
                FromJsonUtilP(input[U("ForceLink")], ForceLink);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output[U("CustomId")] = each_CustomId;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[U("ForceLink")] = each_ForceLink;
                return output;
            }
        };

        struct LinkCustomIDResult : public PlayFabResultCommon
        {

            LinkCustomIDResult() :
                PlayFabResultCommon()
            {}

            LinkCustomIDResult(const LinkCustomIDResult& src) :
                PlayFabResultCommon()
            {}

            ~LinkCustomIDResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkFacebookAccountRequest : public PlayFabRequestCommon
        {
            std::string AccessToken;
            Boxed<bool> ForceLink;

            LinkFacebookAccountRequest() :
                PlayFabRequestCommon(),
                AccessToken(),
                ForceLink()
            {}

            LinkFacebookAccountRequest(const LinkFacebookAccountRequest& src) :
                PlayFabRequestCommon(),
                AccessToken(src.AccessToken),
                ForceLink(src.ForceLink)
            {}

            ~LinkFacebookAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AccessToken")], AccessToken);
                FromJsonUtilP(input[U("ForceLink")], ForceLink);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output[U("AccessToken")] = each_AccessToken;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[U("ForceLink")] = each_ForceLink;
                return output;
            }
        };

        struct LinkFacebookAccountResult : public PlayFabResultCommon
        {

            LinkFacebookAccountResult() :
                PlayFabResultCommon()
            {}

            LinkFacebookAccountResult(const LinkFacebookAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~LinkFacebookAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkGameCenterAccountRequest : public PlayFabRequestCommon
        {
            Boxed<bool> ForceLink;
            std::string GameCenterId;

            LinkGameCenterAccountRequest() :
                PlayFabRequestCommon(),
                ForceLink(),
                GameCenterId()
            {}

            LinkGameCenterAccountRequest(const LinkGameCenterAccountRequest& src) :
                PlayFabRequestCommon(),
                ForceLink(src.ForceLink),
                GameCenterId(src.GameCenterId)
            {}

            ~LinkGameCenterAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("ForceLink")], ForceLink);
                FromJsonUtilS(input[U("GameCenterId")], GameCenterId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[U("ForceLink")] = each_ForceLink;
                web::json::value each_GameCenterId; ToJsonUtilS(GameCenterId, each_GameCenterId); output[U("GameCenterId")] = each_GameCenterId;
                return output;
            }
        };

        struct LinkGameCenterAccountResult : public PlayFabResultCommon
        {

            LinkGameCenterAccountResult() :
                PlayFabResultCommon()
            {}

            LinkGameCenterAccountResult(const LinkGameCenterAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~LinkGameCenterAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkGoogleAccountRequest : public PlayFabRequestCommon
        {
            Boxed<bool> ForceLink;
            std::string ServerAuthCode;

            LinkGoogleAccountRequest() :
                PlayFabRequestCommon(),
                ForceLink(),
                ServerAuthCode()
            {}

            LinkGoogleAccountRequest(const LinkGoogleAccountRequest& src) :
                PlayFabRequestCommon(),
                ForceLink(src.ForceLink),
                ServerAuthCode(src.ServerAuthCode)
            {}

            ~LinkGoogleAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("ForceLink")], ForceLink);
                FromJsonUtilS(input[U("ServerAuthCode")], ServerAuthCode);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[U("ForceLink")] = each_ForceLink;
                web::json::value each_ServerAuthCode; ToJsonUtilS(ServerAuthCode, each_ServerAuthCode); output[U("ServerAuthCode")] = each_ServerAuthCode;
                return output;
            }
        };

        struct LinkGoogleAccountResult : public PlayFabResultCommon
        {

            LinkGoogleAccountResult() :
                PlayFabResultCommon()
            {}

            LinkGoogleAccountResult(const LinkGoogleAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~LinkGoogleAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkIOSDeviceIDRequest : public PlayFabRequestCommon
        {
            std::string DeviceId;
            std::string DeviceModel;
            Boxed<bool> ForceLink;
            std::string OS;

            LinkIOSDeviceIDRequest() :
                PlayFabRequestCommon(),
                DeviceId(),
                DeviceModel(),
                ForceLink(),
                OS()
            {}

            LinkIOSDeviceIDRequest(const LinkIOSDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                DeviceId(src.DeviceId),
                DeviceModel(src.DeviceModel),
                ForceLink(src.ForceLink),
                OS(src.OS)
            {}

            ~LinkIOSDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DeviceId")], DeviceId);
                FromJsonUtilS(input[U("DeviceModel")], DeviceModel);
                FromJsonUtilP(input[U("ForceLink")], ForceLink);
                FromJsonUtilS(input[U("OS")], OS);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DeviceId; ToJsonUtilS(DeviceId, each_DeviceId); output[U("DeviceId")] = each_DeviceId;
                web::json::value each_DeviceModel; ToJsonUtilS(DeviceModel, each_DeviceModel); output[U("DeviceModel")] = each_DeviceModel;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[U("ForceLink")] = each_ForceLink;
                web::json::value each_OS; ToJsonUtilS(OS, each_OS); output[U("OS")] = each_OS;
                return output;
            }
        };

        struct LinkIOSDeviceIDResult : public PlayFabResultCommon
        {

            LinkIOSDeviceIDResult() :
                PlayFabResultCommon()
            {}

            LinkIOSDeviceIDResult(const LinkIOSDeviceIDResult& src) :
                PlayFabResultCommon()
            {}

            ~LinkIOSDeviceIDResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkKongregateAccountRequest : public PlayFabRequestCommon
        {
            std::string AuthTicket;
            Boxed<bool> ForceLink;
            std::string KongregateId;

            LinkKongregateAccountRequest() :
                PlayFabRequestCommon(),
                AuthTicket(),
                ForceLink(),
                KongregateId()
            {}

            LinkKongregateAccountRequest(const LinkKongregateAccountRequest& src) :
                PlayFabRequestCommon(),
                AuthTicket(src.AuthTicket),
                ForceLink(src.ForceLink),
                KongregateId(src.KongregateId)
            {}

            ~LinkKongregateAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AuthTicket")], AuthTicket);
                FromJsonUtilP(input[U("ForceLink")], ForceLink);
                FromJsonUtilS(input[U("KongregateId")], KongregateId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AuthTicket; ToJsonUtilS(AuthTicket, each_AuthTicket); output[U("AuthTicket")] = each_AuthTicket;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[U("ForceLink")] = each_ForceLink;
                web::json::value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output[U("KongregateId")] = each_KongregateId;
                return output;
            }
        };

        struct LinkKongregateAccountResult : public PlayFabResultCommon
        {

            LinkKongregateAccountResult() :
                PlayFabResultCommon()
            {}

            LinkKongregateAccountResult(const LinkKongregateAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~LinkKongregateAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkSteamAccountRequest : public PlayFabRequestCommon
        {
            Boxed<bool> ForceLink;
            std::string SteamTicket;

            LinkSteamAccountRequest() :
                PlayFabRequestCommon(),
                ForceLink(),
                SteamTicket()
            {}

            LinkSteamAccountRequest(const LinkSteamAccountRequest& src) :
                PlayFabRequestCommon(),
                ForceLink(src.ForceLink),
                SteamTicket(src.SteamTicket)
            {}

            ~LinkSteamAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("ForceLink")], ForceLink);
                FromJsonUtilS(input[U("SteamTicket")], SteamTicket);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[U("ForceLink")] = each_ForceLink;
                web::json::value each_SteamTicket; ToJsonUtilS(SteamTicket, each_SteamTicket); output[U("SteamTicket")] = each_SteamTicket;
                return output;
            }
        };

        struct LinkSteamAccountResult : public PlayFabResultCommon
        {

            LinkSteamAccountResult() :
                PlayFabResultCommon()
            {}

            LinkSteamAccountResult(const LinkSteamAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~LinkSteamAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkTwitchAccountRequest : public PlayFabRequestCommon
        {
            std::string AccessToken;
            Boxed<bool> ForceLink;

            LinkTwitchAccountRequest() :
                PlayFabRequestCommon(),
                AccessToken(),
                ForceLink()
            {}

            LinkTwitchAccountRequest(const LinkTwitchAccountRequest& src) :
                PlayFabRequestCommon(),
                AccessToken(src.AccessToken),
                ForceLink(src.ForceLink)
            {}

            ~LinkTwitchAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AccessToken")], AccessToken);
                FromJsonUtilP(input[U("ForceLink")], ForceLink);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output[U("AccessToken")] = each_AccessToken;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[U("ForceLink")] = each_ForceLink;
                return output;
            }
        };

        struct LinkTwitchAccountResult : public PlayFabResultCommon
        {

            LinkTwitchAccountResult() :
                PlayFabResultCommon()
            {}

            LinkTwitchAccountResult(const LinkTwitchAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~LinkTwitchAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct LinkWindowsHelloAccountRequest : public PlayFabRequestCommon
        {
            std::string DeviceName;
            Boxed<bool> ForceLink;
            std::string PublicKey;
            std::string UserName;

            LinkWindowsHelloAccountRequest() :
                PlayFabRequestCommon(),
                DeviceName(),
                ForceLink(),
                PublicKey(),
                UserName()
            {}

            LinkWindowsHelloAccountRequest(const LinkWindowsHelloAccountRequest& src) :
                PlayFabRequestCommon(),
                DeviceName(src.DeviceName),
                ForceLink(src.ForceLink),
                PublicKey(src.PublicKey),
                UserName(src.UserName)
            {}

            ~LinkWindowsHelloAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DeviceName")], DeviceName);
                FromJsonUtilP(input[U("ForceLink")], ForceLink);
                FromJsonUtilS(input[U("PublicKey")], PublicKey);
                FromJsonUtilS(input[U("UserName")], UserName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DeviceName; ToJsonUtilS(DeviceName, each_DeviceName); output[U("DeviceName")] = each_DeviceName;
                web::json::value each_ForceLink; ToJsonUtilP(ForceLink, each_ForceLink); output[U("ForceLink")] = each_ForceLink;
                web::json::value each_PublicKey; ToJsonUtilS(PublicKey, each_PublicKey); output[U("PublicKey")] = each_PublicKey;
                web::json::value each_UserName; ToJsonUtilS(UserName, each_UserName); output[U("UserName")] = each_UserName;
                return output;
            }
        };

        struct LinkWindowsHelloAccountResponse : public PlayFabResultCommon
        {

            LinkWindowsHelloAccountResponse() :
                PlayFabResultCommon()
            {}

            LinkWindowsHelloAccountResponse(const LinkWindowsHelloAccountResponse& src) :
                PlayFabResultCommon()
            {}

            ~LinkWindowsHelloAccountResponse() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ListUsersCharactersRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            ListUsersCharactersRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            ListUsersCharactersRequest(const ListUsersCharactersRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~ListUsersCharactersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct ListUsersCharactersResult : public PlayFabResultCommon
        {
            std::list<CharacterResult> Characters;

            ListUsersCharactersResult() :
                PlayFabResultCommon(),
                Characters()
            {}

            ListUsersCharactersResult(const ListUsersCharactersResult& src) :
                PlayFabResultCommon(),
                Characters(src.Characters)
            {}

            ~ListUsersCharactersResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Characters")], Characters);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Characters; ToJsonUtilO(Characters, each_Characters); output[U("Characters")] = each_Characters;
                return output;
            }
        };

        struct UserSettings : public PlayFabBaseModel
        {
            bool GatherDeviceInfo;
            bool NeedsAttribution;

            UserSettings() :
                PlayFabBaseModel(),
                GatherDeviceInfo(),
                NeedsAttribution()
            {}

            UserSettings(const UserSettings& src) :
                PlayFabBaseModel(),
                GatherDeviceInfo(src.GatherDeviceInfo),
                NeedsAttribution(src.NeedsAttribution)
            {}

            ~UserSettings() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("GatherDeviceInfo")], GatherDeviceInfo);
                FromJsonUtilP(input[U("NeedsAttribution")], NeedsAttribution);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GatherDeviceInfo; ToJsonUtilP(GatherDeviceInfo, each_GatherDeviceInfo); output[U("GatherDeviceInfo")] = each_GatherDeviceInfo;
                web::json::value each_NeedsAttribution; ToJsonUtilP(NeedsAttribution, each_NeedsAttribution); output[U("NeedsAttribution")] = each_NeedsAttribution;
                return output;
            }
        };

        struct LoginResult : public PlayFabResultCommon
        {
            Boxed<EntityTokenResponse> EntityToken;
            Boxed<GetPlayerCombinedInfoResultPayload> InfoResultPayload;
            Boxed<time_t> LastLoginTime;
            bool NewlyCreated;
            std::string PlayFabId;
            std::string SessionTicket;
            Boxed<UserSettings> SettingsForUser;

            LoginResult() :
                PlayFabResultCommon(),
                EntityToken(),
                InfoResultPayload(),
                LastLoginTime(),
                NewlyCreated(),
                PlayFabId(),
                SessionTicket(),
                SettingsForUser()
            {}

            LoginResult(const LoginResult& src) :
                PlayFabResultCommon(),
                EntityToken(src.EntityToken),
                InfoResultPayload(src.InfoResultPayload),
                LastLoginTime(src.LastLoginTime),
                NewlyCreated(src.NewlyCreated),
                PlayFabId(src.PlayFabId),
                SessionTicket(src.SessionTicket),
                SettingsForUser(src.SettingsForUser)
            {}

            ~LoginResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("EntityToken")], EntityToken);
                FromJsonUtilO(input[U("InfoResultPayload")], InfoResultPayload);
                FromJsonUtilT(input[U("LastLoginTime")], LastLoginTime);
                FromJsonUtilP(input[U("NewlyCreated")], NewlyCreated);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("SessionTicket")], SessionTicket);
                FromJsonUtilO(input[U("SettingsForUser")], SettingsForUser);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EntityToken; ToJsonUtilO(EntityToken, each_EntityToken); output[U("EntityToken")] = each_EntityToken;
                web::json::value each_InfoResultPayload; ToJsonUtilO(InfoResultPayload, each_InfoResultPayload); output[U("InfoResultPayload")] = each_InfoResultPayload;
                web::json::value each_LastLoginTime; ToJsonUtilT(LastLoginTime, each_LastLoginTime); output[U("LastLoginTime")] = each_LastLoginTime;
                web::json::value each_NewlyCreated; ToJsonUtilP(NewlyCreated, each_NewlyCreated); output[U("NewlyCreated")] = each_NewlyCreated;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_SessionTicket; ToJsonUtilS(SessionTicket, each_SessionTicket); output[U("SessionTicket")] = each_SessionTicket;
                web::json::value each_SettingsForUser; ToJsonUtilO(SettingsForUser, each_SettingsForUser); output[U("SettingsForUser")] = each_SettingsForUser;
                return output;
            }
        };

        struct LoginWithAndroidDeviceIDRequest : public PlayFabRequestCommon
        {
            std::string AndroidDevice;
            std::string AndroidDeviceId;
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string OS;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithAndroidDeviceIDRequest() :
                PlayFabRequestCommon(),
                AndroidDevice(),
                AndroidDeviceId(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                OS(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithAndroidDeviceIDRequest(const LoginWithAndroidDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                AndroidDevice(src.AndroidDevice),
                AndroidDeviceId(src.AndroidDeviceId),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                OS(src.OS),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithAndroidDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AndroidDevice")], AndroidDevice);
                FromJsonUtilS(input[U("AndroidDeviceId")], AndroidDeviceId);
                FromJsonUtilP(input[U("CreateAccount")], CreateAccount);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("OS")], OS);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AndroidDevice; ToJsonUtilS(AndroidDevice, each_AndroidDevice); output[U("AndroidDevice")] = each_AndroidDevice;
                web::json::value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output[U("AndroidDeviceId")] = each_AndroidDeviceId;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[U("CreateAccount")] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_OS; ToJsonUtilS(OS, each_OS); output[U("OS")] = each_OS;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct LoginWithCustomIDRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string CustomId;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithCustomIDRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                CustomId(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithCustomIDRequest(const LoginWithCustomIDRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                CustomId(src.CustomId),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithCustomIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("CreateAccount")], CreateAccount);
                FromJsonUtilS(input[U("CustomId")], CustomId);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[U("CreateAccount")] = each_CreateAccount;
                web::json::value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output[U("CustomId")] = each_CustomId;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct LoginWithEmailAddressRequest : public PlayFabRequestCommon
        {
            std::string Email;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string Password;
            std::string TitleId;

            LoginWithEmailAddressRequest() :
                PlayFabRequestCommon(),
                Email(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                Password(),
                TitleId()
            {}

            LoginWithEmailAddressRequest(const LoginWithEmailAddressRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                Password(src.Password),
                TitleId(src.TitleId)
            {}

            ~LoginWithEmailAddressRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Email")], Email);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("Password")], Password);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[U("Email")] = each_Email;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[U("Password")] = each_Password;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct LoginWithFacebookRequest : public PlayFabRequestCommon
        {
            std::string AccessToken;
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithFacebookRequest() :
                PlayFabRequestCommon(),
                AccessToken(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithFacebookRequest(const LoginWithFacebookRequest& src) :
                PlayFabRequestCommon(),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithFacebookRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AccessToken")], AccessToken);
                FromJsonUtilP(input[U("CreateAccount")], CreateAccount);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output[U("AccessToken")] = each_AccessToken;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[U("CreateAccount")] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct LoginWithGameCenterRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerId;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithGameCenterRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerId(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithGameCenterRequest(const LoginWithGameCenterRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerId(src.PlayerId),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithGameCenterRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("CreateAccount")], CreateAccount);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("PlayerId")], PlayerId);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[U("CreateAccount")] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerId; ToJsonUtilS(PlayerId, each_PlayerId); output[U("PlayerId")] = each_PlayerId;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct LoginWithGoogleAccountRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string ServerAuthCode;
            std::string TitleId;

            LoginWithGoogleAccountRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                ServerAuthCode(),
                TitleId()
            {}

            LoginWithGoogleAccountRequest(const LoginWithGoogleAccountRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                ServerAuthCode(src.ServerAuthCode),
                TitleId(src.TitleId)
            {}

            ~LoginWithGoogleAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("CreateAccount")], CreateAccount);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("ServerAuthCode")], ServerAuthCode);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[U("CreateAccount")] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_ServerAuthCode; ToJsonUtilS(ServerAuthCode, each_ServerAuthCode); output[U("ServerAuthCode")] = each_ServerAuthCode;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct LoginWithIOSDeviceIDRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string DeviceId;
            std::string DeviceModel;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string OS;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithIOSDeviceIDRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                DeviceId(),
                DeviceModel(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                OS(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithIOSDeviceIDRequest(const LoginWithIOSDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                DeviceId(src.DeviceId),
                DeviceModel(src.DeviceModel),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                OS(src.OS),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithIOSDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("CreateAccount")], CreateAccount);
                FromJsonUtilS(input[U("DeviceId")], DeviceId);
                FromJsonUtilS(input[U("DeviceModel")], DeviceModel);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("OS")], OS);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[U("CreateAccount")] = each_CreateAccount;
                web::json::value each_DeviceId; ToJsonUtilS(DeviceId, each_DeviceId); output[U("DeviceId")] = each_DeviceId;
                web::json::value each_DeviceModel; ToJsonUtilS(DeviceModel, each_DeviceModel); output[U("DeviceModel")] = each_DeviceModel;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_OS; ToJsonUtilS(OS, each_OS); output[U("OS")] = each_OS;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct LoginWithKongregateRequest : public PlayFabRequestCommon
        {
            std::string AuthTicket;
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            std::string KongregateId;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithKongregateRequest() :
                PlayFabRequestCommon(),
                AuthTicket(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                KongregateId(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithKongregateRequest(const LoginWithKongregateRequest& src) :
                PlayFabRequestCommon(),
                AuthTicket(src.AuthTicket),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                KongregateId(src.KongregateId),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithKongregateRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AuthTicket")], AuthTicket);
                FromJsonUtilP(input[U("CreateAccount")], CreateAccount);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilS(input[U("KongregateId")], KongregateId);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AuthTicket; ToJsonUtilS(AuthTicket, each_AuthTicket); output[U("AuthTicket")] = each_AuthTicket;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[U("CreateAccount")] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_KongregateId; ToJsonUtilS(KongregateId, each_KongregateId); output[U("KongregateId")] = each_KongregateId;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct LoginWithPlayFabRequest : public PlayFabRequestCommon
        {
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string Password;
            std::string TitleId;
            std::string Username;

            LoginWithPlayFabRequest() :
                PlayFabRequestCommon(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                Password(),
                TitleId(),
                Username()
            {}

            LoginWithPlayFabRequest(const LoginWithPlayFabRequest& src) :
                PlayFabRequestCommon(),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                Password(src.Password),
                TitleId(src.TitleId),
                Username(src.Username)
            {}

            ~LoginWithPlayFabRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("Password")], Password);
                FromJsonUtilS(input[U("TitleId")], TitleId);
                FromJsonUtilS(input[U("Username")], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[U("Password")] = each_Password;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                return output;
            }
        };

        struct LoginWithSteamRequest : public PlayFabRequestCommon
        {
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string SteamTicket;
            std::string TitleId;

            LoginWithSteamRequest() :
                PlayFabRequestCommon(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                SteamTicket(),
                TitleId()
            {}

            LoginWithSteamRequest(const LoginWithSteamRequest& src) :
                PlayFabRequestCommon(),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                SteamTicket(src.SteamTicket),
                TitleId(src.TitleId)
            {}

            ~LoginWithSteamRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("CreateAccount")], CreateAccount);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("SteamTicket")], SteamTicket);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[U("CreateAccount")] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_SteamTicket; ToJsonUtilS(SteamTicket, each_SteamTicket); output[U("SteamTicket")] = each_SteamTicket;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct LoginWithTwitchRequest : public PlayFabRequestCommon
        {
            std::string AccessToken;
            Boxed<bool> CreateAccount;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string TitleId;

            LoginWithTwitchRequest() :
                PlayFabRequestCommon(),
                AccessToken(),
                CreateAccount(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                TitleId()
            {}

            LoginWithTwitchRequest(const LoginWithTwitchRequest& src) :
                PlayFabRequestCommon(),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                TitleId(src.TitleId)
            {}

            ~LoginWithTwitchRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AccessToken")], AccessToken);
                FromJsonUtilP(input[U("CreateAccount")], CreateAccount);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AccessToken; ToJsonUtilS(AccessToken, each_AccessToken); output[U("AccessToken")] = each_AccessToken;
                web::json::value each_CreateAccount; ToJsonUtilP(CreateAccount, each_CreateAccount); output[U("CreateAccount")] = each_CreateAccount;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct LoginWithWindowsHelloRequest : public PlayFabRequestCommon
        {
            std::string ChallengeSignature;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PublicKeyHint;
            std::string TitleId;

            LoginWithWindowsHelloRequest() :
                PlayFabRequestCommon(),
                ChallengeSignature(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PublicKeyHint(),
                TitleId()
            {}

            LoginWithWindowsHelloRequest(const LoginWithWindowsHelloRequest& src) :
                PlayFabRequestCommon(),
                ChallengeSignature(src.ChallengeSignature),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PublicKeyHint(src.PublicKeyHint),
                TitleId(src.TitleId)
            {}

            ~LoginWithWindowsHelloRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ChallengeSignature")], ChallengeSignature);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("PublicKeyHint")], PublicKeyHint);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ChallengeSignature; ToJsonUtilS(ChallengeSignature, each_ChallengeSignature); output[U("ChallengeSignature")] = each_ChallengeSignature;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PublicKeyHint; ToJsonUtilS(PublicKeyHint, each_PublicKeyHint); output[U("PublicKeyHint")] = each_PublicKeyHint;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct MatchmakeRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;
            std::string CharacterId;
            std::string GameMode;
            std::string LobbyId;
            Boxed<Region> pfRegion;
            Boxed<bool> StartNewIfNoneFound;
            std::string StatisticName;
            Boxed<CollectionFilter> TagFilter;

            MatchmakeRequest() :
                PlayFabRequestCommon(),
                BuildVersion(),
                CharacterId(),
                GameMode(),
                LobbyId(),
                pfRegion(),
                StartNewIfNoneFound(),
                StatisticName(),
                TagFilter()
            {}

            MatchmakeRequest(const MatchmakeRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion),
                CharacterId(src.CharacterId),
                GameMode(src.GameMode),
                LobbyId(src.LobbyId),
                pfRegion(src.pfRegion),
                StartNewIfNoneFound(src.StartNewIfNoneFound),
                StatisticName(src.StatisticName),
                TagFilter(src.TagFilter)
            {}

            ~MatchmakeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildVersion")], BuildVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("GameMode")], GameMode);
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
                FromJsonUtilE(input[U("pfRegion")], pfRegion);
                FromJsonUtilP(input[U("StartNewIfNoneFound")], StartNewIfNoneFound);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilO(input[U("TagFilter")], TagFilter);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[U("BuildVersion")] = each_BuildVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[U("GameMode")] = each_GameMode;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                web::json::value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output[U("Region")] = each_pfRegion;
                web::json::value each_StartNewIfNoneFound; ToJsonUtilP(StartNewIfNoneFound, each_StartNewIfNoneFound); output[U("StartNewIfNoneFound")] = each_StartNewIfNoneFound;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_TagFilter; ToJsonUtilO(TagFilter, each_TagFilter); output[U("TagFilter")] = each_TagFilter;
                return output;
            }
        };

        struct MatchmakeResult : public PlayFabResultCommon
        {
            std::string Expires;
            std::string LobbyID;
            Boxed<Int32> PollWaitTimeMS;
            std::string ServerHostname;
            std::string ServerIPV6Address;
            Boxed<Int32> ServerPort;
            Boxed<MatchmakeStatus> Status;
            std::string Ticket;

            MatchmakeResult() :
                PlayFabResultCommon(),
                Expires(),
                LobbyID(),
                PollWaitTimeMS(),
                ServerHostname(),
                ServerIPV6Address(),
                ServerPort(),
                Status(),
                Ticket()
            {}

            MatchmakeResult(const MatchmakeResult& src) :
                PlayFabResultCommon(),
                Expires(src.Expires),
                LobbyID(src.LobbyID),
                PollWaitTimeMS(src.PollWaitTimeMS),
                ServerHostname(src.ServerHostname),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                Status(src.Status),
                Ticket(src.Ticket)
            {}

            ~MatchmakeResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Expires")], Expires);
                FromJsonUtilS(input[U("LobbyID")], LobbyID);
                FromJsonUtilP(input[U("PollWaitTimeMS")], PollWaitTimeMS);
                FromJsonUtilS(input[U("ServerHostname")], ServerHostname);
                FromJsonUtilS(input[U("ServerIPV6Address")], ServerIPV6Address);
                FromJsonUtilP(input[U("ServerPort")], ServerPort);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilS(input[U("Ticket")], Ticket);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Expires; ToJsonUtilS(Expires, each_Expires); output[U("Expires")] = each_Expires;
                web::json::value each_LobbyID; ToJsonUtilS(LobbyID, each_LobbyID); output[U("LobbyID")] = each_LobbyID;
                web::json::value each_PollWaitTimeMS; ToJsonUtilP(PollWaitTimeMS, each_PollWaitTimeMS); output[U("PollWaitTimeMS")] = each_PollWaitTimeMS;
                web::json::value each_ServerHostname; ToJsonUtilS(ServerHostname, each_ServerHostname); output[U("ServerHostname")] = each_ServerHostname;
                web::json::value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output[U("ServerIPV6Address")] = each_ServerIPV6Address;
                web::json::value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output[U("ServerPort")] = each_ServerPort;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
                web::json::value each_Ticket; ToJsonUtilS(Ticket, each_Ticket); output[U("Ticket")] = each_Ticket;
                return output;
            }
        };

        struct ModifyUserVirtualCurrencyResult : public PlayFabResultCommon
        {
            Int32 Balance;
            Int32 BalanceChange;
            std::string PlayFabId;
            std::string VirtualCurrency;

            ModifyUserVirtualCurrencyResult() :
                PlayFabResultCommon(),
                Balance(),
                BalanceChange(),
                PlayFabId(),
                VirtualCurrency()
            {}

            ModifyUserVirtualCurrencyResult(const ModifyUserVirtualCurrencyResult& src) :
                PlayFabResultCommon(),
                Balance(src.Balance),
                BalanceChange(src.BalanceChange),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~ModifyUserVirtualCurrencyResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Balance")], Balance);
                FromJsonUtilP(input[U("BalanceChange")], BalanceChange);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Balance; ToJsonUtilP(Balance, each_Balance); output[U("Balance")] = each_Balance;
                web::json::value each_BalanceChange; ToJsonUtilP(BalanceChange, each_BalanceChange); output[U("BalanceChange")] = each_BalanceChange;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct NameIdentifier : public PlayFabBaseModel
        {
            std::string Id;
            std::string Name;

            NameIdentifier() :
                PlayFabBaseModel(),
                Id(),
                Name()
            {}

            NameIdentifier(const NameIdentifier& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name)
            {}

            ~NameIdentifier() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Id")], Id);
                FromJsonUtilS(input[U("Name")], Name);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Id; ToJsonUtilS(Id, each_Id); output[U("Id")] = each_Id;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                return output;
            }
        };

        struct OpenTradeRequest : public PlayFabRequestCommon
        {
            std::list<std::string> AllowedPlayerIds;
            std::list<std::string> OfferedInventoryInstanceIds;
            std::list<std::string> RequestedCatalogItemIds;

            OpenTradeRequest() :
                PlayFabRequestCommon(),
                AllowedPlayerIds(),
                OfferedInventoryInstanceIds(),
                RequestedCatalogItemIds()
            {}

            OpenTradeRequest(const OpenTradeRequest& src) :
                PlayFabRequestCommon(),
                AllowedPlayerIds(src.AllowedPlayerIds),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds)
            {}

            ~OpenTradeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AllowedPlayerIds")], AllowedPlayerIds);
                FromJsonUtilS(input[U("OfferedInventoryInstanceIds")], OfferedInventoryInstanceIds);
                FromJsonUtilS(input[U("RequestedCatalogItemIds")], RequestedCatalogItemIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AllowedPlayerIds; ToJsonUtilS(AllowedPlayerIds, each_AllowedPlayerIds); output[U("AllowedPlayerIds")] = each_AllowedPlayerIds;
                web::json::value each_OfferedInventoryInstanceIds; ToJsonUtilS(OfferedInventoryInstanceIds, each_OfferedInventoryInstanceIds); output[U("OfferedInventoryInstanceIds")] = each_OfferedInventoryInstanceIds;
                web::json::value each_RequestedCatalogItemIds; ToJsonUtilS(RequestedCatalogItemIds, each_RequestedCatalogItemIds); output[U("RequestedCatalogItemIds")] = each_RequestedCatalogItemIds;
                return output;
            }
        };

        struct OpenTradeResponse : public PlayFabResultCommon
        {
            Boxed<TradeInfo> Trade;

            OpenTradeResponse() :
                PlayFabResultCommon(),
                Trade()
            {}

            OpenTradeResponse(const OpenTradeResponse& src) :
                PlayFabResultCommon(),
                Trade(src.Trade)
            {}

            ~OpenTradeResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Trade")], Trade);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Trade; ToJsonUtilO(Trade, each_Trade); output[U("Trade")] = each_Trade;
                return output;
            }
        };

        struct PayForPurchaseRequest : public PlayFabRequestCommon
        {
            std::string Currency;
            std::string OrderId;
            std::string ProviderName;
            std::string ProviderTransactionId;

            PayForPurchaseRequest() :
                PlayFabRequestCommon(),
                Currency(),
                OrderId(),
                ProviderName(),
                ProviderTransactionId()
            {}

            PayForPurchaseRequest(const PayForPurchaseRequest& src) :
                PlayFabRequestCommon(),
                Currency(src.Currency),
                OrderId(src.OrderId),
                ProviderName(src.ProviderName),
                ProviderTransactionId(src.ProviderTransactionId)
            {}

            ~PayForPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Currency")], Currency);
                FromJsonUtilS(input[U("OrderId")], OrderId);
                FromJsonUtilS(input[U("ProviderName")], ProviderName);
                FromJsonUtilS(input[U("ProviderTransactionId")], ProviderTransactionId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Currency; ToJsonUtilS(Currency, each_Currency); output[U("Currency")] = each_Currency;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[U("OrderId")] = each_OrderId;
                web::json::value each_ProviderName; ToJsonUtilS(ProviderName, each_ProviderName); output[U("ProviderName")] = each_ProviderName;
                web::json::value each_ProviderTransactionId; ToJsonUtilS(ProviderTransactionId, each_ProviderTransactionId); output[U("ProviderTransactionId")] = each_ProviderTransactionId;
                return output;
            }
        };

        struct PayForPurchaseResult : public PlayFabResultCommon
        {
            Uint32 CreditApplied;
            std::string OrderId;
            std::string ProviderData;
            std::string ProviderToken;
            std::string PurchaseConfirmationPageURL;
            std::string PurchaseCurrency;
            Uint32 PurchasePrice;
            Boxed<TransactionStatus> Status;
            std::map<std::string, Int32> VCAmount;
            std::map<std::string, Int32> VirtualCurrency;

            PayForPurchaseResult() :
                PlayFabResultCommon(),
                CreditApplied(),
                OrderId(),
                ProviderData(),
                ProviderToken(),
                PurchaseConfirmationPageURL(),
                PurchaseCurrency(),
                PurchasePrice(),
                Status(),
                VCAmount(),
                VirtualCurrency()
            {}

            PayForPurchaseResult(const PayForPurchaseResult& src) :
                PlayFabResultCommon(),
                CreditApplied(src.CreditApplied),
                OrderId(src.OrderId),
                ProviderData(src.ProviderData),
                ProviderToken(src.ProviderToken),
                PurchaseConfirmationPageURL(src.PurchaseConfirmationPageURL),
                PurchaseCurrency(src.PurchaseCurrency),
                PurchasePrice(src.PurchasePrice),
                Status(src.Status),
                VCAmount(src.VCAmount),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~PayForPurchaseResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("CreditApplied")], CreditApplied);
                FromJsonUtilS(input[U("OrderId")], OrderId);
                FromJsonUtilS(input[U("ProviderData")], ProviderData);
                FromJsonUtilS(input[U("ProviderToken")], ProviderToken);
                FromJsonUtilS(input[U("PurchaseConfirmationPageURL")], PurchaseConfirmationPageURL);
                FromJsonUtilS(input[U("PurchaseCurrency")], PurchaseCurrency);
                FromJsonUtilP(input[U("PurchasePrice")], PurchasePrice);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilP(input[U("VCAmount")], VCAmount);
                FromJsonUtilP(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreditApplied; ToJsonUtilP(CreditApplied, each_CreditApplied); output[U("CreditApplied")] = each_CreditApplied;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[U("OrderId")] = each_OrderId;
                web::json::value each_ProviderData; ToJsonUtilS(ProviderData, each_ProviderData); output[U("ProviderData")] = each_ProviderData;
                web::json::value each_ProviderToken; ToJsonUtilS(ProviderToken, each_ProviderToken); output[U("ProviderToken")] = each_ProviderToken;
                web::json::value each_PurchaseConfirmationPageURL; ToJsonUtilS(PurchaseConfirmationPageURL, each_PurchaseConfirmationPageURL); output[U("PurchaseConfirmationPageURL")] = each_PurchaseConfirmationPageURL;
                web::json::value each_PurchaseCurrency; ToJsonUtilS(PurchaseCurrency, each_PurchaseCurrency); output[U("PurchaseCurrency")] = each_PurchaseCurrency;
                web::json::value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output[U("PurchasePrice")] = each_PurchasePrice;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
                web::json::value each_VCAmount; ToJsonUtilP(VCAmount, each_VCAmount); output[U("VCAmount")] = each_VCAmount;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct PaymentOption : public PlayFabBaseModel
        {
            std::string Currency;
            Uint32 Price;
            std::string ProviderName;
            Uint32 StoreCredit;

            PaymentOption() :
                PlayFabBaseModel(),
                Currency(),
                Price(),
                ProviderName(),
                StoreCredit()
            {}

            PaymentOption(const PaymentOption& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                Price(src.Price),
                ProviderName(src.ProviderName),
                StoreCredit(src.StoreCredit)
            {}

            ~PaymentOption() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Currency")], Currency);
                FromJsonUtilP(input[U("Price")], Price);
                FromJsonUtilS(input[U("ProviderName")], ProviderName);
                FromJsonUtilP(input[U("StoreCredit")], StoreCredit);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Currency; ToJsonUtilS(Currency, each_Currency); output[U("Currency")] = each_Currency;
                web::json::value each_Price; ToJsonUtilP(Price, each_Price); output[U("Price")] = each_Price;
                web::json::value each_ProviderName; ToJsonUtilS(ProviderName, each_ProviderName); output[U("ProviderName")] = each_ProviderName;
                web::json::value each_StoreCredit; ToJsonUtilP(StoreCredit, each_StoreCredit); output[U("StoreCredit")] = each_StoreCredit;
                return output;
            }
        };

        struct PurchaseItemRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ItemId;
            Int32 Price;
            std::string StoreId;
            std::string VirtualCurrency;

            PurchaseItemRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                ItemId(),
                Price(),
                StoreId(),
                VirtualCurrency()
            {}

            PurchaseItemRequest(const PurchaseItemRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ItemId(src.ItemId),
                Price(src.Price),
                StoreId(src.StoreId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~PurchaseItemRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("ItemId")], ItemId);
                FromJsonUtilP(input[U("Price")], Price);
                FromJsonUtilS(input[U("StoreId")], StoreId);
                FromJsonUtilS(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                web::json::value each_Price; ToJsonUtilP(Price, each_Price); output[U("Price")] = each_Price;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[U("StoreId")] = each_StoreId;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct PurchaseItemResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> Items;

            PurchaseItemResult() :
                PlayFabResultCommon(),
                Items()
            {}

            PurchaseItemResult(const PurchaseItemResult& src) :
                PlayFabResultCommon(),
                Items(src.Items)
            {}

            ~PurchaseItemResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Items")], Items);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Items; ToJsonUtilO(Items, each_Items); output[U("Items")] = each_Items;
                return output;
            }
        };

        struct RedeemCouponRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string CouponCode;

            RedeemCouponRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                CouponCode()
            {}

            RedeemCouponRequest(const RedeemCouponRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CouponCode(src.CouponCode)
            {}

            ~RedeemCouponRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("CouponCode")], CouponCode);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CouponCode; ToJsonUtilS(CouponCode, each_CouponCode); output[U("CouponCode")] = each_CouponCode;
                return output;
            }
        };

        struct RedeemCouponResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> GrantedItems;

            RedeemCouponResult() :
                PlayFabResultCommon(),
                GrantedItems()
            {}

            RedeemCouponResult(const RedeemCouponResult& src) :
                PlayFabResultCommon(),
                GrantedItems(src.GrantedItems)
            {}

            ~RedeemCouponResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("GrantedItems")], GrantedItems);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GrantedItems; ToJsonUtilO(GrantedItems, each_GrantedItems); output[U("GrantedItems")] = each_GrantedItems;
                return output;
            }
        };

        struct RegisterForIOSPushNotificationRequest : public PlayFabRequestCommon
        {
            std::string ConfirmationMessage;
            std::string DeviceToken;
            Boxed<bool> SendPushNotificationConfirmation;

            RegisterForIOSPushNotificationRequest() :
                PlayFabRequestCommon(),
                ConfirmationMessage(),
                DeviceToken(),
                SendPushNotificationConfirmation()
            {}

            RegisterForIOSPushNotificationRequest(const RegisterForIOSPushNotificationRequest& src) :
                PlayFabRequestCommon(),
                ConfirmationMessage(src.ConfirmationMessage),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation)
            {}

            ~RegisterForIOSPushNotificationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ConfirmationMessage")], ConfirmationMessage);
                FromJsonUtilS(input[U("DeviceToken")], DeviceToken);
                FromJsonUtilP(input[U("SendPushNotificationConfirmation")], SendPushNotificationConfirmation);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ConfirmationMessage; ToJsonUtilS(ConfirmationMessage, each_ConfirmationMessage); output[U("ConfirmationMessage")] = each_ConfirmationMessage;
                web::json::value each_DeviceToken; ToJsonUtilS(DeviceToken, each_DeviceToken); output[U("DeviceToken")] = each_DeviceToken;
                web::json::value each_SendPushNotificationConfirmation; ToJsonUtilP(SendPushNotificationConfirmation, each_SendPushNotificationConfirmation); output[U("SendPushNotificationConfirmation")] = each_SendPushNotificationConfirmation;
                return output;
            }
        };

        struct RegisterForIOSPushNotificationResult : public PlayFabResultCommon
        {

            RegisterForIOSPushNotificationResult() :
                PlayFabResultCommon()
            {}

            RegisterForIOSPushNotificationResult(const RegisterForIOSPushNotificationResult& src) :
                PlayFabResultCommon()
            {}

            ~RegisterForIOSPushNotificationResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RegisterPlayFabUserRequest : public PlayFabRequestCommon
        {
            std::string DisplayName;
            std::string Email;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string Password;
            std::string PlayerSecret;
            Boxed<bool> RequireBothUsernameAndEmail;
            std::string TitleId;
            std::string Username;

            RegisterPlayFabUserRequest() :
                PlayFabRequestCommon(),
                DisplayName(),
                Email(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                Password(),
                PlayerSecret(),
                RequireBothUsernameAndEmail(),
                TitleId(),
                Username()
            {}

            RegisterPlayFabUserRequest(const RegisterPlayFabUserRequest& src) :
                PlayFabRequestCommon(),
                DisplayName(src.DisplayName),
                Email(src.Email),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                Password(src.Password),
                PlayerSecret(src.PlayerSecret),
                RequireBothUsernameAndEmail(src.RequireBothUsernameAndEmail),
                TitleId(src.TitleId),
                Username(src.Username)
            {}

            ~RegisterPlayFabUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilS(input[U("Email")], Email);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("Password")], Password);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilP(input[U("RequireBothUsernameAndEmail")], RequireBothUsernameAndEmail);
                FromJsonUtilS(input[U("TitleId")], TitleId);
                FromJsonUtilS(input[U("Username")], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[U("Email")] = each_Email;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[U("Password")] = each_Password;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_RequireBothUsernameAndEmail; ToJsonUtilP(RequireBothUsernameAndEmail, each_RequireBothUsernameAndEmail); output[U("RequireBothUsernameAndEmail")] = each_RequireBothUsernameAndEmail;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                return output;
            }
        };

        struct RegisterPlayFabUserResult : public PlayFabResultCommon
        {
            std::string PlayFabId;
            std::string SessionTicket;
            Boxed<UserSettings> SettingsForUser;
            std::string Username;

            RegisterPlayFabUserResult() :
                PlayFabResultCommon(),
                PlayFabId(),
                SessionTicket(),
                SettingsForUser(),
                Username()
            {}

            RegisterPlayFabUserResult(const RegisterPlayFabUserResult& src) :
                PlayFabResultCommon(),
                PlayFabId(src.PlayFabId),
                SessionTicket(src.SessionTicket),
                SettingsForUser(src.SettingsForUser),
                Username(src.Username)
            {}

            ~RegisterPlayFabUserResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("SessionTicket")], SessionTicket);
                FromJsonUtilO(input[U("SettingsForUser")], SettingsForUser);
                FromJsonUtilS(input[U("Username")], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_SessionTicket; ToJsonUtilS(SessionTicket, each_SessionTicket); output[U("SessionTicket")] = each_SessionTicket;
                web::json::value each_SettingsForUser; ToJsonUtilO(SettingsForUser, each_SettingsForUser); output[U("SettingsForUser")] = each_SettingsForUser;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                return output;
            }
        };

        struct RegisterWithWindowsHelloRequest : public PlayFabRequestCommon
        {
            std::string DeviceName;
            std::string EncryptedRequest;
            Boxed<GetPlayerCombinedInfoRequestParams> InfoRequestParameters;
            Boxed<bool> LoginTitlePlayerAccountEntity;
            std::string PlayerSecret;
            std::string PublicKey;
            std::string TitleId;
            std::string UserName;

            RegisterWithWindowsHelloRequest() :
                PlayFabRequestCommon(),
                DeviceName(),
                EncryptedRequest(),
                InfoRequestParameters(),
                LoginTitlePlayerAccountEntity(),
                PlayerSecret(),
                PublicKey(),
                TitleId(),
                UserName()
            {}

            RegisterWithWindowsHelloRequest(const RegisterWithWindowsHelloRequest& src) :
                PlayFabRequestCommon(),
                DeviceName(src.DeviceName),
                EncryptedRequest(src.EncryptedRequest),
                InfoRequestParameters(src.InfoRequestParameters),
                LoginTitlePlayerAccountEntity(src.LoginTitlePlayerAccountEntity),
                PlayerSecret(src.PlayerSecret),
                PublicKey(src.PublicKey),
                TitleId(src.TitleId),
                UserName(src.UserName)
            {}

            ~RegisterWithWindowsHelloRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DeviceName")], DeviceName);
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilO(input[U("InfoRequestParameters")], InfoRequestParameters);
                FromJsonUtilP(input[U("LoginTitlePlayerAccountEntity")], LoginTitlePlayerAccountEntity);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("PublicKey")], PublicKey);
                FromJsonUtilS(input[U("TitleId")], TitleId);
                FromJsonUtilS(input[U("UserName")], UserName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DeviceName; ToJsonUtilS(DeviceName, each_DeviceName); output[U("DeviceName")] = each_DeviceName;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_InfoRequestParameters; ToJsonUtilO(InfoRequestParameters, each_InfoRequestParameters); output[U("InfoRequestParameters")] = each_InfoRequestParameters;
                web::json::value each_LoginTitlePlayerAccountEntity; ToJsonUtilP(LoginTitlePlayerAccountEntity, each_LoginTitlePlayerAccountEntity); output[U("LoginTitlePlayerAccountEntity")] = each_LoginTitlePlayerAccountEntity;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_PublicKey; ToJsonUtilS(PublicKey, each_PublicKey); output[U("PublicKey")] = each_PublicKey;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                web::json::value each_UserName; ToJsonUtilS(UserName, each_UserName); output[U("UserName")] = each_UserName;
                return output;
            }
        };

        struct RemoveContactEmailRequest : public PlayFabRequestCommon
        {

            RemoveContactEmailRequest() :
                PlayFabRequestCommon()
            {}

            RemoveContactEmailRequest(const RemoveContactEmailRequest& src) :
                PlayFabRequestCommon()
            {}

            ~RemoveContactEmailRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveContactEmailResult : public PlayFabResultCommon
        {

            RemoveContactEmailResult() :
                PlayFabResultCommon()
            {}

            RemoveContactEmailResult(const RemoveContactEmailResult& src) :
                PlayFabResultCommon()
            {}

            ~RemoveContactEmailResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveFriendRequest : public PlayFabRequestCommon
        {
            std::string FriendPlayFabId;

            RemoveFriendRequest() :
                PlayFabRequestCommon(),
                FriendPlayFabId()
            {}

            RemoveFriendRequest(const RemoveFriendRequest& src) :
                PlayFabRequestCommon(),
                FriendPlayFabId(src.FriendPlayFabId)
            {}

            ~RemoveFriendRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FriendPlayFabId")], FriendPlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[U("FriendPlayFabId")] = each_FriendPlayFabId;
                return output;
            }
        };

        struct RemoveFriendResult : public PlayFabResultCommon
        {

            RemoveFriendResult() :
                PlayFabResultCommon()
            {}

            RemoveFriendResult(const RemoveFriendResult& src) :
                PlayFabResultCommon()
            {}

            ~RemoveFriendResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveGenericIDRequest : public PlayFabRequestCommon
        {
            GenericServiceId GenericId;

            RemoveGenericIDRequest() :
                PlayFabRequestCommon(),
                GenericId()
            {}

            RemoveGenericIDRequest(const RemoveGenericIDRequest& src) :
                PlayFabRequestCommon(),
                GenericId(src.GenericId)
            {}

            ~RemoveGenericIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("GenericId")], GenericId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GenericId; ToJsonUtilO(GenericId, each_GenericId); output[U("GenericId")] = each_GenericId;
                return output;
            }
        };

        struct RemoveGenericIDResult : public PlayFabResultCommon
        {

            RemoveGenericIDResult() :
                PlayFabResultCommon()
            {}

            RemoveGenericIDResult(const RemoveGenericIDResult& src) :
                PlayFabResultCommon()
            {}

            ~RemoveGenericIDResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveSharedGroupMembersRequest : public PlayFabRequestCommon
        {
            std::list<std::string> PlayFabIds;
            std::string SharedGroupId;

            RemoveSharedGroupMembersRequest() :
                PlayFabRequestCommon(),
                PlayFabIds(),
                SharedGroupId()
            {}

            RemoveSharedGroupMembersRequest(const RemoveSharedGroupMembersRequest& src) :
                PlayFabRequestCommon(),
                PlayFabIds(src.PlayFabIds),
                SharedGroupId(src.SharedGroupId)
            {}

            ~RemoveSharedGroupMembersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabIds")], PlayFabIds);
                FromJsonUtilS(input[U("SharedGroupId")], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabIds; ToJsonUtilS(PlayFabIds, each_PlayFabIds); output[U("PlayFabIds")] = each_PlayFabIds;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[U("SharedGroupId")] = each_SharedGroupId;
                return output;
            }
        };

        struct RemoveSharedGroupMembersResult : public PlayFabResultCommon
        {

            RemoveSharedGroupMembersResult() :
                PlayFabResultCommon()
            {}

            RemoveSharedGroupMembersResult(const RemoveSharedGroupMembersResult& src) :
                PlayFabResultCommon()
            {}

            ~RemoveSharedGroupMembersResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ReportPlayerClientRequest : public PlayFabRequestCommon
        {
            std::string Comment;
            std::string ReporteeId;

            ReportPlayerClientRequest() :
                PlayFabRequestCommon(),
                Comment(),
                ReporteeId()
            {}

            ReportPlayerClientRequest(const ReportPlayerClientRequest& src) :
                PlayFabRequestCommon(),
                Comment(src.Comment),
                ReporteeId(src.ReporteeId)
            {}

            ~ReportPlayerClientRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Comment")], Comment);
                FromJsonUtilS(input[U("ReporteeId")], ReporteeId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[U("Comment")] = each_Comment;
                web::json::value each_ReporteeId; ToJsonUtilS(ReporteeId, each_ReporteeId); output[U("ReporteeId")] = each_ReporteeId;
                return output;
            }
        };

        struct ReportPlayerClientResult : public PlayFabResultCommon
        {
            Int32 SubmissionsRemaining;

            ReportPlayerClientResult() :
                PlayFabResultCommon(),
                SubmissionsRemaining()
            {}

            ReportPlayerClientResult(const ReportPlayerClientResult& src) :
                PlayFabResultCommon(),
                SubmissionsRemaining(src.SubmissionsRemaining)
            {}

            ~ReportPlayerClientResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("SubmissionsRemaining")], SubmissionsRemaining);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SubmissionsRemaining; ToJsonUtilP(SubmissionsRemaining, each_SubmissionsRemaining); output[U("SubmissionsRemaining")] = each_SubmissionsRemaining;
                return output;
            }
        };

        struct RestoreIOSPurchasesRequest : public PlayFabRequestCommon
        {
            std::string ReceiptData;

            RestoreIOSPurchasesRequest() :
                PlayFabRequestCommon(),
                ReceiptData()
            {}

            RestoreIOSPurchasesRequest(const RestoreIOSPurchasesRequest& src) :
                PlayFabRequestCommon(),
                ReceiptData(src.ReceiptData)
            {}

            ~RestoreIOSPurchasesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ReceiptData")], ReceiptData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ReceiptData; ToJsonUtilS(ReceiptData, each_ReceiptData); output[U("ReceiptData")] = each_ReceiptData;
                return output;
            }
        };

        struct RestoreIOSPurchasesResult : public PlayFabResultCommon
        {

            RestoreIOSPurchasesResult() :
                PlayFabResultCommon()
            {}

            RestoreIOSPurchasesResult(const RestoreIOSPurchasesResult& src) :
                PlayFabResultCommon()
            {}

            ~RestoreIOSPurchasesResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SendAccountRecoveryEmailRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string EmailTemplateId;
            std::string TitleId;

            SendAccountRecoveryEmailRequest() :
                PlayFabRequestCommon(),
                Email(),
                EmailTemplateId(),
                TitleId()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                EmailTemplateId(src.EmailTemplateId),
                TitleId(src.TitleId)
            {}

            ~SendAccountRecoveryEmailRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Email")], Email);
                FromJsonUtilS(input[U("EmailTemplateId")], EmailTemplateId);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[U("Email")] = each_Email;
                web::json::value each_EmailTemplateId; ToJsonUtilS(EmailTemplateId, each_EmailTemplateId); output[U("EmailTemplateId")] = each_EmailTemplateId;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct SendAccountRecoveryEmailResult : public PlayFabResultCommon
        {

            SendAccountRecoveryEmailResult() :
                PlayFabResultCommon()
            {}

            SendAccountRecoveryEmailResult(const SendAccountRecoveryEmailResult& src) :
                PlayFabResultCommon()
            {}

            ~SendAccountRecoveryEmailResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetFriendTagsRequest : public PlayFabRequestCommon
        {
            std::string FriendPlayFabId;
            std::list<std::string> Tags;

            SetFriendTagsRequest() :
                PlayFabRequestCommon(),
                FriendPlayFabId(),
                Tags()
            {}

            SetFriendTagsRequest(const SetFriendTagsRequest& src) :
                PlayFabRequestCommon(),
                FriendPlayFabId(src.FriendPlayFabId),
                Tags(src.Tags)
            {}

            ~SetFriendTagsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FriendPlayFabId")], FriendPlayFabId);
                FromJsonUtilS(input[U("Tags")], Tags);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[U("FriendPlayFabId")] = each_FriendPlayFabId;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[U("Tags")] = each_Tags;
                return output;
            }
        };

        struct SetFriendTagsResult : public PlayFabResultCommon
        {

            SetFriendTagsResult() :
                PlayFabResultCommon()
            {}

            SetFriendTagsResult(const SetFriendTagsResult& src) :
                PlayFabResultCommon()
            {}

            ~SetFriendTagsResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetPlayerSecretRequest : public PlayFabRequestCommon
        {
            std::string EncryptedRequest;
            std::string PlayerSecret;

            SetPlayerSecretRequest() :
                PlayFabRequestCommon(),
                EncryptedRequest(),
                PlayerSecret()
            {}

            SetPlayerSecretRequest(const SetPlayerSecretRequest& src) :
                PlayFabRequestCommon(),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret)
            {}

            ~SetPlayerSecretRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("EncryptedRequest")], EncryptedRequest);
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EncryptedRequest; ToJsonUtilS(EncryptedRequest, each_EncryptedRequest); output[U("EncryptedRequest")] = each_EncryptedRequest;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                return output;
            }
        };

        struct SetPlayerSecretResult : public PlayFabResultCommon
        {

            SetPlayerSecretResult() :
                PlayFabResultCommon()
            {}

            SetPlayerSecretResult(const SetPlayerSecretResult& src) :
                PlayFabResultCommon()
            {}

            ~SetPlayerSecretResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct StartGameRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;
            std::string CharacterId;
            std::string CustomCommandLineData;
            std::string GameMode;
            Region pfRegion;
            std::string StatisticName;

            StartGameRequest() :
                PlayFabRequestCommon(),
                BuildVersion(),
                CharacterId(),
                CustomCommandLineData(),
                GameMode(),
                pfRegion(),
                StatisticName()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion),
                CharacterId(src.CharacterId),
                CustomCommandLineData(src.CustomCommandLineData),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion),
                StatisticName(src.StatisticName)
            {}

            ~StartGameRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildVersion")], BuildVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("CustomCommandLineData")], CustomCommandLineData);
                FromJsonUtilS(input[U("GameMode")], GameMode);
                FromJsonEnum(input[U("pfRegion")], pfRegion);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[U("BuildVersion")] = each_BuildVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CustomCommandLineData; ToJsonUtilS(CustomCommandLineData, each_CustomCommandLineData); output[U("CustomCommandLineData")] = each_CustomCommandLineData;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[U("GameMode")] = each_GameMode;
                web::json::value each_pfRegion; ToJsonEnum(pfRegion, each_pfRegion); output[U("Region")] = each_pfRegion;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                return output;
            }
        };

        struct StartGameResult : public PlayFabResultCommon
        {
            std::string Expires;
            std::string LobbyID;
            std::string Password;
            std::string ServerHostname;
            std::string ServerIPV6Address;
            Boxed<Int32> ServerPort;
            std::string Ticket;

            StartGameResult() :
                PlayFabResultCommon(),
                Expires(),
                LobbyID(),
                Password(),
                ServerHostname(),
                ServerIPV6Address(),
                ServerPort(),
                Ticket()
            {}

            StartGameResult(const StartGameResult& src) :
                PlayFabResultCommon(),
                Expires(src.Expires),
                LobbyID(src.LobbyID),
                Password(src.Password),
                ServerHostname(src.ServerHostname),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                Ticket(src.Ticket)
            {}

            ~StartGameResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Expires")], Expires);
                FromJsonUtilS(input[U("LobbyID")], LobbyID);
                FromJsonUtilS(input[U("Password")], Password);
                FromJsonUtilS(input[U("ServerHostname")], ServerHostname);
                FromJsonUtilS(input[U("ServerIPV6Address")], ServerIPV6Address);
                FromJsonUtilP(input[U("ServerPort")], ServerPort);
                FromJsonUtilS(input[U("Ticket")], Ticket);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Expires; ToJsonUtilS(Expires, each_Expires); output[U("Expires")] = each_Expires;
                web::json::value each_LobbyID; ToJsonUtilS(LobbyID, each_LobbyID); output[U("LobbyID")] = each_LobbyID;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[U("Password")] = each_Password;
                web::json::value each_ServerHostname; ToJsonUtilS(ServerHostname, each_ServerHostname); output[U("ServerHostname")] = each_ServerHostname;
                web::json::value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output[U("ServerIPV6Address")] = each_ServerIPV6Address;
                web::json::value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output[U("ServerPort")] = each_ServerPort;
                web::json::value each_Ticket; ToJsonUtilS(Ticket, each_Ticket); output[U("Ticket")] = each_Ticket;
                return output;
            }
        };

        struct StartPurchaseRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::list<ItemPurchaseRequest> Items;
            std::string StoreId;

            StartPurchaseRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                Items(),
                StoreId()
            {}

            StartPurchaseRequest(const StartPurchaseRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                Items(src.Items),
                StoreId(src.StoreId)
            {}

            ~StartPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilO(input[U("Items")], Items);
                FromJsonUtilS(input[U("StoreId")], StoreId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_Items; ToJsonUtilO(Items, each_Items); output[U("Items")] = each_Items;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[U("StoreId")] = each_StoreId;
                return output;
            }
        };

        struct StartPurchaseResult : public PlayFabResultCommon
        {
            std::list<CartItem> Contents;
            std::string OrderId;
            std::list<PaymentOption> PaymentOptions;
            std::map<std::string, Int32> VirtualCurrencyBalances;

            StartPurchaseResult() :
                PlayFabResultCommon(),
                Contents(),
                OrderId(),
                PaymentOptions(),
                VirtualCurrencyBalances()
            {}

            StartPurchaseResult(const StartPurchaseResult& src) :
                PlayFabResultCommon(),
                Contents(src.Contents),
                OrderId(src.OrderId),
                PaymentOptions(src.PaymentOptions),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances)
            {}

            ~StartPurchaseResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Contents")], Contents);
                FromJsonUtilS(input[U("OrderId")], OrderId);
                FromJsonUtilO(input[U("PaymentOptions")], PaymentOptions);
                FromJsonUtilP(input[U("VirtualCurrencyBalances")], VirtualCurrencyBalances);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Contents; ToJsonUtilO(Contents, each_Contents); output[U("Contents")] = each_Contents;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[U("OrderId")] = each_OrderId;
                web::json::value each_PaymentOptions; ToJsonUtilO(PaymentOptions, each_PaymentOptions); output[U("PaymentOptions")] = each_PaymentOptions;
                web::json::value each_VirtualCurrencyBalances; ToJsonUtilP(VirtualCurrencyBalances, each_VirtualCurrencyBalances); output[U("VirtualCurrencyBalances")] = each_VirtualCurrencyBalances;
                return output;
            }
        };

        struct StatisticUpdate : public PlayFabBaseModel
        {
            std::string StatisticName;
            Int32 Value;
            Boxed<Uint32> Version;

            StatisticUpdate() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(),
                Version()
            {}

            StatisticUpdate(const StatisticUpdate& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            ~StatisticUpdate() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilP(input[U("Value")], Value);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_Value; ToJsonUtilP(Value, each_Value); output[U("Value")] = each_Value;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct SubtractUserVirtualCurrencyRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string VirtualCurrency;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabRequestCommon(),
                Amount(),
                VirtualCurrency()
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~SubtractUserVirtualCurrencyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Amount")], Amount);
                FromJsonUtilS(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[U("Amount")] = each_Amount;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct UnlinkAndroidDeviceIDRequest : public PlayFabRequestCommon
        {
            std::string AndroidDeviceId;

            UnlinkAndroidDeviceIDRequest() :
                PlayFabRequestCommon(),
                AndroidDeviceId()
            {}

            UnlinkAndroidDeviceIDRequest(const UnlinkAndroidDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            ~UnlinkAndroidDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AndroidDeviceId")], AndroidDeviceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AndroidDeviceId; ToJsonUtilS(AndroidDeviceId, each_AndroidDeviceId); output[U("AndroidDeviceId")] = each_AndroidDeviceId;
                return output;
            }
        };

        struct UnlinkAndroidDeviceIDResult : public PlayFabResultCommon
        {

            UnlinkAndroidDeviceIDResult() :
                PlayFabResultCommon()
            {}

            UnlinkAndroidDeviceIDResult(const UnlinkAndroidDeviceIDResult& src) :
                PlayFabResultCommon()
            {}

            ~UnlinkAndroidDeviceIDResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkCustomIDRequest : public PlayFabRequestCommon
        {
            std::string CustomId;

            UnlinkCustomIDRequest() :
                PlayFabRequestCommon(),
                CustomId()
            {}

            UnlinkCustomIDRequest(const UnlinkCustomIDRequest& src) :
                PlayFabRequestCommon(),
                CustomId(src.CustomId)
            {}

            ~UnlinkCustomIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CustomId")], CustomId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CustomId; ToJsonUtilS(CustomId, each_CustomId); output[U("CustomId")] = each_CustomId;
                return output;
            }
        };

        struct UnlinkCustomIDResult : public PlayFabResultCommon
        {

            UnlinkCustomIDResult() :
                PlayFabResultCommon()
            {}

            UnlinkCustomIDResult(const UnlinkCustomIDResult& src) :
                PlayFabResultCommon()
            {}

            ~UnlinkCustomIDResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkFacebookAccountRequest : public PlayFabRequestCommon
        {

            UnlinkFacebookAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkFacebookAccountRequest(const UnlinkFacebookAccountRequest& src) :
                PlayFabRequestCommon()
            {}

            ~UnlinkFacebookAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkFacebookAccountResult : public PlayFabResultCommon
        {

            UnlinkFacebookAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkFacebookAccountResult(const UnlinkFacebookAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~UnlinkFacebookAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkGameCenterAccountRequest : public PlayFabRequestCommon
        {

            UnlinkGameCenterAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkGameCenterAccountRequest(const UnlinkGameCenterAccountRequest& src) :
                PlayFabRequestCommon()
            {}

            ~UnlinkGameCenterAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkGameCenterAccountResult : public PlayFabResultCommon
        {

            UnlinkGameCenterAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkGameCenterAccountResult(const UnlinkGameCenterAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~UnlinkGameCenterAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkGoogleAccountRequest : public PlayFabRequestCommon
        {

            UnlinkGoogleAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkGoogleAccountRequest(const UnlinkGoogleAccountRequest& src) :
                PlayFabRequestCommon()
            {}

            ~UnlinkGoogleAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkGoogleAccountResult : public PlayFabResultCommon
        {

            UnlinkGoogleAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkGoogleAccountResult(const UnlinkGoogleAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~UnlinkGoogleAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkIOSDeviceIDRequest : public PlayFabRequestCommon
        {
            std::string DeviceId;

            UnlinkIOSDeviceIDRequest() :
                PlayFabRequestCommon(),
                DeviceId()
            {}

            UnlinkIOSDeviceIDRequest(const UnlinkIOSDeviceIDRequest& src) :
                PlayFabRequestCommon(),
                DeviceId(src.DeviceId)
            {}

            ~UnlinkIOSDeviceIDRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DeviceId")], DeviceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DeviceId; ToJsonUtilS(DeviceId, each_DeviceId); output[U("DeviceId")] = each_DeviceId;
                return output;
            }
        };

        struct UnlinkIOSDeviceIDResult : public PlayFabResultCommon
        {

            UnlinkIOSDeviceIDResult() :
                PlayFabResultCommon()
            {}

            UnlinkIOSDeviceIDResult(const UnlinkIOSDeviceIDResult& src) :
                PlayFabResultCommon()
            {}

            ~UnlinkIOSDeviceIDResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkKongregateAccountRequest : public PlayFabRequestCommon
        {

            UnlinkKongregateAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkKongregateAccountRequest(const UnlinkKongregateAccountRequest& src) :
                PlayFabRequestCommon()
            {}

            ~UnlinkKongregateAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkKongregateAccountResult : public PlayFabResultCommon
        {

            UnlinkKongregateAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkKongregateAccountResult(const UnlinkKongregateAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~UnlinkKongregateAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkSteamAccountRequest : public PlayFabRequestCommon
        {

            UnlinkSteamAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkSteamAccountRequest(const UnlinkSteamAccountRequest& src) :
                PlayFabRequestCommon()
            {}

            ~UnlinkSteamAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkSteamAccountResult : public PlayFabResultCommon
        {

            UnlinkSteamAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkSteamAccountResult(const UnlinkSteamAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~UnlinkSteamAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkTwitchAccountRequest : public PlayFabRequestCommon
        {

            UnlinkTwitchAccountRequest() :
                PlayFabRequestCommon()
            {}

            UnlinkTwitchAccountRequest(const UnlinkTwitchAccountRequest& src) :
                PlayFabRequestCommon()
            {}

            ~UnlinkTwitchAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkTwitchAccountResult : public PlayFabResultCommon
        {

            UnlinkTwitchAccountResult() :
                PlayFabResultCommon()
            {}

            UnlinkTwitchAccountResult(const UnlinkTwitchAccountResult& src) :
                PlayFabResultCommon()
            {}

            ~UnlinkTwitchAccountResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlinkWindowsHelloAccountRequest : public PlayFabRequestCommon
        {
            std::string PublicKeyHint;

            UnlinkWindowsHelloAccountRequest() :
                PlayFabRequestCommon(),
                PublicKeyHint()
            {}

            UnlinkWindowsHelloAccountRequest(const UnlinkWindowsHelloAccountRequest& src) :
                PlayFabRequestCommon(),
                PublicKeyHint(src.PublicKeyHint)
            {}

            ~UnlinkWindowsHelloAccountRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PublicKeyHint")], PublicKeyHint);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PublicKeyHint; ToJsonUtilS(PublicKeyHint, each_PublicKeyHint); output[U("PublicKeyHint")] = each_PublicKeyHint;
                return output;
            }
        };

        struct UnlinkWindowsHelloAccountResponse : public PlayFabResultCommon
        {

            UnlinkWindowsHelloAccountResponse() :
                PlayFabResultCommon()
            {}

            UnlinkWindowsHelloAccountResponse(const UnlinkWindowsHelloAccountResponse& src) :
                PlayFabResultCommon()
            {}

            ~UnlinkWindowsHelloAccountResponse() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UnlockContainerInstanceRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ContainerItemInstanceId;
            std::string KeyItemInstanceId;

            UnlockContainerInstanceRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemInstanceId(),
                KeyItemInstanceId()
            {}

            UnlockContainerInstanceRequest(const UnlockContainerInstanceRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemInstanceId(src.ContainerItemInstanceId),
                KeyItemInstanceId(src.KeyItemInstanceId)
            {}

            ~UnlockContainerInstanceRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("ContainerItemInstanceId")], ContainerItemInstanceId);
                FromJsonUtilS(input[U("KeyItemInstanceId")], KeyItemInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ContainerItemInstanceId; ToJsonUtilS(ContainerItemInstanceId, each_ContainerItemInstanceId); output[U("ContainerItemInstanceId")] = each_ContainerItemInstanceId;
                web::json::value each_KeyItemInstanceId; ToJsonUtilS(KeyItemInstanceId, each_KeyItemInstanceId); output[U("KeyItemInstanceId")] = each_KeyItemInstanceId;
                return output;
            }
        };

        struct UnlockContainerItemRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ContainerItemId;

            UnlockContainerItemRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemId()
            {}

            UnlockContainerItemRequest(const UnlockContainerItemRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemId(src.ContainerItemId)
            {}

            ~UnlockContainerItemRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("ContainerItemId")], ContainerItemId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ContainerItemId; ToJsonUtilS(ContainerItemId, each_ContainerItemId); output[U("ContainerItemId")] = each_ContainerItemId;
                return output;
            }
        };

        struct UnlockContainerItemResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> GrantedItems;
            std::string UnlockedItemInstanceId;
            std::string UnlockedWithItemInstanceId;
            std::map<std::string, Uint32> VirtualCurrency;

            UnlockContainerItemResult() :
                PlayFabResultCommon(),
                GrantedItems(),
                UnlockedItemInstanceId(),
                UnlockedWithItemInstanceId(),
                VirtualCurrency()
            {}

            UnlockContainerItemResult(const UnlockContainerItemResult& src) :
                PlayFabResultCommon(),
                GrantedItems(src.GrantedItems),
                UnlockedItemInstanceId(src.UnlockedItemInstanceId),
                UnlockedWithItemInstanceId(src.UnlockedWithItemInstanceId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~UnlockContainerItemResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("GrantedItems")], GrantedItems);
                FromJsonUtilS(input[U("UnlockedItemInstanceId")], UnlockedItemInstanceId);
                FromJsonUtilS(input[U("UnlockedWithItemInstanceId")], UnlockedWithItemInstanceId);
                FromJsonUtilP(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GrantedItems; ToJsonUtilO(GrantedItems, each_GrantedItems); output[U("GrantedItems")] = each_GrantedItems;
                web::json::value each_UnlockedItemInstanceId; ToJsonUtilS(UnlockedItemInstanceId, each_UnlockedItemInstanceId); output[U("UnlockedItemInstanceId")] = each_UnlockedItemInstanceId;
                web::json::value each_UnlockedWithItemInstanceId; ToJsonUtilS(UnlockedWithItemInstanceId, each_UnlockedWithItemInstanceId); output[U("UnlockedWithItemInstanceId")] = each_UnlockedWithItemInstanceId;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct UpdateAvatarUrlRequest : public PlayFabRequestCommon
        {
            std::string ImageUrl;

            UpdateAvatarUrlRequest() :
                PlayFabRequestCommon(),
                ImageUrl()
            {}

            UpdateAvatarUrlRequest(const UpdateAvatarUrlRequest& src) :
                PlayFabRequestCommon(),
                ImageUrl(src.ImageUrl)
            {}

            ~UpdateAvatarUrlRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ImageUrl")], ImageUrl);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ImageUrl; ToJsonUtilS(ImageUrl, each_ImageUrl); output[U("ImageUrl")] = each_ImageUrl;
                return output;
            }
        };

        struct UpdateCharacterDataRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateCharacterDataRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateCharacterDataRequest(const UpdateCharacterDataRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            ~UpdateCharacterDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("Data")], Data);
                FromJsonUtilS(input[U("KeysToRemove")], KeysToRemove);
                FromJsonUtilE(input[U("Permission")], Permission);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[U("KeysToRemove")] = each_KeysToRemove;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[U("Permission")] = each_Permission;
                return output;
            }
        };

        struct UpdateCharacterDataResult : public PlayFabResultCommon
        {
            Uint32 DataVersion;

            UpdateCharacterDataResult() :
                PlayFabResultCommon(),
                DataVersion()
            {}

            UpdateCharacterDataResult(const UpdateCharacterDataResult& src) :
                PlayFabResultCommon(),
                DataVersion(src.DataVersion)
            {}

            ~UpdateCharacterDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("DataVersion")], DataVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output[U("DataVersion")] = each_DataVersion;
                return output;
            }
        };

        struct UpdateCharacterStatisticsRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::map<std::string, Int32> CharacterStatistics;

            UpdateCharacterStatisticsRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                CharacterStatistics()
            {}

            UpdateCharacterStatisticsRequest(const UpdateCharacterStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics)
            {}

            ~UpdateCharacterStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilP(input[U("CharacterStatistics")], CharacterStatistics);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CharacterStatistics; ToJsonUtilP(CharacterStatistics, each_CharacterStatistics); output[U("CharacterStatistics")] = each_CharacterStatistics;
                return output;
            }
        };

        struct UpdateCharacterStatisticsResult : public PlayFabResultCommon
        {

            UpdateCharacterStatisticsResult() :
                PlayFabResultCommon()
            {}

            UpdateCharacterStatisticsResult(const UpdateCharacterStatisticsResult& src) :
                PlayFabResultCommon()
            {}

            ~UpdateCharacterStatisticsResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdatePlayerStatisticsRequest : public PlayFabRequestCommon
        {
            std::list<StatisticUpdate> Statistics;

            UpdatePlayerStatisticsRequest() :
                PlayFabRequestCommon(),
                Statistics()
            {}

            UpdatePlayerStatisticsRequest(const UpdatePlayerStatisticsRequest& src) :
                PlayFabRequestCommon(),
                Statistics(src.Statistics)
            {}

            ~UpdatePlayerStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Statistics")], Statistics);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Statistics; ToJsonUtilO(Statistics, each_Statistics); output[U("Statistics")] = each_Statistics;
                return output;
            }
        };

        struct UpdatePlayerStatisticsResult : public PlayFabResultCommon
        {

            UpdatePlayerStatisticsResult() :
                PlayFabResultCommon()
            {}

            UpdatePlayerStatisticsResult(const UpdatePlayerStatisticsResult& src) :
                PlayFabResultCommon()
            {}

            ~UpdatePlayerStatisticsResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdateSharedGroupDataRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;
            std::string SharedGroupId;

            UpdateSharedGroupDataRequest() :
                PlayFabRequestCommon(),
                Data(),
                KeysToRemove(),
                Permission(),
                SharedGroupId()
            {}

            UpdateSharedGroupDataRequest(const UpdateSharedGroupDataRequest& src) :
                PlayFabRequestCommon(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                SharedGroupId(src.SharedGroupId)
            {}

            ~UpdateSharedGroupDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Data")], Data);
                FromJsonUtilS(input[U("KeysToRemove")], KeysToRemove);
                FromJsonUtilE(input[U("Permission")], Permission);
                FromJsonUtilS(input[U("SharedGroupId")], SharedGroupId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[U("KeysToRemove")] = each_KeysToRemove;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[U("Permission")] = each_Permission;
                web::json::value each_SharedGroupId; ToJsonUtilS(SharedGroupId, each_SharedGroupId); output[U("SharedGroupId")] = each_SharedGroupId;
                return output;
            }
        };

        struct UpdateSharedGroupDataResult : public PlayFabResultCommon
        {

            UpdateSharedGroupDataResult() :
                PlayFabResultCommon()
            {}

            UpdateSharedGroupDataResult(const UpdateSharedGroupDataResult& src) :
                PlayFabResultCommon()
            {}

            ~UpdateSharedGroupDataResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdateUserDataRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateUserDataRequest() :
                PlayFabRequestCommon(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabRequestCommon(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            ~UpdateUserDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Data")], Data);
                FromJsonUtilS(input[U("KeysToRemove")], KeysToRemove);
                FromJsonUtilE(input[U("Permission")], Permission);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[U("KeysToRemove")] = each_KeysToRemove;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[U("Permission")] = each_Permission;
                return output;
            }
        };

        struct UpdateUserDataResult : public PlayFabResultCommon
        {
            Uint32 DataVersion;

            UpdateUserDataResult() :
                PlayFabResultCommon(),
                DataVersion()
            {}

            UpdateUserDataResult(const UpdateUserDataResult& src) :
                PlayFabResultCommon(),
                DataVersion(src.DataVersion)
            {}

            ~UpdateUserDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("DataVersion")], DataVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output[U("DataVersion")] = each_DataVersion;
                return output;
            }
        };

        struct UpdateUserTitleDisplayNameRequest : public PlayFabRequestCommon
        {
            std::string DisplayName;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabRequestCommon(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabRequestCommon(),
                DisplayName(src.DisplayName)
            {}

            ~UpdateUserTitleDisplayNameRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                return output;
            }
        };

        struct UpdateUserTitleDisplayNameResult : public PlayFabResultCommon
        {
            std::string DisplayName;

            UpdateUserTitleDisplayNameResult() :
                PlayFabResultCommon(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameResult(const UpdateUserTitleDisplayNameResult& src) :
                PlayFabResultCommon(),
                DisplayName(src.DisplayName)
            {}

            ~UpdateUserTitleDisplayNameResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                return output;
            }
        };

        struct ValidateAmazonReceiptRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CurrencyCode;
            Int32 PurchasePrice;
            std::string ReceiptId;
            std::string UserId;

            ValidateAmazonReceiptRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CurrencyCode(),
                PurchasePrice(),
                ReceiptId(),
                UserId()
            {}

            ValidateAmazonReceiptRequest(const ValidateAmazonReceiptRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                ReceiptId(src.ReceiptId),
                UserId(src.UserId)
            {}

            ~ValidateAmazonReceiptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CurrencyCode")], CurrencyCode);
                FromJsonUtilP(input[U("PurchasePrice")], PurchasePrice);
                FromJsonUtilS(input[U("ReceiptId")], ReceiptId);
                FromJsonUtilS(input[U("UserId")], UserId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output[U("CurrencyCode")] = each_CurrencyCode;
                web::json::value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output[U("PurchasePrice")] = each_PurchasePrice;
                web::json::value each_ReceiptId; ToJsonUtilS(ReceiptId, each_ReceiptId); output[U("ReceiptId")] = each_ReceiptId;
                web::json::value each_UserId; ToJsonUtilS(UserId, each_UserId); output[U("UserId")] = each_UserId;
                return output;
            }
        };

        struct ValidateAmazonReceiptResult : public PlayFabResultCommon
        {

            ValidateAmazonReceiptResult() :
                PlayFabResultCommon()
            {}

            ValidateAmazonReceiptResult(const ValidateAmazonReceiptResult& src) :
                PlayFabResultCommon()
            {}

            ~ValidateAmazonReceiptResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ValidateGooglePlayPurchaseRequest : public PlayFabRequestCommon
        {
            std::string CurrencyCode;
            Boxed<Uint32> PurchasePrice;
            std::string ReceiptJson;
            std::string Signature;

            ValidateGooglePlayPurchaseRequest() :
                PlayFabRequestCommon(),
                CurrencyCode(),
                PurchasePrice(),
                ReceiptJson(),
                Signature()
            {}

            ValidateGooglePlayPurchaseRequest(const ValidateGooglePlayPurchaseRequest& src) :
                PlayFabRequestCommon(),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                ReceiptJson(src.ReceiptJson),
                Signature(src.Signature)
            {}

            ~ValidateGooglePlayPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CurrencyCode")], CurrencyCode);
                FromJsonUtilP(input[U("PurchasePrice")], PurchasePrice);
                FromJsonUtilS(input[U("ReceiptJson")], ReceiptJson);
                FromJsonUtilS(input[U("Signature")], Signature);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output[U("CurrencyCode")] = each_CurrencyCode;
                web::json::value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output[U("PurchasePrice")] = each_PurchasePrice;
                web::json::value each_ReceiptJson; ToJsonUtilS(ReceiptJson, each_ReceiptJson); output[U("ReceiptJson")] = each_ReceiptJson;
                web::json::value each_Signature; ToJsonUtilS(Signature, each_Signature); output[U("Signature")] = each_Signature;
                return output;
            }
        };

        struct ValidateGooglePlayPurchaseResult : public PlayFabResultCommon
        {

            ValidateGooglePlayPurchaseResult() :
                PlayFabResultCommon()
            {}

            ValidateGooglePlayPurchaseResult(const ValidateGooglePlayPurchaseResult& src) :
                PlayFabResultCommon()
            {}

            ~ValidateGooglePlayPurchaseResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ValidateIOSReceiptRequest : public PlayFabRequestCommon
        {
            std::string CurrencyCode;
            Int32 PurchasePrice;
            std::string ReceiptData;

            ValidateIOSReceiptRequest() :
                PlayFabRequestCommon(),
                CurrencyCode(),
                PurchasePrice(),
                ReceiptData()
            {}

            ValidateIOSReceiptRequest(const ValidateIOSReceiptRequest& src) :
                PlayFabRequestCommon(),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                ReceiptData(src.ReceiptData)
            {}

            ~ValidateIOSReceiptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CurrencyCode")], CurrencyCode);
                FromJsonUtilP(input[U("PurchasePrice")], PurchasePrice);
                FromJsonUtilS(input[U("ReceiptData")], ReceiptData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output[U("CurrencyCode")] = each_CurrencyCode;
                web::json::value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output[U("PurchasePrice")] = each_PurchasePrice;
                web::json::value each_ReceiptData; ToJsonUtilS(ReceiptData, each_ReceiptData); output[U("ReceiptData")] = each_ReceiptData;
                return output;
            }
        };

        struct ValidateIOSReceiptResult : public PlayFabResultCommon
        {

            ValidateIOSReceiptResult() :
                PlayFabResultCommon()
            {}

            ValidateIOSReceiptResult(const ValidateIOSReceiptResult& src) :
                PlayFabResultCommon()
            {}

            ~ValidateIOSReceiptResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ValidateWindowsReceiptRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CurrencyCode;
            Uint32 PurchasePrice;
            std::string Receipt;

            ValidateWindowsReceiptRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CurrencyCode(),
                PurchasePrice(),
                Receipt()
            {}

            ValidateWindowsReceiptRequest(const ValidateWindowsReceiptRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice),
                Receipt(src.Receipt)
            {}

            ~ValidateWindowsReceiptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CurrencyCode")], CurrencyCode);
                FromJsonUtilP(input[U("PurchasePrice")], PurchasePrice);
                FromJsonUtilS(input[U("Receipt")], Receipt);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output[U("CurrencyCode")] = each_CurrencyCode;
                web::json::value each_PurchasePrice; ToJsonUtilP(PurchasePrice, each_PurchasePrice); output[U("PurchasePrice")] = each_PurchasePrice;
                web::json::value each_Receipt; ToJsonUtilS(Receipt, each_Receipt); output[U("Receipt")] = each_Receipt;
                return output;
            }
        };

        struct ValidateWindowsReceiptResult : public PlayFabResultCommon
        {

            ValidateWindowsReceiptResult() :
                PlayFabResultCommon()
            {}

            ValidateWindowsReceiptResult(const ValidateWindowsReceiptResult& src) :
                PlayFabResultCommon()
            {}

            ~ValidateWindowsReceiptResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct WriteClientCharacterEventRequest : public PlayFabRequestCommon
        {
            web::json::value Body; // Not truly arbitrary. See documentation for restrictions on format
            std::string CharacterId;
            std::string EventName;
            Boxed<time_t> Timestamp;

            WriteClientCharacterEventRequest() :
                PlayFabRequestCommon(),
                Body(),
                CharacterId(),
                EventName(),
                Timestamp()
            {}

            WriteClientCharacterEventRequest(const WriteClientCharacterEventRequest& src) :
                PlayFabRequestCommon(),
                Body(src.Body),
                CharacterId(src.CharacterId),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            ~WriteClientCharacterEventRequest() { }

            void FromJson(web::json::value& input) override
            {
                Body = input[U("Body")];
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("EventName")], EventName);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("Body")] = Body;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_EventName; ToJsonUtilS(EventName, each_EventName); output[U("EventName")] = each_EventName;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
                return output;
            }
        };

        struct WriteClientPlayerEventRequest : public PlayFabRequestCommon
        {
            web::json::value Body; // Not truly arbitrary. See documentation for restrictions on format
            std::string EventName;
            Boxed<time_t> Timestamp;

            WriteClientPlayerEventRequest() :
                PlayFabRequestCommon(),
                Body(),
                EventName(),
                Timestamp()
            {}

            WriteClientPlayerEventRequest(const WriteClientPlayerEventRequest& src) :
                PlayFabRequestCommon(),
                Body(src.Body),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            ~WriteClientPlayerEventRequest() { }

            void FromJson(web::json::value& input) override
            {
                Body = input[U("Body")];
                FromJsonUtilS(input[U("EventName")], EventName);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("Body")] = Body;
                web::json::value each_EventName; ToJsonUtilS(EventName, each_EventName); output[U("EventName")] = each_EventName;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
                return output;
            }
        };

        struct WriteEventResponse : public PlayFabResultCommon
        {
            std::string EventId;

            WriteEventResponse() :
                PlayFabResultCommon(),
                EventId()
            {}

            WriteEventResponse(const WriteEventResponse& src) :
                PlayFabResultCommon(),
                EventId(src.EventId)
            {}

            ~WriteEventResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("EventId")], EventId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EventId; ToJsonUtilS(EventId, each_EventId); output[U("EventId")] = each_EventId;
                return output;
            }
        };

        struct WriteTitleEventRequest : public PlayFabRequestCommon
        {
            web::json::value Body; // Not truly arbitrary. See documentation for restrictions on format
            std::string EventName;
            Boxed<time_t> Timestamp;

            WriteTitleEventRequest() :
                PlayFabRequestCommon(),
                Body(),
                EventName(),
                Timestamp()
            {}

            WriteTitleEventRequest(const WriteTitleEventRequest& src) :
                PlayFabRequestCommon(),
                Body(src.Body),
                EventName(src.EventName),
                Timestamp(src.Timestamp)
            {}

            ~WriteTitleEventRequest() { }

            void FromJson(web::json::value& input) override
            {
                Body = input[U("Body")];
                FromJsonUtilS(input[U("EventName")], EventName);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("Body")] = Body;
                web::json::value each_EventName; ToJsonUtilS(EventName, each_EventName); output[U("EventName")] = each_EventName;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
                return output;
            }
        };

    }
}

#endif
