#pragma once

#ifdef ENABLE_PLAYFABSERVER_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace ServerModels
    {
        // Server Enums
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

        enum GenericErrorCodes
        {
            GenericErrorCodesSuccess,
            GenericErrorCodesInvalidParams,
            GenericErrorCodesAccountNotFound,
            GenericErrorCodesAccountBanned,
            GenericErrorCodesInvalidUsernameOrPassword,
            GenericErrorCodesInvalidTitleId,
            GenericErrorCodesInvalidEmailAddress,
            GenericErrorCodesEmailAddressNotAvailable,
            GenericErrorCodesInvalidUsername,
            GenericErrorCodesInvalidPassword,
            GenericErrorCodesUsernameNotAvailable,
            GenericErrorCodesInvalidSteamTicket,
            GenericErrorCodesAccountAlreadyLinked,
            GenericErrorCodesLinkedAccountAlreadyClaimed,
            GenericErrorCodesInvalidFacebookToken,
            GenericErrorCodesAccountNotLinked,
            GenericErrorCodesFailedByPaymentProvider,
            GenericErrorCodesCouponCodeNotFound,
            GenericErrorCodesInvalidContainerItem,
            GenericErrorCodesContainerNotOwned,
            GenericErrorCodesKeyNotOwned,
            GenericErrorCodesInvalidItemIdInTable,
            GenericErrorCodesInvalidReceipt,
            GenericErrorCodesReceiptAlreadyUsed,
            GenericErrorCodesReceiptCancelled,
            GenericErrorCodesGameNotFound,
            GenericErrorCodesGameModeNotFound,
            GenericErrorCodesInvalidGoogleToken,
            GenericErrorCodesUserIsNotPartOfDeveloper,
            GenericErrorCodesInvalidTitleForDeveloper,
            GenericErrorCodesTitleNameConflicts,
            GenericErrorCodesUserisNotValid,
            GenericErrorCodesValueAlreadyExists,
            GenericErrorCodesBuildNotFound,
            GenericErrorCodesPlayerNotInGame,
            GenericErrorCodesInvalidTicket,
            GenericErrorCodesInvalidDeveloper,
            GenericErrorCodesInvalidOrderInfo,
            GenericErrorCodesRegistrationIncomplete,
            GenericErrorCodesInvalidPlatform,
            GenericErrorCodesUnknownError,
            GenericErrorCodesSteamApplicationNotOwned,
            GenericErrorCodesWrongSteamAccount,
            GenericErrorCodesTitleNotActivated,
            GenericErrorCodesRegistrationSessionNotFound,
            GenericErrorCodesNoSuchMod,
            GenericErrorCodesFileNotFound,
            GenericErrorCodesDuplicateEmail,
            GenericErrorCodesItemNotFound,
            GenericErrorCodesItemNotOwned,
            GenericErrorCodesItemNotRecycleable,
            GenericErrorCodesItemNotAffordable,
            GenericErrorCodesInvalidVirtualCurrency,
            GenericErrorCodesWrongVirtualCurrency,
            GenericErrorCodesWrongPrice,
            GenericErrorCodesNonPositiveValue,
            GenericErrorCodesInvalidRegion,
            GenericErrorCodesRegionAtCapacity,
            GenericErrorCodesServerFailedToStart,
            GenericErrorCodesNameNotAvailable,
            GenericErrorCodesInsufficientFunds,
            GenericErrorCodesInvalidDeviceID,
            GenericErrorCodesInvalidPushNotificationToken,
            GenericErrorCodesNoRemainingUses,
            GenericErrorCodesInvalidPaymentProvider,
            GenericErrorCodesPurchaseInitializationFailure,
            GenericErrorCodesDuplicateUsername,
            GenericErrorCodesInvalidBuyerInfo,
            GenericErrorCodesNoGameModeParamsSet,
            GenericErrorCodesBodyTooLarge,
            GenericErrorCodesReservedWordInBody,
            GenericErrorCodesInvalidTypeInBody,
            GenericErrorCodesInvalidRequest,
            GenericErrorCodesReservedEventName,
            GenericErrorCodesInvalidUserStatistics,
            GenericErrorCodesNotAuthenticated,
            GenericErrorCodesStreamAlreadyExists,
            GenericErrorCodesErrorCreatingStream,
            GenericErrorCodesStreamNotFound,
            GenericErrorCodesInvalidAccount,
            GenericErrorCodesPurchaseDoesNotExist,
            GenericErrorCodesInvalidPurchaseTransactionStatus,
            GenericErrorCodesAPINotEnabledForGameClientAccess,
            GenericErrorCodesNoPushNotificationARNForTitle,
            GenericErrorCodesBuildAlreadyExists,
            GenericErrorCodesBuildPackageDoesNotExist,
            GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle,
            GenericErrorCodesInvalidSharedGroupId,
            GenericErrorCodesNotAuthorized,
            GenericErrorCodesMissingTitleGoogleProperties,
            GenericErrorCodesInvalidItemProperties,
            GenericErrorCodesInvalidPSNAuthCode,
            GenericErrorCodesInvalidItemId,
            GenericErrorCodesPushNotEnabledForAccount,
            GenericErrorCodesPushServiceError,
            GenericErrorCodesReceiptDoesNotContainInAppItems,
            GenericErrorCodesReceiptContainsMultipleInAppItems,
            GenericErrorCodesInvalidBundleID,
            GenericErrorCodesJavascriptException,
            GenericErrorCodesInvalidSessionTicket,
            GenericErrorCodesUnableToConnectToDatabase,
            GenericErrorCodesInternalServerError,
            GenericErrorCodesInvalidReportDate,
            GenericErrorCodesReportNotAvailable,
            GenericErrorCodesDatabaseThroughputExceeded,
            GenericErrorCodesInvalidGameTicket,
            GenericErrorCodesExpiredGameTicket,
            GenericErrorCodesGameTicketDoesNotMatchLobby,
            GenericErrorCodesLinkedDeviceAlreadyClaimed,
            GenericErrorCodesDeviceAlreadyLinked,
            GenericErrorCodesDeviceNotLinked,
            GenericErrorCodesPartialFailure,
            GenericErrorCodesPublisherNotSet,
            GenericErrorCodesServiceUnavailable,
            GenericErrorCodesVersionNotFound,
            GenericErrorCodesRevisionNotFound,
            GenericErrorCodesInvalidPublisherId,
            GenericErrorCodesDownstreamServiceUnavailable,
            GenericErrorCodesAPINotIncludedInTitleUsageTier,
            GenericErrorCodesDAULimitExceeded,
            GenericErrorCodesAPIRequestLimitExceeded,
            GenericErrorCodesInvalidAPIEndpoint,
            GenericErrorCodesBuildNotAvailable,
            GenericErrorCodesConcurrentEditError,
            GenericErrorCodesContentNotFound,
            GenericErrorCodesCharacterNotFound,
            GenericErrorCodesCloudScriptNotFound,
            GenericErrorCodesContentQuotaExceeded,
            GenericErrorCodesInvalidCharacterStatistics,
            GenericErrorCodesPhotonNotEnabledForTitle,
            GenericErrorCodesPhotonApplicationNotFound,
            GenericErrorCodesPhotonApplicationNotAssociatedWithTitle,
            GenericErrorCodesInvalidEmailOrPassword,
            GenericErrorCodesFacebookAPIError,
            GenericErrorCodesInvalidContentType,
            GenericErrorCodesKeyLengthExceeded,
            GenericErrorCodesDataLengthExceeded,
            GenericErrorCodesTooManyKeys,
            GenericErrorCodesFreeTierCannotHaveVirtualCurrency,
            GenericErrorCodesMissingAmazonSharedKey,
            GenericErrorCodesAmazonValidationError,
            GenericErrorCodesInvalidPSNIssuerId,
            GenericErrorCodesPSNInaccessible,
            GenericErrorCodesExpiredAuthToken,
            GenericErrorCodesFailedToGetEntitlements,
            GenericErrorCodesFailedToConsumeEntitlement,
            GenericErrorCodesTradeAcceptingUserNotAllowed,
            GenericErrorCodesTradeInventoryItemIsAssignedToCharacter,
            GenericErrorCodesTradeInventoryItemIsBundle,
            GenericErrorCodesTradeStatusNotValidForCancelling,
            GenericErrorCodesTradeStatusNotValidForAccepting,
            GenericErrorCodesTradeDoesNotExist,
            GenericErrorCodesTradeCancelled,
            GenericErrorCodesTradeAlreadyFilled,
            GenericErrorCodesTradeWaitForStatusTimeout,
            GenericErrorCodesTradeInventoryItemExpired,
            GenericErrorCodesTradeMissingOfferedAndAcceptedItems,
            GenericErrorCodesTradeAcceptedItemIsBundle,
            GenericErrorCodesTradeAcceptedItemIsStackable,
            GenericErrorCodesTradeInventoryItemInvalidStatus,
            GenericErrorCodesTradeAcceptedCatalogItemInvalid,
            GenericErrorCodesTradeAllowedUsersInvalid,
            GenericErrorCodesTradeInventoryItemDoesNotExist,
            GenericErrorCodesTradeInventoryItemIsConsumed,
            GenericErrorCodesTradeInventoryItemIsStackable,
            GenericErrorCodesTradeAcceptedItemsMismatch,
            GenericErrorCodesInvalidKongregateToken,
            GenericErrorCodesFeatureNotConfiguredForTitle,
            GenericErrorCodesNoMatchingCatalogItemForReceipt,
            GenericErrorCodesInvalidCurrencyCode,
            GenericErrorCodesNoRealMoneyPriceForCatalogItem,
            GenericErrorCodesTradeInventoryItemIsNotTradable,
            GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable,
            GenericErrorCodesUsersAlreadyFriends,
            GenericErrorCodesLinkedIdentifierAlreadyClaimed,
            GenericErrorCodesCustomIdNotLinked,
            GenericErrorCodesTotalDataSizeExceeded,
            GenericErrorCodesDeleteKeyConflict,
            GenericErrorCodesInvalidXboxLiveToken,
            GenericErrorCodesExpiredXboxLiveToken,
            GenericErrorCodesResettableStatisticVersionRequired,
            GenericErrorCodesNotAuthorizedByTitle,
            GenericErrorCodesNoPartnerEnabled,
            GenericErrorCodesInvalidPartnerResponse,
            GenericErrorCodesAPINotEnabledForGameServerAccess,
            GenericErrorCodesStatisticNotFound,
            GenericErrorCodesStatisticNameConflict,
            GenericErrorCodesStatisticVersionClosedForWrites,
            GenericErrorCodesStatisticVersionInvalid,
            GenericErrorCodesAPIClientRequestRateLimitExceeded,
            GenericErrorCodesInvalidJSONContent,
            GenericErrorCodesInvalidDropTable,
            GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval,
            GenericErrorCodesStatisticCountLimitExceeded,
            GenericErrorCodesStatisticVersionIncrementRateExceeded,
            GenericErrorCodesContainerKeyInvalid,
            GenericErrorCodesCloudScriptExecutionTimeLimitExceeded,
            GenericErrorCodesNoWritePermissionsForEvent,
            GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded,
            GenericErrorCodesCloudScriptAPIRequestCountExceeded,
            GenericErrorCodesCloudScriptAPIRequestError,
            GenericErrorCodesCloudScriptHTTPRequestError,
            GenericErrorCodesInsufficientGuildRole,
            GenericErrorCodesGuildNotFound,
            GenericErrorCodesOverLimit,
            GenericErrorCodesEventNotFound,
            GenericErrorCodesInvalidEventField,
            GenericErrorCodesInvalidEventName,
            GenericErrorCodesCatalogNotConfigured,
            GenericErrorCodesOperationNotSupportedForPlatform,
            GenericErrorCodesSegmentNotFound,
            GenericErrorCodesStoreNotFound,
            GenericErrorCodesInvalidStatisticName,
            GenericErrorCodesTitleNotQualifiedForLimit,
            GenericErrorCodesInvalidServiceLimitLevel,
            GenericErrorCodesServiceLimitLevelInTransition,
            GenericErrorCodesCouponAlreadyRedeemed,
            GenericErrorCodesGameServerBuildSizeLimitExceeded,
            GenericErrorCodesGameServerBuildCountLimitExceeded,
            GenericErrorCodesVirtualCurrencyCountLimitExceeded,
            GenericErrorCodesVirtualCurrencyCodeExists,
            GenericErrorCodesTitleNewsItemCountLimitExceeded,
            GenericErrorCodesInvalidTwitchToken,
            GenericErrorCodesTwitchResponseError,
            GenericErrorCodesProfaneDisplayName,
            GenericErrorCodesUserAlreadyAdded,
            GenericErrorCodesInvalidVirtualCurrencyCode,
            GenericErrorCodesVirtualCurrencyCannotBeDeleted,
            GenericErrorCodesIdentifierAlreadyClaimed,
            GenericErrorCodesIdentifierNotLinked,
            GenericErrorCodesInvalidContinuationToken,
            GenericErrorCodesExpiredContinuationToken,
            GenericErrorCodesInvalidSegment,
            GenericErrorCodesInvalidSessionId,
            GenericErrorCodesSessionLogNotFound,
            GenericErrorCodesInvalidSearchTerm,
            GenericErrorCodesTwoFactorAuthenticationTokenRequired,
            GenericErrorCodesGameServerHostCountLimitExceeded,
            GenericErrorCodesPlayerTagCountLimitExceeded,
            GenericErrorCodesRequestAlreadyRunning,
            GenericErrorCodesActionGroupNotFound,
            GenericErrorCodesMaximumSegmentBulkActionJobsRunning,
            GenericErrorCodesNoActionsOnPlayersInSegmentJob,
            GenericErrorCodesDuplicateStatisticName,
            GenericErrorCodesScheduledTaskNameConflict,
            GenericErrorCodesScheduledTaskCreateConflict,
            GenericErrorCodesInvalidScheduledTaskName,
            GenericErrorCodesInvalidTaskSchedule,
            GenericErrorCodesSteamNotEnabledForTitle,
            GenericErrorCodesLimitNotAnUpgradeOption,
            GenericErrorCodesNoSecretKeyEnabledForCloudScript,
            GenericErrorCodesTaskNotFound,
            GenericErrorCodesTaskInstanceNotFound,
            GenericErrorCodesInvalidIdentityProviderId,
            GenericErrorCodesMisconfiguredIdentityProvider,
            GenericErrorCodesInvalidScheduledTaskType,
            GenericErrorCodesBillingInformationRequired,
            GenericErrorCodesLimitedEditionItemUnavailable,
            GenericErrorCodesInvalidAdPlacementAndReward,
            GenericErrorCodesAllAdPlacementViewsAlreadyConsumed,
            GenericErrorCodesGoogleOAuthNotConfiguredForTitle,
            GenericErrorCodesGoogleOAuthError,
            GenericErrorCodesUserNotFriend,
            GenericErrorCodesInvalidSignature,
            GenericErrorCodesInvalidPublicKey,
            GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse,
            GenericErrorCodesStatisticUpdateInProgress,
            GenericErrorCodesLeaderboardVersionNotAvailable,
            GenericErrorCodesStatisticAlreadyHasPrizeTable,
            GenericErrorCodesPrizeTableHasOverlappingRanks,
            GenericErrorCodesPrizeTableHasMissingRanks,
            GenericErrorCodesPrizeTableRankStartsAtZero,
            GenericErrorCodesInvalidStatistic,
            GenericErrorCodesExpressionParseFailure,
            GenericErrorCodesExpressionInvokeFailure,
            GenericErrorCodesExpressionTooLong,
            GenericErrorCodesDataUpdateRateExceeded,
            GenericErrorCodesRestrictedEmailDomain,
            GenericErrorCodesEncryptionKeyDisabled,
            GenericErrorCodesEncryptionKeyMissing,
            GenericErrorCodesEncryptionKeyBroken,
            GenericErrorCodesNoSharedSecretKeyConfigured,
            GenericErrorCodesSecretKeyNotFound,
            GenericErrorCodesPlayerSecretAlreadyConfigured,
            GenericErrorCodesAPIRequestsDisabledForTitle,
            GenericErrorCodesInvalidSharedSecretKey,
            GenericErrorCodesPrizeTableHasNoRanks,
            GenericErrorCodesProfileDoesNotExist,
            GenericErrorCodesContentS3OriginBucketNotConfigured,
            GenericErrorCodesInvalidEnvironmentForReceipt,
            GenericErrorCodesEncryptedRequestNotAllowed,
            GenericErrorCodesSignedRequestNotAllowed,
            GenericErrorCodesRequestViewConstraintParamsNotAllowed,
            GenericErrorCodesBadPartnerConfiguration,
            GenericErrorCodesXboxBPCertificateFailure,
            GenericErrorCodesXboxXASSExchangeFailure,
            GenericErrorCodesInvalidEntityId,
            GenericErrorCodesStatisticValueAggregationOverflow,
            GenericErrorCodesEmailMessageFromAddressIsMissing,
            GenericErrorCodesEmailMessageToAddressIsMissing,
            GenericErrorCodesSmtpServerAuthenticationError,
            GenericErrorCodesSmtpServerLimitExceeded,
            GenericErrorCodesSmtpServerInsufficientStorage,
            GenericErrorCodesSmtpServerCommunicationError,
            GenericErrorCodesSmtpServerGeneralFailure,
            GenericErrorCodesEmailClientTimeout,
            GenericErrorCodesEmailClientCanceledTask,
            GenericErrorCodesEmailTemplateMissing,
            GenericErrorCodesInvalidHostForTitleId,
            GenericErrorCodesEmailConfirmationTokenDoesNotExist,
            GenericErrorCodesEmailConfirmationTokenExpired,
            GenericErrorCodesAccountDeleted,
            GenericErrorCodesPlayerSecretNotConfigured,
            GenericErrorCodesInvalidSignatureTime,
            GenericErrorCodesNoContactEmailAddressFound,
            GenericErrorCodesInvalidAuthToken,
            GenericErrorCodesAuthTokenDoesNotExist,
            GenericErrorCodesAuthTokenExpired,
            GenericErrorCodesAuthTokenAlreadyUsedToResetPassword,
            GenericErrorCodesMembershipNameTooLong,
            GenericErrorCodesMembershipNotFound,
            GenericErrorCodesGoogleServiceAccountInvalid,
            GenericErrorCodesGoogleServiceAccountParseFailure,
            GenericErrorCodesEntityTokenMissing,
            GenericErrorCodesEntityTokenInvalid,
            GenericErrorCodesEntityTokenExpired,
            GenericErrorCodesEntityTokenRevoked,
            GenericErrorCodesInvalidProductForSubscription,
            GenericErrorCodesXboxInaccessible,
            GenericErrorCodesSubscriptionAlreadyTaken,
            GenericErrorCodesSmtpAddonNotEnabled,
            GenericErrorCodesAPIConcurrentRequestLimitExceeded,
            GenericErrorCodesXboxRejectedXSTSExchangeRequest,
            GenericErrorCodesVariableNotDefined,
            GenericErrorCodesTemplateVersionNotDefined,
            GenericErrorCodesFileTooLarge,
            GenericErrorCodesTitleDeleted,
            GenericErrorCodesTitleContainsUserAccounts,
            GenericErrorCodesTitleDeletionPlayerCleanupFailure,
            GenericErrorCodesEntityFileOperationPending,
            GenericErrorCodesNoEntityFileOperationPending,
            GenericErrorCodesEntityProfileVersionMismatch,
            GenericErrorCodesTemplateVersionTooOld,
            GenericErrorCodesMembershipDefinitionInUse,
            GenericErrorCodesPaymentPageNotConfigured,
            GenericErrorCodesFailedLoginAttemptRateLimitExceeded,
            GenericErrorCodesEntityBlockedByGroup,
            GenericErrorCodesRoleDoesNotExist,
            GenericErrorCodesEntityIsAlreadyMember,
            GenericErrorCodesDuplicateRoleId,
            GenericErrorCodesGroupInvitationNotFound,
            GenericErrorCodesGroupApplicationNotFound,
            GenericErrorCodesOutstandingInvitationAcceptedInstead,
            GenericErrorCodesOutstandingApplicationAcceptedInstead,
            GenericErrorCodesRoleIsGroupDefaultMember,
            GenericErrorCodesRoleIsGroupAdmin,
            GenericErrorCodesRoleNameNotAvailable,
            GenericErrorCodesGroupNameNotAvailable,
            GenericErrorCodesEmailReportAlreadySent,
            GenericErrorCodesEmailReportRecipientBlacklisted,
            GenericErrorCodesEventNamespaceNotAllowed,
            GenericErrorCodesEventEntityNotAllowed
        };

        inline void ToJsonEnum(const GenericErrorCodes input, web::json::value& output)
        {
            if (input == GenericErrorCodesSuccess) output = web::json::value(U("Success"));
            if (input == GenericErrorCodesInvalidParams) output = web::json::value(U("InvalidParams"));
            if (input == GenericErrorCodesAccountNotFound) output = web::json::value(U("AccountNotFound"));
            if (input == GenericErrorCodesAccountBanned) output = web::json::value(U("AccountBanned"));
            if (input == GenericErrorCodesInvalidUsernameOrPassword) output = web::json::value(U("InvalidUsernameOrPassword"));
            if (input == GenericErrorCodesInvalidTitleId) output = web::json::value(U("InvalidTitleId"));
            if (input == GenericErrorCodesInvalidEmailAddress) output = web::json::value(U("InvalidEmailAddress"));
            if (input == GenericErrorCodesEmailAddressNotAvailable) output = web::json::value(U("EmailAddressNotAvailable"));
            if (input == GenericErrorCodesInvalidUsername) output = web::json::value(U("InvalidUsername"));
            if (input == GenericErrorCodesInvalidPassword) output = web::json::value(U("InvalidPassword"));
            if (input == GenericErrorCodesUsernameNotAvailable) output = web::json::value(U("UsernameNotAvailable"));
            if (input == GenericErrorCodesInvalidSteamTicket) output = web::json::value(U("InvalidSteamTicket"));
            if (input == GenericErrorCodesAccountAlreadyLinked) output = web::json::value(U("AccountAlreadyLinked"));
            if (input == GenericErrorCodesLinkedAccountAlreadyClaimed) output = web::json::value(U("LinkedAccountAlreadyClaimed"));
            if (input == GenericErrorCodesInvalidFacebookToken) output = web::json::value(U("InvalidFacebookToken"));
            if (input == GenericErrorCodesAccountNotLinked) output = web::json::value(U("AccountNotLinked"));
            if (input == GenericErrorCodesFailedByPaymentProvider) output = web::json::value(U("FailedByPaymentProvider"));
            if (input == GenericErrorCodesCouponCodeNotFound) output = web::json::value(U("CouponCodeNotFound"));
            if (input == GenericErrorCodesInvalidContainerItem) output = web::json::value(U("InvalidContainerItem"));
            if (input == GenericErrorCodesContainerNotOwned) output = web::json::value(U("ContainerNotOwned"));
            if (input == GenericErrorCodesKeyNotOwned) output = web::json::value(U("KeyNotOwned"));
            if (input == GenericErrorCodesInvalidItemIdInTable) output = web::json::value(U("InvalidItemIdInTable"));
            if (input == GenericErrorCodesInvalidReceipt) output = web::json::value(U("InvalidReceipt"));
            if (input == GenericErrorCodesReceiptAlreadyUsed) output = web::json::value(U("ReceiptAlreadyUsed"));
            if (input == GenericErrorCodesReceiptCancelled) output = web::json::value(U("ReceiptCancelled"));
            if (input == GenericErrorCodesGameNotFound) output = web::json::value(U("GameNotFound"));
            if (input == GenericErrorCodesGameModeNotFound) output = web::json::value(U("GameModeNotFound"));
            if (input == GenericErrorCodesInvalidGoogleToken) output = web::json::value(U("InvalidGoogleToken"));
            if (input == GenericErrorCodesUserIsNotPartOfDeveloper) output = web::json::value(U("UserIsNotPartOfDeveloper"));
            if (input == GenericErrorCodesInvalidTitleForDeveloper) output = web::json::value(U("InvalidTitleForDeveloper"));
            if (input == GenericErrorCodesTitleNameConflicts) output = web::json::value(U("TitleNameConflicts"));
            if (input == GenericErrorCodesUserisNotValid) output = web::json::value(U("UserisNotValid"));
            if (input == GenericErrorCodesValueAlreadyExists) output = web::json::value(U("ValueAlreadyExists"));
            if (input == GenericErrorCodesBuildNotFound) output = web::json::value(U("BuildNotFound"));
            if (input == GenericErrorCodesPlayerNotInGame) output = web::json::value(U("PlayerNotInGame"));
            if (input == GenericErrorCodesInvalidTicket) output = web::json::value(U("InvalidTicket"));
            if (input == GenericErrorCodesInvalidDeveloper) output = web::json::value(U("InvalidDeveloper"));
            if (input == GenericErrorCodesInvalidOrderInfo) output = web::json::value(U("InvalidOrderInfo"));
            if (input == GenericErrorCodesRegistrationIncomplete) output = web::json::value(U("RegistrationIncomplete"));
            if (input == GenericErrorCodesInvalidPlatform) output = web::json::value(U("InvalidPlatform"));
            if (input == GenericErrorCodesUnknownError) output = web::json::value(U("UnknownError"));
            if (input == GenericErrorCodesSteamApplicationNotOwned) output = web::json::value(U("SteamApplicationNotOwned"));
            if (input == GenericErrorCodesWrongSteamAccount) output = web::json::value(U("WrongSteamAccount"));
            if (input == GenericErrorCodesTitleNotActivated) output = web::json::value(U("TitleNotActivated"));
            if (input == GenericErrorCodesRegistrationSessionNotFound) output = web::json::value(U("RegistrationSessionNotFound"));
            if (input == GenericErrorCodesNoSuchMod) output = web::json::value(U("NoSuchMod"));
            if (input == GenericErrorCodesFileNotFound) output = web::json::value(U("FileNotFound"));
            if (input == GenericErrorCodesDuplicateEmail) output = web::json::value(U("DuplicateEmail"));
            if (input == GenericErrorCodesItemNotFound) output = web::json::value(U("ItemNotFound"));
            if (input == GenericErrorCodesItemNotOwned) output = web::json::value(U("ItemNotOwned"));
            if (input == GenericErrorCodesItemNotRecycleable) output = web::json::value(U("ItemNotRecycleable"));
            if (input == GenericErrorCodesItemNotAffordable) output = web::json::value(U("ItemNotAffordable"));
            if (input == GenericErrorCodesInvalidVirtualCurrency) output = web::json::value(U("InvalidVirtualCurrency"));
            if (input == GenericErrorCodesWrongVirtualCurrency) output = web::json::value(U("WrongVirtualCurrency"));
            if (input == GenericErrorCodesWrongPrice) output = web::json::value(U("WrongPrice"));
            if (input == GenericErrorCodesNonPositiveValue) output = web::json::value(U("NonPositiveValue"));
            if (input == GenericErrorCodesInvalidRegion) output = web::json::value(U("InvalidRegion"));
            if (input == GenericErrorCodesRegionAtCapacity) output = web::json::value(U("RegionAtCapacity"));
            if (input == GenericErrorCodesServerFailedToStart) output = web::json::value(U("ServerFailedToStart"));
            if (input == GenericErrorCodesNameNotAvailable) output = web::json::value(U("NameNotAvailable"));
            if (input == GenericErrorCodesInsufficientFunds) output = web::json::value(U("InsufficientFunds"));
            if (input == GenericErrorCodesInvalidDeviceID) output = web::json::value(U("InvalidDeviceID"));
            if (input == GenericErrorCodesInvalidPushNotificationToken) output = web::json::value(U("InvalidPushNotificationToken"));
            if (input == GenericErrorCodesNoRemainingUses) output = web::json::value(U("NoRemainingUses"));
            if (input == GenericErrorCodesInvalidPaymentProvider) output = web::json::value(U("InvalidPaymentProvider"));
            if (input == GenericErrorCodesPurchaseInitializationFailure) output = web::json::value(U("PurchaseInitializationFailure"));
            if (input == GenericErrorCodesDuplicateUsername) output = web::json::value(U("DuplicateUsername"));
            if (input == GenericErrorCodesInvalidBuyerInfo) output = web::json::value(U("InvalidBuyerInfo"));
            if (input == GenericErrorCodesNoGameModeParamsSet) output = web::json::value(U("NoGameModeParamsSet"));
            if (input == GenericErrorCodesBodyTooLarge) output = web::json::value(U("BodyTooLarge"));
            if (input == GenericErrorCodesReservedWordInBody) output = web::json::value(U("ReservedWordInBody"));
            if (input == GenericErrorCodesInvalidTypeInBody) output = web::json::value(U("InvalidTypeInBody"));
            if (input == GenericErrorCodesInvalidRequest) output = web::json::value(U("InvalidRequest"));
            if (input == GenericErrorCodesReservedEventName) output = web::json::value(U("ReservedEventName"));
            if (input == GenericErrorCodesInvalidUserStatistics) output = web::json::value(U("InvalidUserStatistics"));
            if (input == GenericErrorCodesNotAuthenticated) output = web::json::value(U("NotAuthenticated"));
            if (input == GenericErrorCodesStreamAlreadyExists) output = web::json::value(U("StreamAlreadyExists"));
            if (input == GenericErrorCodesErrorCreatingStream) output = web::json::value(U("ErrorCreatingStream"));
            if (input == GenericErrorCodesStreamNotFound) output = web::json::value(U("StreamNotFound"));
            if (input == GenericErrorCodesInvalidAccount) output = web::json::value(U("InvalidAccount"));
            if (input == GenericErrorCodesPurchaseDoesNotExist) output = web::json::value(U("PurchaseDoesNotExist"));
            if (input == GenericErrorCodesInvalidPurchaseTransactionStatus) output = web::json::value(U("InvalidPurchaseTransactionStatus"));
            if (input == GenericErrorCodesAPINotEnabledForGameClientAccess) output = web::json::value(U("APINotEnabledForGameClientAccess"));
            if (input == GenericErrorCodesNoPushNotificationARNForTitle) output = web::json::value(U("NoPushNotificationARNForTitle"));
            if (input == GenericErrorCodesBuildAlreadyExists) output = web::json::value(U("BuildAlreadyExists"));
            if (input == GenericErrorCodesBuildPackageDoesNotExist) output = web::json::value(U("BuildPackageDoesNotExist"));
            if (input == GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle) output = web::json::value(U("CustomAnalyticsEventsNotEnabledForTitle"));
            if (input == GenericErrorCodesInvalidSharedGroupId) output = web::json::value(U("InvalidSharedGroupId"));
            if (input == GenericErrorCodesNotAuthorized) output = web::json::value(U("NotAuthorized"));
            if (input == GenericErrorCodesMissingTitleGoogleProperties) output = web::json::value(U("MissingTitleGoogleProperties"));
            if (input == GenericErrorCodesInvalidItemProperties) output = web::json::value(U("InvalidItemProperties"));
            if (input == GenericErrorCodesInvalidPSNAuthCode) output = web::json::value(U("InvalidPSNAuthCode"));
            if (input == GenericErrorCodesInvalidItemId) output = web::json::value(U("InvalidItemId"));
            if (input == GenericErrorCodesPushNotEnabledForAccount) output = web::json::value(U("PushNotEnabledForAccount"));
            if (input == GenericErrorCodesPushServiceError) output = web::json::value(U("PushServiceError"));
            if (input == GenericErrorCodesReceiptDoesNotContainInAppItems) output = web::json::value(U("ReceiptDoesNotContainInAppItems"));
            if (input == GenericErrorCodesReceiptContainsMultipleInAppItems) output = web::json::value(U("ReceiptContainsMultipleInAppItems"));
            if (input == GenericErrorCodesInvalidBundleID) output = web::json::value(U("InvalidBundleID"));
            if (input == GenericErrorCodesJavascriptException) output = web::json::value(U("JavascriptException"));
            if (input == GenericErrorCodesInvalidSessionTicket) output = web::json::value(U("InvalidSessionTicket"));
            if (input == GenericErrorCodesUnableToConnectToDatabase) output = web::json::value(U("UnableToConnectToDatabase"));
            if (input == GenericErrorCodesInternalServerError) output = web::json::value(U("InternalServerError"));
            if (input == GenericErrorCodesInvalidReportDate) output = web::json::value(U("InvalidReportDate"));
            if (input == GenericErrorCodesReportNotAvailable) output = web::json::value(U("ReportNotAvailable"));
            if (input == GenericErrorCodesDatabaseThroughputExceeded) output = web::json::value(U("DatabaseThroughputExceeded"));
            if (input == GenericErrorCodesInvalidGameTicket) output = web::json::value(U("InvalidGameTicket"));
            if (input == GenericErrorCodesExpiredGameTicket) output = web::json::value(U("ExpiredGameTicket"));
            if (input == GenericErrorCodesGameTicketDoesNotMatchLobby) output = web::json::value(U("GameTicketDoesNotMatchLobby"));
            if (input == GenericErrorCodesLinkedDeviceAlreadyClaimed) output = web::json::value(U("LinkedDeviceAlreadyClaimed"));
            if (input == GenericErrorCodesDeviceAlreadyLinked) output = web::json::value(U("DeviceAlreadyLinked"));
            if (input == GenericErrorCodesDeviceNotLinked) output = web::json::value(U("DeviceNotLinked"));
            if (input == GenericErrorCodesPartialFailure) output = web::json::value(U("PartialFailure"));
            if (input == GenericErrorCodesPublisherNotSet) output = web::json::value(U("PublisherNotSet"));
            if (input == GenericErrorCodesServiceUnavailable) output = web::json::value(U("ServiceUnavailable"));
            if (input == GenericErrorCodesVersionNotFound) output = web::json::value(U("VersionNotFound"));
            if (input == GenericErrorCodesRevisionNotFound) output = web::json::value(U("RevisionNotFound"));
            if (input == GenericErrorCodesInvalidPublisherId) output = web::json::value(U("InvalidPublisherId"));
            if (input == GenericErrorCodesDownstreamServiceUnavailable) output = web::json::value(U("DownstreamServiceUnavailable"));
            if (input == GenericErrorCodesAPINotIncludedInTitleUsageTier) output = web::json::value(U("APINotIncludedInTitleUsageTier"));
            if (input == GenericErrorCodesDAULimitExceeded) output = web::json::value(U("DAULimitExceeded"));
            if (input == GenericErrorCodesAPIRequestLimitExceeded) output = web::json::value(U("APIRequestLimitExceeded"));
            if (input == GenericErrorCodesInvalidAPIEndpoint) output = web::json::value(U("InvalidAPIEndpoint"));
            if (input == GenericErrorCodesBuildNotAvailable) output = web::json::value(U("BuildNotAvailable"));
            if (input == GenericErrorCodesConcurrentEditError) output = web::json::value(U("ConcurrentEditError"));
            if (input == GenericErrorCodesContentNotFound) output = web::json::value(U("ContentNotFound"));
            if (input == GenericErrorCodesCharacterNotFound) output = web::json::value(U("CharacterNotFound"));
            if (input == GenericErrorCodesCloudScriptNotFound) output = web::json::value(U("CloudScriptNotFound"));
            if (input == GenericErrorCodesContentQuotaExceeded) output = web::json::value(U("ContentQuotaExceeded"));
            if (input == GenericErrorCodesInvalidCharacterStatistics) output = web::json::value(U("InvalidCharacterStatistics"));
            if (input == GenericErrorCodesPhotonNotEnabledForTitle) output = web::json::value(U("PhotonNotEnabledForTitle"));
            if (input == GenericErrorCodesPhotonApplicationNotFound) output = web::json::value(U("PhotonApplicationNotFound"));
            if (input == GenericErrorCodesPhotonApplicationNotAssociatedWithTitle) output = web::json::value(U("PhotonApplicationNotAssociatedWithTitle"));
            if (input == GenericErrorCodesInvalidEmailOrPassword) output = web::json::value(U("InvalidEmailOrPassword"));
            if (input == GenericErrorCodesFacebookAPIError) output = web::json::value(U("FacebookAPIError"));
            if (input == GenericErrorCodesInvalidContentType) output = web::json::value(U("InvalidContentType"));
            if (input == GenericErrorCodesKeyLengthExceeded) output = web::json::value(U("KeyLengthExceeded"));
            if (input == GenericErrorCodesDataLengthExceeded) output = web::json::value(U("DataLengthExceeded"));
            if (input == GenericErrorCodesTooManyKeys) output = web::json::value(U("TooManyKeys"));
            if (input == GenericErrorCodesFreeTierCannotHaveVirtualCurrency) output = web::json::value(U("FreeTierCannotHaveVirtualCurrency"));
            if (input == GenericErrorCodesMissingAmazonSharedKey) output = web::json::value(U("MissingAmazonSharedKey"));
            if (input == GenericErrorCodesAmazonValidationError) output = web::json::value(U("AmazonValidationError"));
            if (input == GenericErrorCodesInvalidPSNIssuerId) output = web::json::value(U("InvalidPSNIssuerId"));
            if (input == GenericErrorCodesPSNInaccessible) output = web::json::value(U("PSNInaccessible"));
            if (input == GenericErrorCodesExpiredAuthToken) output = web::json::value(U("ExpiredAuthToken"));
            if (input == GenericErrorCodesFailedToGetEntitlements) output = web::json::value(U("FailedToGetEntitlements"));
            if (input == GenericErrorCodesFailedToConsumeEntitlement) output = web::json::value(U("FailedToConsumeEntitlement"));
            if (input == GenericErrorCodesTradeAcceptingUserNotAllowed) output = web::json::value(U("TradeAcceptingUserNotAllowed"));
            if (input == GenericErrorCodesTradeInventoryItemIsAssignedToCharacter) output = web::json::value(U("TradeInventoryItemIsAssignedToCharacter"));
            if (input == GenericErrorCodesTradeInventoryItemIsBundle) output = web::json::value(U("TradeInventoryItemIsBundle"));
            if (input == GenericErrorCodesTradeStatusNotValidForCancelling) output = web::json::value(U("TradeStatusNotValidForCancelling"));
            if (input == GenericErrorCodesTradeStatusNotValidForAccepting) output = web::json::value(U("TradeStatusNotValidForAccepting"));
            if (input == GenericErrorCodesTradeDoesNotExist) output = web::json::value(U("TradeDoesNotExist"));
            if (input == GenericErrorCodesTradeCancelled) output = web::json::value(U("TradeCancelled"));
            if (input == GenericErrorCodesTradeAlreadyFilled) output = web::json::value(U("TradeAlreadyFilled"));
            if (input == GenericErrorCodesTradeWaitForStatusTimeout) output = web::json::value(U("TradeWaitForStatusTimeout"));
            if (input == GenericErrorCodesTradeInventoryItemExpired) output = web::json::value(U("TradeInventoryItemExpired"));
            if (input == GenericErrorCodesTradeMissingOfferedAndAcceptedItems) output = web::json::value(U("TradeMissingOfferedAndAcceptedItems"));
            if (input == GenericErrorCodesTradeAcceptedItemIsBundle) output = web::json::value(U("TradeAcceptedItemIsBundle"));
            if (input == GenericErrorCodesTradeAcceptedItemIsStackable) output = web::json::value(U("TradeAcceptedItemIsStackable"));
            if (input == GenericErrorCodesTradeInventoryItemInvalidStatus) output = web::json::value(U("TradeInventoryItemInvalidStatus"));
            if (input == GenericErrorCodesTradeAcceptedCatalogItemInvalid) output = web::json::value(U("TradeAcceptedCatalogItemInvalid"));
            if (input == GenericErrorCodesTradeAllowedUsersInvalid) output = web::json::value(U("TradeAllowedUsersInvalid"));
            if (input == GenericErrorCodesTradeInventoryItemDoesNotExist) output = web::json::value(U("TradeInventoryItemDoesNotExist"));
            if (input == GenericErrorCodesTradeInventoryItemIsConsumed) output = web::json::value(U("TradeInventoryItemIsConsumed"));
            if (input == GenericErrorCodesTradeInventoryItemIsStackable) output = web::json::value(U("TradeInventoryItemIsStackable"));
            if (input == GenericErrorCodesTradeAcceptedItemsMismatch) output = web::json::value(U("TradeAcceptedItemsMismatch"));
            if (input == GenericErrorCodesInvalidKongregateToken) output = web::json::value(U("InvalidKongregateToken"));
            if (input == GenericErrorCodesFeatureNotConfiguredForTitle) output = web::json::value(U("FeatureNotConfiguredForTitle"));
            if (input == GenericErrorCodesNoMatchingCatalogItemForReceipt) output = web::json::value(U("NoMatchingCatalogItemForReceipt"));
            if (input == GenericErrorCodesInvalidCurrencyCode) output = web::json::value(U("InvalidCurrencyCode"));
            if (input == GenericErrorCodesNoRealMoneyPriceForCatalogItem) output = web::json::value(U("NoRealMoneyPriceForCatalogItem"));
            if (input == GenericErrorCodesTradeInventoryItemIsNotTradable) output = web::json::value(U("TradeInventoryItemIsNotTradable"));
            if (input == GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable) output = web::json::value(U("TradeAcceptedCatalogItemIsNotTradable"));
            if (input == GenericErrorCodesUsersAlreadyFriends) output = web::json::value(U("UsersAlreadyFriends"));
            if (input == GenericErrorCodesLinkedIdentifierAlreadyClaimed) output = web::json::value(U("LinkedIdentifierAlreadyClaimed"));
            if (input == GenericErrorCodesCustomIdNotLinked) output = web::json::value(U("CustomIdNotLinked"));
            if (input == GenericErrorCodesTotalDataSizeExceeded) output = web::json::value(U("TotalDataSizeExceeded"));
            if (input == GenericErrorCodesDeleteKeyConflict) output = web::json::value(U("DeleteKeyConflict"));
            if (input == GenericErrorCodesInvalidXboxLiveToken) output = web::json::value(U("InvalidXboxLiveToken"));
            if (input == GenericErrorCodesExpiredXboxLiveToken) output = web::json::value(U("ExpiredXboxLiveToken"));
            if (input == GenericErrorCodesResettableStatisticVersionRequired) output = web::json::value(U("ResettableStatisticVersionRequired"));
            if (input == GenericErrorCodesNotAuthorizedByTitle) output = web::json::value(U("NotAuthorizedByTitle"));
            if (input == GenericErrorCodesNoPartnerEnabled) output = web::json::value(U("NoPartnerEnabled"));
            if (input == GenericErrorCodesInvalidPartnerResponse) output = web::json::value(U("InvalidPartnerResponse"));
            if (input == GenericErrorCodesAPINotEnabledForGameServerAccess) output = web::json::value(U("APINotEnabledForGameServerAccess"));
            if (input == GenericErrorCodesStatisticNotFound) output = web::json::value(U("StatisticNotFound"));
            if (input == GenericErrorCodesStatisticNameConflict) output = web::json::value(U("StatisticNameConflict"));
            if (input == GenericErrorCodesStatisticVersionClosedForWrites) output = web::json::value(U("StatisticVersionClosedForWrites"));
            if (input == GenericErrorCodesStatisticVersionInvalid) output = web::json::value(U("StatisticVersionInvalid"));
            if (input == GenericErrorCodesAPIClientRequestRateLimitExceeded) output = web::json::value(U("APIClientRequestRateLimitExceeded"));
            if (input == GenericErrorCodesInvalidJSONContent) output = web::json::value(U("InvalidJSONContent"));
            if (input == GenericErrorCodesInvalidDropTable) output = web::json::value(U("InvalidDropTable"));
            if (input == GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval) output = web::json::value(U("StatisticVersionAlreadyIncrementedForScheduledInterval"));
            if (input == GenericErrorCodesStatisticCountLimitExceeded) output = web::json::value(U("StatisticCountLimitExceeded"));
            if (input == GenericErrorCodesStatisticVersionIncrementRateExceeded) output = web::json::value(U("StatisticVersionIncrementRateExceeded"));
            if (input == GenericErrorCodesContainerKeyInvalid) output = web::json::value(U("ContainerKeyInvalid"));
            if (input == GenericErrorCodesCloudScriptExecutionTimeLimitExceeded) output = web::json::value(U("CloudScriptExecutionTimeLimitExceeded"));
            if (input == GenericErrorCodesNoWritePermissionsForEvent) output = web::json::value(U("NoWritePermissionsForEvent"));
            if (input == GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded) output = web::json::value(U("CloudScriptFunctionArgumentSizeExceeded"));
            if (input == GenericErrorCodesCloudScriptAPIRequestCountExceeded) output = web::json::value(U("CloudScriptAPIRequestCountExceeded"));
            if (input == GenericErrorCodesCloudScriptAPIRequestError) output = web::json::value(U("CloudScriptAPIRequestError"));
            if (input == GenericErrorCodesCloudScriptHTTPRequestError) output = web::json::value(U("CloudScriptHTTPRequestError"));
            if (input == GenericErrorCodesInsufficientGuildRole) output = web::json::value(U("InsufficientGuildRole"));
            if (input == GenericErrorCodesGuildNotFound) output = web::json::value(U("GuildNotFound"));
            if (input == GenericErrorCodesOverLimit) output = web::json::value(U("OverLimit"));
            if (input == GenericErrorCodesEventNotFound) output = web::json::value(U("EventNotFound"));
            if (input == GenericErrorCodesInvalidEventField) output = web::json::value(U("InvalidEventField"));
            if (input == GenericErrorCodesInvalidEventName) output = web::json::value(U("InvalidEventName"));
            if (input == GenericErrorCodesCatalogNotConfigured) output = web::json::value(U("CatalogNotConfigured"));
            if (input == GenericErrorCodesOperationNotSupportedForPlatform) output = web::json::value(U("OperationNotSupportedForPlatform"));
            if (input == GenericErrorCodesSegmentNotFound) output = web::json::value(U("SegmentNotFound"));
            if (input == GenericErrorCodesStoreNotFound) output = web::json::value(U("StoreNotFound"));
            if (input == GenericErrorCodesInvalidStatisticName) output = web::json::value(U("InvalidStatisticName"));
            if (input == GenericErrorCodesTitleNotQualifiedForLimit) output = web::json::value(U("TitleNotQualifiedForLimit"));
            if (input == GenericErrorCodesInvalidServiceLimitLevel) output = web::json::value(U("InvalidServiceLimitLevel"));
            if (input == GenericErrorCodesServiceLimitLevelInTransition) output = web::json::value(U("ServiceLimitLevelInTransition"));
            if (input == GenericErrorCodesCouponAlreadyRedeemed) output = web::json::value(U("CouponAlreadyRedeemed"));
            if (input == GenericErrorCodesGameServerBuildSizeLimitExceeded) output = web::json::value(U("GameServerBuildSizeLimitExceeded"));
            if (input == GenericErrorCodesGameServerBuildCountLimitExceeded) output = web::json::value(U("GameServerBuildCountLimitExceeded"));
            if (input == GenericErrorCodesVirtualCurrencyCountLimitExceeded) output = web::json::value(U("VirtualCurrencyCountLimitExceeded"));
            if (input == GenericErrorCodesVirtualCurrencyCodeExists) output = web::json::value(U("VirtualCurrencyCodeExists"));
            if (input == GenericErrorCodesTitleNewsItemCountLimitExceeded) output = web::json::value(U("TitleNewsItemCountLimitExceeded"));
            if (input == GenericErrorCodesInvalidTwitchToken) output = web::json::value(U("InvalidTwitchToken"));
            if (input == GenericErrorCodesTwitchResponseError) output = web::json::value(U("TwitchResponseError"));
            if (input == GenericErrorCodesProfaneDisplayName) output = web::json::value(U("ProfaneDisplayName"));
            if (input == GenericErrorCodesUserAlreadyAdded) output = web::json::value(U("UserAlreadyAdded"));
            if (input == GenericErrorCodesInvalidVirtualCurrencyCode) output = web::json::value(U("InvalidVirtualCurrencyCode"));
            if (input == GenericErrorCodesVirtualCurrencyCannotBeDeleted) output = web::json::value(U("VirtualCurrencyCannotBeDeleted"));
            if (input == GenericErrorCodesIdentifierAlreadyClaimed) output = web::json::value(U("IdentifierAlreadyClaimed"));
            if (input == GenericErrorCodesIdentifierNotLinked) output = web::json::value(U("IdentifierNotLinked"));
            if (input == GenericErrorCodesInvalidContinuationToken) output = web::json::value(U("InvalidContinuationToken"));
            if (input == GenericErrorCodesExpiredContinuationToken) output = web::json::value(U("ExpiredContinuationToken"));
            if (input == GenericErrorCodesInvalidSegment) output = web::json::value(U("InvalidSegment"));
            if (input == GenericErrorCodesInvalidSessionId) output = web::json::value(U("InvalidSessionId"));
            if (input == GenericErrorCodesSessionLogNotFound) output = web::json::value(U("SessionLogNotFound"));
            if (input == GenericErrorCodesInvalidSearchTerm) output = web::json::value(U("InvalidSearchTerm"));
            if (input == GenericErrorCodesTwoFactorAuthenticationTokenRequired) output = web::json::value(U("TwoFactorAuthenticationTokenRequired"));
            if (input == GenericErrorCodesGameServerHostCountLimitExceeded) output = web::json::value(U("GameServerHostCountLimitExceeded"));
            if (input == GenericErrorCodesPlayerTagCountLimitExceeded) output = web::json::value(U("PlayerTagCountLimitExceeded"));
            if (input == GenericErrorCodesRequestAlreadyRunning) output = web::json::value(U("RequestAlreadyRunning"));
            if (input == GenericErrorCodesActionGroupNotFound) output = web::json::value(U("ActionGroupNotFound"));
            if (input == GenericErrorCodesMaximumSegmentBulkActionJobsRunning) output = web::json::value(U("MaximumSegmentBulkActionJobsRunning"));
            if (input == GenericErrorCodesNoActionsOnPlayersInSegmentJob) output = web::json::value(U("NoActionsOnPlayersInSegmentJob"));
            if (input == GenericErrorCodesDuplicateStatisticName) output = web::json::value(U("DuplicateStatisticName"));
            if (input == GenericErrorCodesScheduledTaskNameConflict) output = web::json::value(U("ScheduledTaskNameConflict"));
            if (input == GenericErrorCodesScheduledTaskCreateConflict) output = web::json::value(U("ScheduledTaskCreateConflict"));
            if (input == GenericErrorCodesInvalidScheduledTaskName) output = web::json::value(U("InvalidScheduledTaskName"));
            if (input == GenericErrorCodesInvalidTaskSchedule) output = web::json::value(U("InvalidTaskSchedule"));
            if (input == GenericErrorCodesSteamNotEnabledForTitle) output = web::json::value(U("SteamNotEnabledForTitle"));
            if (input == GenericErrorCodesLimitNotAnUpgradeOption) output = web::json::value(U("LimitNotAnUpgradeOption"));
            if (input == GenericErrorCodesNoSecretKeyEnabledForCloudScript) output = web::json::value(U("NoSecretKeyEnabledForCloudScript"));
            if (input == GenericErrorCodesTaskNotFound) output = web::json::value(U("TaskNotFound"));
            if (input == GenericErrorCodesTaskInstanceNotFound) output = web::json::value(U("TaskInstanceNotFound"));
            if (input == GenericErrorCodesInvalidIdentityProviderId) output = web::json::value(U("InvalidIdentityProviderId"));
            if (input == GenericErrorCodesMisconfiguredIdentityProvider) output = web::json::value(U("MisconfiguredIdentityProvider"));
            if (input == GenericErrorCodesInvalidScheduledTaskType) output = web::json::value(U("InvalidScheduledTaskType"));
            if (input == GenericErrorCodesBillingInformationRequired) output = web::json::value(U("BillingInformationRequired"));
            if (input == GenericErrorCodesLimitedEditionItemUnavailable) output = web::json::value(U("LimitedEditionItemUnavailable"));
            if (input == GenericErrorCodesInvalidAdPlacementAndReward) output = web::json::value(U("InvalidAdPlacementAndReward"));
            if (input == GenericErrorCodesAllAdPlacementViewsAlreadyConsumed) output = web::json::value(U("AllAdPlacementViewsAlreadyConsumed"));
            if (input == GenericErrorCodesGoogleOAuthNotConfiguredForTitle) output = web::json::value(U("GoogleOAuthNotConfiguredForTitle"));
            if (input == GenericErrorCodesGoogleOAuthError) output = web::json::value(U("GoogleOAuthError"));
            if (input == GenericErrorCodesUserNotFriend) output = web::json::value(U("UserNotFriend"));
            if (input == GenericErrorCodesInvalidSignature) output = web::json::value(U("InvalidSignature"));
            if (input == GenericErrorCodesInvalidPublicKey) output = web::json::value(U("InvalidPublicKey"));
            if (input == GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse) output = web::json::value(U("GoogleOAuthNoIdTokenIncludedInResponse"));
            if (input == GenericErrorCodesStatisticUpdateInProgress) output = web::json::value(U("StatisticUpdateInProgress"));
            if (input == GenericErrorCodesLeaderboardVersionNotAvailable) output = web::json::value(U("LeaderboardVersionNotAvailable"));
            if (input == GenericErrorCodesStatisticAlreadyHasPrizeTable) output = web::json::value(U("StatisticAlreadyHasPrizeTable"));
            if (input == GenericErrorCodesPrizeTableHasOverlappingRanks) output = web::json::value(U("PrizeTableHasOverlappingRanks"));
            if (input == GenericErrorCodesPrizeTableHasMissingRanks) output = web::json::value(U("PrizeTableHasMissingRanks"));
            if (input == GenericErrorCodesPrizeTableRankStartsAtZero) output = web::json::value(U("PrizeTableRankStartsAtZero"));
            if (input == GenericErrorCodesInvalidStatistic) output = web::json::value(U("InvalidStatistic"));
            if (input == GenericErrorCodesExpressionParseFailure) output = web::json::value(U("ExpressionParseFailure"));
            if (input == GenericErrorCodesExpressionInvokeFailure) output = web::json::value(U("ExpressionInvokeFailure"));
            if (input == GenericErrorCodesExpressionTooLong) output = web::json::value(U("ExpressionTooLong"));
            if (input == GenericErrorCodesDataUpdateRateExceeded) output = web::json::value(U("DataUpdateRateExceeded"));
            if (input == GenericErrorCodesRestrictedEmailDomain) output = web::json::value(U("RestrictedEmailDomain"));
            if (input == GenericErrorCodesEncryptionKeyDisabled) output = web::json::value(U("EncryptionKeyDisabled"));
            if (input == GenericErrorCodesEncryptionKeyMissing) output = web::json::value(U("EncryptionKeyMissing"));
            if (input == GenericErrorCodesEncryptionKeyBroken) output = web::json::value(U("EncryptionKeyBroken"));
            if (input == GenericErrorCodesNoSharedSecretKeyConfigured) output = web::json::value(U("NoSharedSecretKeyConfigured"));
            if (input == GenericErrorCodesSecretKeyNotFound) output = web::json::value(U("SecretKeyNotFound"));
            if (input == GenericErrorCodesPlayerSecretAlreadyConfigured) output = web::json::value(U("PlayerSecretAlreadyConfigured"));
            if (input == GenericErrorCodesAPIRequestsDisabledForTitle) output = web::json::value(U("APIRequestsDisabledForTitle"));
            if (input == GenericErrorCodesInvalidSharedSecretKey) output = web::json::value(U("InvalidSharedSecretKey"));
            if (input == GenericErrorCodesPrizeTableHasNoRanks) output = web::json::value(U("PrizeTableHasNoRanks"));
            if (input == GenericErrorCodesProfileDoesNotExist) output = web::json::value(U("ProfileDoesNotExist"));
            if (input == GenericErrorCodesContentS3OriginBucketNotConfigured) output = web::json::value(U("ContentS3OriginBucketNotConfigured"));
            if (input == GenericErrorCodesInvalidEnvironmentForReceipt) output = web::json::value(U("InvalidEnvironmentForReceipt"));
            if (input == GenericErrorCodesEncryptedRequestNotAllowed) output = web::json::value(U("EncryptedRequestNotAllowed"));
            if (input == GenericErrorCodesSignedRequestNotAllowed) output = web::json::value(U("SignedRequestNotAllowed"));
            if (input == GenericErrorCodesRequestViewConstraintParamsNotAllowed) output = web::json::value(U("RequestViewConstraintParamsNotAllowed"));
            if (input == GenericErrorCodesBadPartnerConfiguration) output = web::json::value(U("BadPartnerConfiguration"));
            if (input == GenericErrorCodesXboxBPCertificateFailure) output = web::json::value(U("XboxBPCertificateFailure"));
            if (input == GenericErrorCodesXboxXASSExchangeFailure) output = web::json::value(U("XboxXASSExchangeFailure"));
            if (input == GenericErrorCodesInvalidEntityId) output = web::json::value(U("InvalidEntityId"));
            if (input == GenericErrorCodesStatisticValueAggregationOverflow) output = web::json::value(U("StatisticValueAggregationOverflow"));
            if (input == GenericErrorCodesEmailMessageFromAddressIsMissing) output = web::json::value(U("EmailMessageFromAddressIsMissing"));
            if (input == GenericErrorCodesEmailMessageToAddressIsMissing) output = web::json::value(U("EmailMessageToAddressIsMissing"));
            if (input == GenericErrorCodesSmtpServerAuthenticationError) output = web::json::value(U("SmtpServerAuthenticationError"));
            if (input == GenericErrorCodesSmtpServerLimitExceeded) output = web::json::value(U("SmtpServerLimitExceeded"));
            if (input == GenericErrorCodesSmtpServerInsufficientStorage) output = web::json::value(U("SmtpServerInsufficientStorage"));
            if (input == GenericErrorCodesSmtpServerCommunicationError) output = web::json::value(U("SmtpServerCommunicationError"));
            if (input == GenericErrorCodesSmtpServerGeneralFailure) output = web::json::value(U("SmtpServerGeneralFailure"));
            if (input == GenericErrorCodesEmailClientTimeout) output = web::json::value(U("EmailClientTimeout"));
            if (input == GenericErrorCodesEmailClientCanceledTask) output = web::json::value(U("EmailClientCanceledTask"));
            if (input == GenericErrorCodesEmailTemplateMissing) output = web::json::value(U("EmailTemplateMissing"));
            if (input == GenericErrorCodesInvalidHostForTitleId) output = web::json::value(U("InvalidHostForTitleId"));
            if (input == GenericErrorCodesEmailConfirmationTokenDoesNotExist) output = web::json::value(U("EmailConfirmationTokenDoesNotExist"));
            if (input == GenericErrorCodesEmailConfirmationTokenExpired) output = web::json::value(U("EmailConfirmationTokenExpired"));
            if (input == GenericErrorCodesAccountDeleted) output = web::json::value(U("AccountDeleted"));
            if (input == GenericErrorCodesPlayerSecretNotConfigured) output = web::json::value(U("PlayerSecretNotConfigured"));
            if (input == GenericErrorCodesInvalidSignatureTime) output = web::json::value(U("InvalidSignatureTime"));
            if (input == GenericErrorCodesNoContactEmailAddressFound) output = web::json::value(U("NoContactEmailAddressFound"));
            if (input == GenericErrorCodesInvalidAuthToken) output = web::json::value(U("InvalidAuthToken"));
            if (input == GenericErrorCodesAuthTokenDoesNotExist) output = web::json::value(U("AuthTokenDoesNotExist"));
            if (input == GenericErrorCodesAuthTokenExpired) output = web::json::value(U("AuthTokenExpired"));
            if (input == GenericErrorCodesAuthTokenAlreadyUsedToResetPassword) output = web::json::value(U("AuthTokenAlreadyUsedToResetPassword"));
            if (input == GenericErrorCodesMembershipNameTooLong) output = web::json::value(U("MembershipNameTooLong"));
            if (input == GenericErrorCodesMembershipNotFound) output = web::json::value(U("MembershipNotFound"));
            if (input == GenericErrorCodesGoogleServiceAccountInvalid) output = web::json::value(U("GoogleServiceAccountInvalid"));
            if (input == GenericErrorCodesGoogleServiceAccountParseFailure) output = web::json::value(U("GoogleServiceAccountParseFailure"));
            if (input == GenericErrorCodesEntityTokenMissing) output = web::json::value(U("EntityTokenMissing"));
            if (input == GenericErrorCodesEntityTokenInvalid) output = web::json::value(U("EntityTokenInvalid"));
            if (input == GenericErrorCodesEntityTokenExpired) output = web::json::value(U("EntityTokenExpired"));
            if (input == GenericErrorCodesEntityTokenRevoked) output = web::json::value(U("EntityTokenRevoked"));
            if (input == GenericErrorCodesInvalidProductForSubscription) output = web::json::value(U("InvalidProductForSubscription"));
            if (input == GenericErrorCodesXboxInaccessible) output = web::json::value(U("XboxInaccessible"));
            if (input == GenericErrorCodesSubscriptionAlreadyTaken) output = web::json::value(U("SubscriptionAlreadyTaken"));
            if (input == GenericErrorCodesSmtpAddonNotEnabled) output = web::json::value(U("SmtpAddonNotEnabled"));
            if (input == GenericErrorCodesAPIConcurrentRequestLimitExceeded) output = web::json::value(U("APIConcurrentRequestLimitExceeded"));
            if (input == GenericErrorCodesXboxRejectedXSTSExchangeRequest) output = web::json::value(U("XboxRejectedXSTSExchangeRequest"));
            if (input == GenericErrorCodesVariableNotDefined) output = web::json::value(U("VariableNotDefined"));
            if (input == GenericErrorCodesTemplateVersionNotDefined) output = web::json::value(U("TemplateVersionNotDefined"));
            if (input == GenericErrorCodesFileTooLarge) output = web::json::value(U("FileTooLarge"));
            if (input == GenericErrorCodesTitleDeleted) output = web::json::value(U("TitleDeleted"));
            if (input == GenericErrorCodesTitleContainsUserAccounts) output = web::json::value(U("TitleContainsUserAccounts"));
            if (input == GenericErrorCodesTitleDeletionPlayerCleanupFailure) output = web::json::value(U("TitleDeletionPlayerCleanupFailure"));
            if (input == GenericErrorCodesEntityFileOperationPending) output = web::json::value(U("EntityFileOperationPending"));
            if (input == GenericErrorCodesNoEntityFileOperationPending) output = web::json::value(U("NoEntityFileOperationPending"));
            if (input == GenericErrorCodesEntityProfileVersionMismatch) output = web::json::value(U("EntityProfileVersionMismatch"));
            if (input == GenericErrorCodesTemplateVersionTooOld) output = web::json::value(U("TemplateVersionTooOld"));
            if (input == GenericErrorCodesMembershipDefinitionInUse) output = web::json::value(U("MembershipDefinitionInUse"));
            if (input == GenericErrorCodesPaymentPageNotConfigured) output = web::json::value(U("PaymentPageNotConfigured"));
            if (input == GenericErrorCodesFailedLoginAttemptRateLimitExceeded) output = web::json::value(U("FailedLoginAttemptRateLimitExceeded"));
            if (input == GenericErrorCodesEntityBlockedByGroup) output = web::json::value(U("EntityBlockedByGroup"));
            if (input == GenericErrorCodesRoleDoesNotExist) output = web::json::value(U("RoleDoesNotExist"));
            if (input == GenericErrorCodesEntityIsAlreadyMember) output = web::json::value(U("EntityIsAlreadyMember"));
            if (input == GenericErrorCodesDuplicateRoleId) output = web::json::value(U("DuplicateRoleId"));
            if (input == GenericErrorCodesGroupInvitationNotFound) output = web::json::value(U("GroupInvitationNotFound"));
            if (input == GenericErrorCodesGroupApplicationNotFound) output = web::json::value(U("GroupApplicationNotFound"));
            if (input == GenericErrorCodesOutstandingInvitationAcceptedInstead) output = web::json::value(U("OutstandingInvitationAcceptedInstead"));
            if (input == GenericErrorCodesOutstandingApplicationAcceptedInstead) output = web::json::value(U("OutstandingApplicationAcceptedInstead"));
            if (input == GenericErrorCodesRoleIsGroupDefaultMember) output = web::json::value(U("RoleIsGroupDefaultMember"));
            if (input == GenericErrorCodesRoleIsGroupAdmin) output = web::json::value(U("RoleIsGroupAdmin"));
            if (input == GenericErrorCodesRoleNameNotAvailable) output = web::json::value(U("RoleNameNotAvailable"));
            if (input == GenericErrorCodesGroupNameNotAvailable) output = web::json::value(U("GroupNameNotAvailable"));
            if (input == GenericErrorCodesEmailReportAlreadySent) output = web::json::value(U("EmailReportAlreadySent"));
            if (input == GenericErrorCodesEmailReportRecipientBlacklisted) output = web::json::value(U("EmailReportRecipientBlacklisted"));
            if (input == GenericErrorCodesEventNamespaceNotAllowed) output = web::json::value(U("EventNamespaceNotAllowed"));
            if (input == GenericErrorCodesEventEntityNotAllowed) output = web::json::value(U("EventEntityNotAllowed"));
        }
        inline void FromJsonEnum(const web::json::value& input, GenericErrorCodes& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Success")) output = GenericErrorCodesSuccess;
            if (inputStr == U("InvalidParams")) output = GenericErrorCodesInvalidParams;
            if (inputStr == U("AccountNotFound")) output = GenericErrorCodesAccountNotFound;
            if (inputStr == U("AccountBanned")) output = GenericErrorCodesAccountBanned;
            if (inputStr == U("InvalidUsernameOrPassword")) output = GenericErrorCodesInvalidUsernameOrPassword;
            if (inputStr == U("InvalidTitleId")) output = GenericErrorCodesInvalidTitleId;
            if (inputStr == U("InvalidEmailAddress")) output = GenericErrorCodesInvalidEmailAddress;
            if (inputStr == U("EmailAddressNotAvailable")) output = GenericErrorCodesEmailAddressNotAvailable;
            if (inputStr == U("InvalidUsername")) output = GenericErrorCodesInvalidUsername;
            if (inputStr == U("InvalidPassword")) output = GenericErrorCodesInvalidPassword;
            if (inputStr == U("UsernameNotAvailable")) output = GenericErrorCodesUsernameNotAvailable;
            if (inputStr == U("InvalidSteamTicket")) output = GenericErrorCodesInvalidSteamTicket;
            if (inputStr == U("AccountAlreadyLinked")) output = GenericErrorCodesAccountAlreadyLinked;
            if (inputStr == U("LinkedAccountAlreadyClaimed")) output = GenericErrorCodesLinkedAccountAlreadyClaimed;
            if (inputStr == U("InvalidFacebookToken")) output = GenericErrorCodesInvalidFacebookToken;
            if (inputStr == U("AccountNotLinked")) output = GenericErrorCodesAccountNotLinked;
            if (inputStr == U("FailedByPaymentProvider")) output = GenericErrorCodesFailedByPaymentProvider;
            if (inputStr == U("CouponCodeNotFound")) output = GenericErrorCodesCouponCodeNotFound;
            if (inputStr == U("InvalidContainerItem")) output = GenericErrorCodesInvalidContainerItem;
            if (inputStr == U("ContainerNotOwned")) output = GenericErrorCodesContainerNotOwned;
            if (inputStr == U("KeyNotOwned")) output = GenericErrorCodesKeyNotOwned;
            if (inputStr == U("InvalidItemIdInTable")) output = GenericErrorCodesInvalidItemIdInTable;
            if (inputStr == U("InvalidReceipt")) output = GenericErrorCodesInvalidReceipt;
            if (inputStr == U("ReceiptAlreadyUsed")) output = GenericErrorCodesReceiptAlreadyUsed;
            if (inputStr == U("ReceiptCancelled")) output = GenericErrorCodesReceiptCancelled;
            if (inputStr == U("GameNotFound")) output = GenericErrorCodesGameNotFound;
            if (inputStr == U("GameModeNotFound")) output = GenericErrorCodesGameModeNotFound;
            if (inputStr == U("InvalidGoogleToken")) output = GenericErrorCodesInvalidGoogleToken;
            if (inputStr == U("UserIsNotPartOfDeveloper")) output = GenericErrorCodesUserIsNotPartOfDeveloper;
            if (inputStr == U("InvalidTitleForDeveloper")) output = GenericErrorCodesInvalidTitleForDeveloper;
            if (inputStr == U("TitleNameConflicts")) output = GenericErrorCodesTitleNameConflicts;
            if (inputStr == U("UserisNotValid")) output = GenericErrorCodesUserisNotValid;
            if (inputStr == U("ValueAlreadyExists")) output = GenericErrorCodesValueAlreadyExists;
            if (inputStr == U("BuildNotFound")) output = GenericErrorCodesBuildNotFound;
            if (inputStr == U("PlayerNotInGame")) output = GenericErrorCodesPlayerNotInGame;
            if (inputStr == U("InvalidTicket")) output = GenericErrorCodesInvalidTicket;
            if (inputStr == U("InvalidDeveloper")) output = GenericErrorCodesInvalidDeveloper;
            if (inputStr == U("InvalidOrderInfo")) output = GenericErrorCodesInvalidOrderInfo;
            if (inputStr == U("RegistrationIncomplete")) output = GenericErrorCodesRegistrationIncomplete;
            if (inputStr == U("InvalidPlatform")) output = GenericErrorCodesInvalidPlatform;
            if (inputStr == U("UnknownError")) output = GenericErrorCodesUnknownError;
            if (inputStr == U("SteamApplicationNotOwned")) output = GenericErrorCodesSteamApplicationNotOwned;
            if (inputStr == U("WrongSteamAccount")) output = GenericErrorCodesWrongSteamAccount;
            if (inputStr == U("TitleNotActivated")) output = GenericErrorCodesTitleNotActivated;
            if (inputStr == U("RegistrationSessionNotFound")) output = GenericErrorCodesRegistrationSessionNotFound;
            if (inputStr == U("NoSuchMod")) output = GenericErrorCodesNoSuchMod;
            if (inputStr == U("FileNotFound")) output = GenericErrorCodesFileNotFound;
            if (inputStr == U("DuplicateEmail")) output = GenericErrorCodesDuplicateEmail;
            if (inputStr == U("ItemNotFound")) output = GenericErrorCodesItemNotFound;
            if (inputStr == U("ItemNotOwned")) output = GenericErrorCodesItemNotOwned;
            if (inputStr == U("ItemNotRecycleable")) output = GenericErrorCodesItemNotRecycleable;
            if (inputStr == U("ItemNotAffordable")) output = GenericErrorCodesItemNotAffordable;
            if (inputStr == U("InvalidVirtualCurrency")) output = GenericErrorCodesInvalidVirtualCurrency;
            if (inputStr == U("WrongVirtualCurrency")) output = GenericErrorCodesWrongVirtualCurrency;
            if (inputStr == U("WrongPrice")) output = GenericErrorCodesWrongPrice;
            if (inputStr == U("NonPositiveValue")) output = GenericErrorCodesNonPositiveValue;
            if (inputStr == U("InvalidRegion")) output = GenericErrorCodesInvalidRegion;
            if (inputStr == U("RegionAtCapacity")) output = GenericErrorCodesRegionAtCapacity;
            if (inputStr == U("ServerFailedToStart")) output = GenericErrorCodesServerFailedToStart;
            if (inputStr == U("NameNotAvailable")) output = GenericErrorCodesNameNotAvailable;
            if (inputStr == U("InsufficientFunds")) output = GenericErrorCodesInsufficientFunds;
            if (inputStr == U("InvalidDeviceID")) output = GenericErrorCodesInvalidDeviceID;
            if (inputStr == U("InvalidPushNotificationToken")) output = GenericErrorCodesInvalidPushNotificationToken;
            if (inputStr == U("NoRemainingUses")) output = GenericErrorCodesNoRemainingUses;
            if (inputStr == U("InvalidPaymentProvider")) output = GenericErrorCodesInvalidPaymentProvider;
            if (inputStr == U("PurchaseInitializationFailure")) output = GenericErrorCodesPurchaseInitializationFailure;
            if (inputStr == U("DuplicateUsername")) output = GenericErrorCodesDuplicateUsername;
            if (inputStr == U("InvalidBuyerInfo")) output = GenericErrorCodesInvalidBuyerInfo;
            if (inputStr == U("NoGameModeParamsSet")) output = GenericErrorCodesNoGameModeParamsSet;
            if (inputStr == U("BodyTooLarge")) output = GenericErrorCodesBodyTooLarge;
            if (inputStr == U("ReservedWordInBody")) output = GenericErrorCodesReservedWordInBody;
            if (inputStr == U("InvalidTypeInBody")) output = GenericErrorCodesInvalidTypeInBody;
            if (inputStr == U("InvalidRequest")) output = GenericErrorCodesInvalidRequest;
            if (inputStr == U("ReservedEventName")) output = GenericErrorCodesReservedEventName;
            if (inputStr == U("InvalidUserStatistics")) output = GenericErrorCodesInvalidUserStatistics;
            if (inputStr == U("NotAuthenticated")) output = GenericErrorCodesNotAuthenticated;
            if (inputStr == U("StreamAlreadyExists")) output = GenericErrorCodesStreamAlreadyExists;
            if (inputStr == U("ErrorCreatingStream")) output = GenericErrorCodesErrorCreatingStream;
            if (inputStr == U("StreamNotFound")) output = GenericErrorCodesStreamNotFound;
            if (inputStr == U("InvalidAccount")) output = GenericErrorCodesInvalidAccount;
            if (inputStr == U("PurchaseDoesNotExist")) output = GenericErrorCodesPurchaseDoesNotExist;
            if (inputStr == U("InvalidPurchaseTransactionStatus")) output = GenericErrorCodesInvalidPurchaseTransactionStatus;
            if (inputStr == U("APINotEnabledForGameClientAccess")) output = GenericErrorCodesAPINotEnabledForGameClientAccess;
            if (inputStr == U("NoPushNotificationARNForTitle")) output = GenericErrorCodesNoPushNotificationARNForTitle;
            if (inputStr == U("BuildAlreadyExists")) output = GenericErrorCodesBuildAlreadyExists;
            if (inputStr == U("BuildPackageDoesNotExist")) output = GenericErrorCodesBuildPackageDoesNotExist;
            if (inputStr == U("CustomAnalyticsEventsNotEnabledForTitle")) output = GenericErrorCodesCustomAnalyticsEventsNotEnabledForTitle;
            if (inputStr == U("InvalidSharedGroupId")) output = GenericErrorCodesInvalidSharedGroupId;
            if (inputStr == U("NotAuthorized")) output = GenericErrorCodesNotAuthorized;
            if (inputStr == U("MissingTitleGoogleProperties")) output = GenericErrorCodesMissingTitleGoogleProperties;
            if (inputStr == U("InvalidItemProperties")) output = GenericErrorCodesInvalidItemProperties;
            if (inputStr == U("InvalidPSNAuthCode")) output = GenericErrorCodesInvalidPSNAuthCode;
            if (inputStr == U("InvalidItemId")) output = GenericErrorCodesInvalidItemId;
            if (inputStr == U("PushNotEnabledForAccount")) output = GenericErrorCodesPushNotEnabledForAccount;
            if (inputStr == U("PushServiceError")) output = GenericErrorCodesPushServiceError;
            if (inputStr == U("ReceiptDoesNotContainInAppItems")) output = GenericErrorCodesReceiptDoesNotContainInAppItems;
            if (inputStr == U("ReceiptContainsMultipleInAppItems")) output = GenericErrorCodesReceiptContainsMultipleInAppItems;
            if (inputStr == U("InvalidBundleID")) output = GenericErrorCodesInvalidBundleID;
            if (inputStr == U("JavascriptException")) output = GenericErrorCodesJavascriptException;
            if (inputStr == U("InvalidSessionTicket")) output = GenericErrorCodesInvalidSessionTicket;
            if (inputStr == U("UnableToConnectToDatabase")) output = GenericErrorCodesUnableToConnectToDatabase;
            if (inputStr == U("InternalServerError")) output = GenericErrorCodesInternalServerError;
            if (inputStr == U("InvalidReportDate")) output = GenericErrorCodesInvalidReportDate;
            if (inputStr == U("ReportNotAvailable")) output = GenericErrorCodesReportNotAvailable;
            if (inputStr == U("DatabaseThroughputExceeded")) output = GenericErrorCodesDatabaseThroughputExceeded;
            if (inputStr == U("InvalidGameTicket")) output = GenericErrorCodesInvalidGameTicket;
            if (inputStr == U("ExpiredGameTicket")) output = GenericErrorCodesExpiredGameTicket;
            if (inputStr == U("GameTicketDoesNotMatchLobby")) output = GenericErrorCodesGameTicketDoesNotMatchLobby;
            if (inputStr == U("LinkedDeviceAlreadyClaimed")) output = GenericErrorCodesLinkedDeviceAlreadyClaimed;
            if (inputStr == U("DeviceAlreadyLinked")) output = GenericErrorCodesDeviceAlreadyLinked;
            if (inputStr == U("DeviceNotLinked")) output = GenericErrorCodesDeviceNotLinked;
            if (inputStr == U("PartialFailure")) output = GenericErrorCodesPartialFailure;
            if (inputStr == U("PublisherNotSet")) output = GenericErrorCodesPublisherNotSet;
            if (inputStr == U("ServiceUnavailable")) output = GenericErrorCodesServiceUnavailable;
            if (inputStr == U("VersionNotFound")) output = GenericErrorCodesVersionNotFound;
            if (inputStr == U("RevisionNotFound")) output = GenericErrorCodesRevisionNotFound;
            if (inputStr == U("InvalidPublisherId")) output = GenericErrorCodesInvalidPublisherId;
            if (inputStr == U("DownstreamServiceUnavailable")) output = GenericErrorCodesDownstreamServiceUnavailable;
            if (inputStr == U("APINotIncludedInTitleUsageTier")) output = GenericErrorCodesAPINotIncludedInTitleUsageTier;
            if (inputStr == U("DAULimitExceeded")) output = GenericErrorCodesDAULimitExceeded;
            if (inputStr == U("APIRequestLimitExceeded")) output = GenericErrorCodesAPIRequestLimitExceeded;
            if (inputStr == U("InvalidAPIEndpoint")) output = GenericErrorCodesInvalidAPIEndpoint;
            if (inputStr == U("BuildNotAvailable")) output = GenericErrorCodesBuildNotAvailable;
            if (inputStr == U("ConcurrentEditError")) output = GenericErrorCodesConcurrentEditError;
            if (inputStr == U("ContentNotFound")) output = GenericErrorCodesContentNotFound;
            if (inputStr == U("CharacterNotFound")) output = GenericErrorCodesCharacterNotFound;
            if (inputStr == U("CloudScriptNotFound")) output = GenericErrorCodesCloudScriptNotFound;
            if (inputStr == U("ContentQuotaExceeded")) output = GenericErrorCodesContentQuotaExceeded;
            if (inputStr == U("InvalidCharacterStatistics")) output = GenericErrorCodesInvalidCharacterStatistics;
            if (inputStr == U("PhotonNotEnabledForTitle")) output = GenericErrorCodesPhotonNotEnabledForTitle;
            if (inputStr == U("PhotonApplicationNotFound")) output = GenericErrorCodesPhotonApplicationNotFound;
            if (inputStr == U("PhotonApplicationNotAssociatedWithTitle")) output = GenericErrorCodesPhotonApplicationNotAssociatedWithTitle;
            if (inputStr == U("InvalidEmailOrPassword")) output = GenericErrorCodesInvalidEmailOrPassword;
            if (inputStr == U("FacebookAPIError")) output = GenericErrorCodesFacebookAPIError;
            if (inputStr == U("InvalidContentType")) output = GenericErrorCodesInvalidContentType;
            if (inputStr == U("KeyLengthExceeded")) output = GenericErrorCodesKeyLengthExceeded;
            if (inputStr == U("DataLengthExceeded")) output = GenericErrorCodesDataLengthExceeded;
            if (inputStr == U("TooManyKeys")) output = GenericErrorCodesTooManyKeys;
            if (inputStr == U("FreeTierCannotHaveVirtualCurrency")) output = GenericErrorCodesFreeTierCannotHaveVirtualCurrency;
            if (inputStr == U("MissingAmazonSharedKey")) output = GenericErrorCodesMissingAmazonSharedKey;
            if (inputStr == U("AmazonValidationError")) output = GenericErrorCodesAmazonValidationError;
            if (inputStr == U("InvalidPSNIssuerId")) output = GenericErrorCodesInvalidPSNIssuerId;
            if (inputStr == U("PSNInaccessible")) output = GenericErrorCodesPSNInaccessible;
            if (inputStr == U("ExpiredAuthToken")) output = GenericErrorCodesExpiredAuthToken;
            if (inputStr == U("FailedToGetEntitlements")) output = GenericErrorCodesFailedToGetEntitlements;
            if (inputStr == U("FailedToConsumeEntitlement")) output = GenericErrorCodesFailedToConsumeEntitlement;
            if (inputStr == U("TradeAcceptingUserNotAllowed")) output = GenericErrorCodesTradeAcceptingUserNotAllowed;
            if (inputStr == U("TradeInventoryItemIsAssignedToCharacter")) output = GenericErrorCodesTradeInventoryItemIsAssignedToCharacter;
            if (inputStr == U("TradeInventoryItemIsBundle")) output = GenericErrorCodesTradeInventoryItemIsBundle;
            if (inputStr == U("TradeStatusNotValidForCancelling")) output = GenericErrorCodesTradeStatusNotValidForCancelling;
            if (inputStr == U("TradeStatusNotValidForAccepting")) output = GenericErrorCodesTradeStatusNotValidForAccepting;
            if (inputStr == U("TradeDoesNotExist")) output = GenericErrorCodesTradeDoesNotExist;
            if (inputStr == U("TradeCancelled")) output = GenericErrorCodesTradeCancelled;
            if (inputStr == U("TradeAlreadyFilled")) output = GenericErrorCodesTradeAlreadyFilled;
            if (inputStr == U("TradeWaitForStatusTimeout")) output = GenericErrorCodesTradeWaitForStatusTimeout;
            if (inputStr == U("TradeInventoryItemExpired")) output = GenericErrorCodesTradeInventoryItemExpired;
            if (inputStr == U("TradeMissingOfferedAndAcceptedItems")) output = GenericErrorCodesTradeMissingOfferedAndAcceptedItems;
            if (inputStr == U("TradeAcceptedItemIsBundle")) output = GenericErrorCodesTradeAcceptedItemIsBundle;
            if (inputStr == U("TradeAcceptedItemIsStackable")) output = GenericErrorCodesTradeAcceptedItemIsStackable;
            if (inputStr == U("TradeInventoryItemInvalidStatus")) output = GenericErrorCodesTradeInventoryItemInvalidStatus;
            if (inputStr == U("TradeAcceptedCatalogItemInvalid")) output = GenericErrorCodesTradeAcceptedCatalogItemInvalid;
            if (inputStr == U("TradeAllowedUsersInvalid")) output = GenericErrorCodesTradeAllowedUsersInvalid;
            if (inputStr == U("TradeInventoryItemDoesNotExist")) output = GenericErrorCodesTradeInventoryItemDoesNotExist;
            if (inputStr == U("TradeInventoryItemIsConsumed")) output = GenericErrorCodesTradeInventoryItemIsConsumed;
            if (inputStr == U("TradeInventoryItemIsStackable")) output = GenericErrorCodesTradeInventoryItemIsStackable;
            if (inputStr == U("TradeAcceptedItemsMismatch")) output = GenericErrorCodesTradeAcceptedItemsMismatch;
            if (inputStr == U("InvalidKongregateToken")) output = GenericErrorCodesInvalidKongregateToken;
            if (inputStr == U("FeatureNotConfiguredForTitle")) output = GenericErrorCodesFeatureNotConfiguredForTitle;
            if (inputStr == U("NoMatchingCatalogItemForReceipt")) output = GenericErrorCodesNoMatchingCatalogItemForReceipt;
            if (inputStr == U("InvalidCurrencyCode")) output = GenericErrorCodesInvalidCurrencyCode;
            if (inputStr == U("NoRealMoneyPriceForCatalogItem")) output = GenericErrorCodesNoRealMoneyPriceForCatalogItem;
            if (inputStr == U("TradeInventoryItemIsNotTradable")) output = GenericErrorCodesTradeInventoryItemIsNotTradable;
            if (inputStr == U("TradeAcceptedCatalogItemIsNotTradable")) output = GenericErrorCodesTradeAcceptedCatalogItemIsNotTradable;
            if (inputStr == U("UsersAlreadyFriends")) output = GenericErrorCodesUsersAlreadyFriends;
            if (inputStr == U("LinkedIdentifierAlreadyClaimed")) output = GenericErrorCodesLinkedIdentifierAlreadyClaimed;
            if (inputStr == U("CustomIdNotLinked")) output = GenericErrorCodesCustomIdNotLinked;
            if (inputStr == U("TotalDataSizeExceeded")) output = GenericErrorCodesTotalDataSizeExceeded;
            if (inputStr == U("DeleteKeyConflict")) output = GenericErrorCodesDeleteKeyConflict;
            if (inputStr == U("InvalidXboxLiveToken")) output = GenericErrorCodesInvalidXboxLiveToken;
            if (inputStr == U("ExpiredXboxLiveToken")) output = GenericErrorCodesExpiredXboxLiveToken;
            if (inputStr == U("ResettableStatisticVersionRequired")) output = GenericErrorCodesResettableStatisticVersionRequired;
            if (inputStr == U("NotAuthorizedByTitle")) output = GenericErrorCodesNotAuthorizedByTitle;
            if (inputStr == U("NoPartnerEnabled")) output = GenericErrorCodesNoPartnerEnabled;
            if (inputStr == U("InvalidPartnerResponse")) output = GenericErrorCodesInvalidPartnerResponse;
            if (inputStr == U("APINotEnabledForGameServerAccess")) output = GenericErrorCodesAPINotEnabledForGameServerAccess;
            if (inputStr == U("StatisticNotFound")) output = GenericErrorCodesStatisticNotFound;
            if (inputStr == U("StatisticNameConflict")) output = GenericErrorCodesStatisticNameConflict;
            if (inputStr == U("StatisticVersionClosedForWrites")) output = GenericErrorCodesStatisticVersionClosedForWrites;
            if (inputStr == U("StatisticVersionInvalid")) output = GenericErrorCodesStatisticVersionInvalid;
            if (inputStr == U("APIClientRequestRateLimitExceeded")) output = GenericErrorCodesAPIClientRequestRateLimitExceeded;
            if (inputStr == U("InvalidJSONContent")) output = GenericErrorCodesInvalidJSONContent;
            if (inputStr == U("InvalidDropTable")) output = GenericErrorCodesInvalidDropTable;
            if (inputStr == U("StatisticVersionAlreadyIncrementedForScheduledInterval")) output = GenericErrorCodesStatisticVersionAlreadyIncrementedForScheduledInterval;
            if (inputStr == U("StatisticCountLimitExceeded")) output = GenericErrorCodesStatisticCountLimitExceeded;
            if (inputStr == U("StatisticVersionIncrementRateExceeded")) output = GenericErrorCodesStatisticVersionIncrementRateExceeded;
            if (inputStr == U("ContainerKeyInvalid")) output = GenericErrorCodesContainerKeyInvalid;
            if (inputStr == U("CloudScriptExecutionTimeLimitExceeded")) output = GenericErrorCodesCloudScriptExecutionTimeLimitExceeded;
            if (inputStr == U("NoWritePermissionsForEvent")) output = GenericErrorCodesNoWritePermissionsForEvent;
            if (inputStr == U("CloudScriptFunctionArgumentSizeExceeded")) output = GenericErrorCodesCloudScriptFunctionArgumentSizeExceeded;
            if (inputStr == U("CloudScriptAPIRequestCountExceeded")) output = GenericErrorCodesCloudScriptAPIRequestCountExceeded;
            if (inputStr == U("CloudScriptAPIRequestError")) output = GenericErrorCodesCloudScriptAPIRequestError;
            if (inputStr == U("CloudScriptHTTPRequestError")) output = GenericErrorCodesCloudScriptHTTPRequestError;
            if (inputStr == U("InsufficientGuildRole")) output = GenericErrorCodesInsufficientGuildRole;
            if (inputStr == U("GuildNotFound")) output = GenericErrorCodesGuildNotFound;
            if (inputStr == U("OverLimit")) output = GenericErrorCodesOverLimit;
            if (inputStr == U("EventNotFound")) output = GenericErrorCodesEventNotFound;
            if (inputStr == U("InvalidEventField")) output = GenericErrorCodesInvalidEventField;
            if (inputStr == U("InvalidEventName")) output = GenericErrorCodesInvalidEventName;
            if (inputStr == U("CatalogNotConfigured")) output = GenericErrorCodesCatalogNotConfigured;
            if (inputStr == U("OperationNotSupportedForPlatform")) output = GenericErrorCodesOperationNotSupportedForPlatform;
            if (inputStr == U("SegmentNotFound")) output = GenericErrorCodesSegmentNotFound;
            if (inputStr == U("StoreNotFound")) output = GenericErrorCodesStoreNotFound;
            if (inputStr == U("InvalidStatisticName")) output = GenericErrorCodesInvalidStatisticName;
            if (inputStr == U("TitleNotQualifiedForLimit")) output = GenericErrorCodesTitleNotQualifiedForLimit;
            if (inputStr == U("InvalidServiceLimitLevel")) output = GenericErrorCodesInvalidServiceLimitLevel;
            if (inputStr == U("ServiceLimitLevelInTransition")) output = GenericErrorCodesServiceLimitLevelInTransition;
            if (inputStr == U("CouponAlreadyRedeemed")) output = GenericErrorCodesCouponAlreadyRedeemed;
            if (inputStr == U("GameServerBuildSizeLimitExceeded")) output = GenericErrorCodesGameServerBuildSizeLimitExceeded;
            if (inputStr == U("GameServerBuildCountLimitExceeded")) output = GenericErrorCodesGameServerBuildCountLimitExceeded;
            if (inputStr == U("VirtualCurrencyCountLimitExceeded")) output = GenericErrorCodesVirtualCurrencyCountLimitExceeded;
            if (inputStr == U("VirtualCurrencyCodeExists")) output = GenericErrorCodesVirtualCurrencyCodeExists;
            if (inputStr == U("TitleNewsItemCountLimitExceeded")) output = GenericErrorCodesTitleNewsItemCountLimitExceeded;
            if (inputStr == U("InvalidTwitchToken")) output = GenericErrorCodesInvalidTwitchToken;
            if (inputStr == U("TwitchResponseError")) output = GenericErrorCodesTwitchResponseError;
            if (inputStr == U("ProfaneDisplayName")) output = GenericErrorCodesProfaneDisplayName;
            if (inputStr == U("UserAlreadyAdded")) output = GenericErrorCodesUserAlreadyAdded;
            if (inputStr == U("InvalidVirtualCurrencyCode")) output = GenericErrorCodesInvalidVirtualCurrencyCode;
            if (inputStr == U("VirtualCurrencyCannotBeDeleted")) output = GenericErrorCodesVirtualCurrencyCannotBeDeleted;
            if (inputStr == U("IdentifierAlreadyClaimed")) output = GenericErrorCodesIdentifierAlreadyClaimed;
            if (inputStr == U("IdentifierNotLinked")) output = GenericErrorCodesIdentifierNotLinked;
            if (inputStr == U("InvalidContinuationToken")) output = GenericErrorCodesInvalidContinuationToken;
            if (inputStr == U("ExpiredContinuationToken")) output = GenericErrorCodesExpiredContinuationToken;
            if (inputStr == U("InvalidSegment")) output = GenericErrorCodesInvalidSegment;
            if (inputStr == U("InvalidSessionId")) output = GenericErrorCodesInvalidSessionId;
            if (inputStr == U("SessionLogNotFound")) output = GenericErrorCodesSessionLogNotFound;
            if (inputStr == U("InvalidSearchTerm")) output = GenericErrorCodesInvalidSearchTerm;
            if (inputStr == U("TwoFactorAuthenticationTokenRequired")) output = GenericErrorCodesTwoFactorAuthenticationTokenRequired;
            if (inputStr == U("GameServerHostCountLimitExceeded")) output = GenericErrorCodesGameServerHostCountLimitExceeded;
            if (inputStr == U("PlayerTagCountLimitExceeded")) output = GenericErrorCodesPlayerTagCountLimitExceeded;
            if (inputStr == U("RequestAlreadyRunning")) output = GenericErrorCodesRequestAlreadyRunning;
            if (inputStr == U("ActionGroupNotFound")) output = GenericErrorCodesActionGroupNotFound;
            if (inputStr == U("MaximumSegmentBulkActionJobsRunning")) output = GenericErrorCodesMaximumSegmentBulkActionJobsRunning;
            if (inputStr == U("NoActionsOnPlayersInSegmentJob")) output = GenericErrorCodesNoActionsOnPlayersInSegmentJob;
            if (inputStr == U("DuplicateStatisticName")) output = GenericErrorCodesDuplicateStatisticName;
            if (inputStr == U("ScheduledTaskNameConflict")) output = GenericErrorCodesScheduledTaskNameConflict;
            if (inputStr == U("ScheduledTaskCreateConflict")) output = GenericErrorCodesScheduledTaskCreateConflict;
            if (inputStr == U("InvalidScheduledTaskName")) output = GenericErrorCodesInvalidScheduledTaskName;
            if (inputStr == U("InvalidTaskSchedule")) output = GenericErrorCodesInvalidTaskSchedule;
            if (inputStr == U("SteamNotEnabledForTitle")) output = GenericErrorCodesSteamNotEnabledForTitle;
            if (inputStr == U("LimitNotAnUpgradeOption")) output = GenericErrorCodesLimitNotAnUpgradeOption;
            if (inputStr == U("NoSecretKeyEnabledForCloudScript")) output = GenericErrorCodesNoSecretKeyEnabledForCloudScript;
            if (inputStr == U("TaskNotFound")) output = GenericErrorCodesTaskNotFound;
            if (inputStr == U("TaskInstanceNotFound")) output = GenericErrorCodesTaskInstanceNotFound;
            if (inputStr == U("InvalidIdentityProviderId")) output = GenericErrorCodesInvalidIdentityProviderId;
            if (inputStr == U("MisconfiguredIdentityProvider")) output = GenericErrorCodesMisconfiguredIdentityProvider;
            if (inputStr == U("InvalidScheduledTaskType")) output = GenericErrorCodesInvalidScheduledTaskType;
            if (inputStr == U("BillingInformationRequired")) output = GenericErrorCodesBillingInformationRequired;
            if (inputStr == U("LimitedEditionItemUnavailable")) output = GenericErrorCodesLimitedEditionItemUnavailable;
            if (inputStr == U("InvalidAdPlacementAndReward")) output = GenericErrorCodesInvalidAdPlacementAndReward;
            if (inputStr == U("AllAdPlacementViewsAlreadyConsumed")) output = GenericErrorCodesAllAdPlacementViewsAlreadyConsumed;
            if (inputStr == U("GoogleOAuthNotConfiguredForTitle")) output = GenericErrorCodesGoogleOAuthNotConfiguredForTitle;
            if (inputStr == U("GoogleOAuthError")) output = GenericErrorCodesGoogleOAuthError;
            if (inputStr == U("UserNotFriend")) output = GenericErrorCodesUserNotFriend;
            if (inputStr == U("InvalidSignature")) output = GenericErrorCodesInvalidSignature;
            if (inputStr == U("InvalidPublicKey")) output = GenericErrorCodesInvalidPublicKey;
            if (inputStr == U("GoogleOAuthNoIdTokenIncludedInResponse")) output = GenericErrorCodesGoogleOAuthNoIdTokenIncludedInResponse;
            if (inputStr == U("StatisticUpdateInProgress")) output = GenericErrorCodesStatisticUpdateInProgress;
            if (inputStr == U("LeaderboardVersionNotAvailable")) output = GenericErrorCodesLeaderboardVersionNotAvailable;
            if (inputStr == U("StatisticAlreadyHasPrizeTable")) output = GenericErrorCodesStatisticAlreadyHasPrizeTable;
            if (inputStr == U("PrizeTableHasOverlappingRanks")) output = GenericErrorCodesPrizeTableHasOverlappingRanks;
            if (inputStr == U("PrizeTableHasMissingRanks")) output = GenericErrorCodesPrizeTableHasMissingRanks;
            if (inputStr == U("PrizeTableRankStartsAtZero")) output = GenericErrorCodesPrizeTableRankStartsAtZero;
            if (inputStr == U("InvalidStatistic")) output = GenericErrorCodesInvalidStatistic;
            if (inputStr == U("ExpressionParseFailure")) output = GenericErrorCodesExpressionParseFailure;
            if (inputStr == U("ExpressionInvokeFailure")) output = GenericErrorCodesExpressionInvokeFailure;
            if (inputStr == U("ExpressionTooLong")) output = GenericErrorCodesExpressionTooLong;
            if (inputStr == U("DataUpdateRateExceeded")) output = GenericErrorCodesDataUpdateRateExceeded;
            if (inputStr == U("RestrictedEmailDomain")) output = GenericErrorCodesRestrictedEmailDomain;
            if (inputStr == U("EncryptionKeyDisabled")) output = GenericErrorCodesEncryptionKeyDisabled;
            if (inputStr == U("EncryptionKeyMissing")) output = GenericErrorCodesEncryptionKeyMissing;
            if (inputStr == U("EncryptionKeyBroken")) output = GenericErrorCodesEncryptionKeyBroken;
            if (inputStr == U("NoSharedSecretKeyConfigured")) output = GenericErrorCodesNoSharedSecretKeyConfigured;
            if (inputStr == U("SecretKeyNotFound")) output = GenericErrorCodesSecretKeyNotFound;
            if (inputStr == U("PlayerSecretAlreadyConfigured")) output = GenericErrorCodesPlayerSecretAlreadyConfigured;
            if (inputStr == U("APIRequestsDisabledForTitle")) output = GenericErrorCodesAPIRequestsDisabledForTitle;
            if (inputStr == U("InvalidSharedSecretKey")) output = GenericErrorCodesInvalidSharedSecretKey;
            if (inputStr == U("PrizeTableHasNoRanks")) output = GenericErrorCodesPrizeTableHasNoRanks;
            if (inputStr == U("ProfileDoesNotExist")) output = GenericErrorCodesProfileDoesNotExist;
            if (inputStr == U("ContentS3OriginBucketNotConfigured")) output = GenericErrorCodesContentS3OriginBucketNotConfigured;
            if (inputStr == U("InvalidEnvironmentForReceipt")) output = GenericErrorCodesInvalidEnvironmentForReceipt;
            if (inputStr == U("EncryptedRequestNotAllowed")) output = GenericErrorCodesEncryptedRequestNotAllowed;
            if (inputStr == U("SignedRequestNotAllowed")) output = GenericErrorCodesSignedRequestNotAllowed;
            if (inputStr == U("RequestViewConstraintParamsNotAllowed")) output = GenericErrorCodesRequestViewConstraintParamsNotAllowed;
            if (inputStr == U("BadPartnerConfiguration")) output = GenericErrorCodesBadPartnerConfiguration;
            if (inputStr == U("XboxBPCertificateFailure")) output = GenericErrorCodesXboxBPCertificateFailure;
            if (inputStr == U("XboxXASSExchangeFailure")) output = GenericErrorCodesXboxXASSExchangeFailure;
            if (inputStr == U("InvalidEntityId")) output = GenericErrorCodesInvalidEntityId;
            if (inputStr == U("StatisticValueAggregationOverflow")) output = GenericErrorCodesStatisticValueAggregationOverflow;
            if (inputStr == U("EmailMessageFromAddressIsMissing")) output = GenericErrorCodesEmailMessageFromAddressIsMissing;
            if (inputStr == U("EmailMessageToAddressIsMissing")) output = GenericErrorCodesEmailMessageToAddressIsMissing;
            if (inputStr == U("SmtpServerAuthenticationError")) output = GenericErrorCodesSmtpServerAuthenticationError;
            if (inputStr == U("SmtpServerLimitExceeded")) output = GenericErrorCodesSmtpServerLimitExceeded;
            if (inputStr == U("SmtpServerInsufficientStorage")) output = GenericErrorCodesSmtpServerInsufficientStorage;
            if (inputStr == U("SmtpServerCommunicationError")) output = GenericErrorCodesSmtpServerCommunicationError;
            if (inputStr == U("SmtpServerGeneralFailure")) output = GenericErrorCodesSmtpServerGeneralFailure;
            if (inputStr == U("EmailClientTimeout")) output = GenericErrorCodesEmailClientTimeout;
            if (inputStr == U("EmailClientCanceledTask")) output = GenericErrorCodesEmailClientCanceledTask;
            if (inputStr == U("EmailTemplateMissing")) output = GenericErrorCodesEmailTemplateMissing;
            if (inputStr == U("InvalidHostForTitleId")) output = GenericErrorCodesInvalidHostForTitleId;
            if (inputStr == U("EmailConfirmationTokenDoesNotExist")) output = GenericErrorCodesEmailConfirmationTokenDoesNotExist;
            if (inputStr == U("EmailConfirmationTokenExpired")) output = GenericErrorCodesEmailConfirmationTokenExpired;
            if (inputStr == U("AccountDeleted")) output = GenericErrorCodesAccountDeleted;
            if (inputStr == U("PlayerSecretNotConfigured")) output = GenericErrorCodesPlayerSecretNotConfigured;
            if (inputStr == U("InvalidSignatureTime")) output = GenericErrorCodesInvalidSignatureTime;
            if (inputStr == U("NoContactEmailAddressFound")) output = GenericErrorCodesNoContactEmailAddressFound;
            if (inputStr == U("InvalidAuthToken")) output = GenericErrorCodesInvalidAuthToken;
            if (inputStr == U("AuthTokenDoesNotExist")) output = GenericErrorCodesAuthTokenDoesNotExist;
            if (inputStr == U("AuthTokenExpired")) output = GenericErrorCodesAuthTokenExpired;
            if (inputStr == U("AuthTokenAlreadyUsedToResetPassword")) output = GenericErrorCodesAuthTokenAlreadyUsedToResetPassword;
            if (inputStr == U("MembershipNameTooLong")) output = GenericErrorCodesMembershipNameTooLong;
            if (inputStr == U("MembershipNotFound")) output = GenericErrorCodesMembershipNotFound;
            if (inputStr == U("GoogleServiceAccountInvalid")) output = GenericErrorCodesGoogleServiceAccountInvalid;
            if (inputStr == U("GoogleServiceAccountParseFailure")) output = GenericErrorCodesGoogleServiceAccountParseFailure;
            if (inputStr == U("EntityTokenMissing")) output = GenericErrorCodesEntityTokenMissing;
            if (inputStr == U("EntityTokenInvalid")) output = GenericErrorCodesEntityTokenInvalid;
            if (inputStr == U("EntityTokenExpired")) output = GenericErrorCodesEntityTokenExpired;
            if (inputStr == U("EntityTokenRevoked")) output = GenericErrorCodesEntityTokenRevoked;
            if (inputStr == U("InvalidProductForSubscription")) output = GenericErrorCodesInvalidProductForSubscription;
            if (inputStr == U("XboxInaccessible")) output = GenericErrorCodesXboxInaccessible;
            if (inputStr == U("SubscriptionAlreadyTaken")) output = GenericErrorCodesSubscriptionAlreadyTaken;
            if (inputStr == U("SmtpAddonNotEnabled")) output = GenericErrorCodesSmtpAddonNotEnabled;
            if (inputStr == U("APIConcurrentRequestLimitExceeded")) output = GenericErrorCodesAPIConcurrentRequestLimitExceeded;
            if (inputStr == U("XboxRejectedXSTSExchangeRequest")) output = GenericErrorCodesXboxRejectedXSTSExchangeRequest;
            if (inputStr == U("VariableNotDefined")) output = GenericErrorCodesVariableNotDefined;
            if (inputStr == U("TemplateVersionNotDefined")) output = GenericErrorCodesTemplateVersionNotDefined;
            if (inputStr == U("FileTooLarge")) output = GenericErrorCodesFileTooLarge;
            if (inputStr == U("TitleDeleted")) output = GenericErrorCodesTitleDeleted;
            if (inputStr == U("TitleContainsUserAccounts")) output = GenericErrorCodesTitleContainsUserAccounts;
            if (inputStr == U("TitleDeletionPlayerCleanupFailure")) output = GenericErrorCodesTitleDeletionPlayerCleanupFailure;
            if (inputStr == U("EntityFileOperationPending")) output = GenericErrorCodesEntityFileOperationPending;
            if (inputStr == U("NoEntityFileOperationPending")) output = GenericErrorCodesNoEntityFileOperationPending;
            if (inputStr == U("EntityProfileVersionMismatch")) output = GenericErrorCodesEntityProfileVersionMismatch;
            if (inputStr == U("TemplateVersionTooOld")) output = GenericErrorCodesTemplateVersionTooOld;
            if (inputStr == U("MembershipDefinitionInUse")) output = GenericErrorCodesMembershipDefinitionInUse;
            if (inputStr == U("PaymentPageNotConfigured")) output = GenericErrorCodesPaymentPageNotConfigured;
            if (inputStr == U("FailedLoginAttemptRateLimitExceeded")) output = GenericErrorCodesFailedLoginAttemptRateLimitExceeded;
            if (inputStr == U("EntityBlockedByGroup")) output = GenericErrorCodesEntityBlockedByGroup;
            if (inputStr == U("RoleDoesNotExist")) output = GenericErrorCodesRoleDoesNotExist;
            if (inputStr == U("EntityIsAlreadyMember")) output = GenericErrorCodesEntityIsAlreadyMember;
            if (inputStr == U("DuplicateRoleId")) output = GenericErrorCodesDuplicateRoleId;
            if (inputStr == U("GroupInvitationNotFound")) output = GenericErrorCodesGroupInvitationNotFound;
            if (inputStr == U("GroupApplicationNotFound")) output = GenericErrorCodesGroupApplicationNotFound;
            if (inputStr == U("OutstandingInvitationAcceptedInstead")) output = GenericErrorCodesOutstandingInvitationAcceptedInstead;
            if (inputStr == U("OutstandingApplicationAcceptedInstead")) output = GenericErrorCodesOutstandingApplicationAcceptedInstead;
            if (inputStr == U("RoleIsGroupDefaultMember")) output = GenericErrorCodesRoleIsGroupDefaultMember;
            if (inputStr == U("RoleIsGroupAdmin")) output = GenericErrorCodesRoleIsGroupAdmin;
            if (inputStr == U("RoleNameNotAvailable")) output = GenericErrorCodesRoleNameNotAvailable;
            if (inputStr == U("GroupNameNotAvailable")) output = GenericErrorCodesGroupNameNotAvailable;
            if (inputStr == U("EmailReportAlreadySent")) output = GenericErrorCodesEmailReportAlreadySent;
            if (inputStr == U("EmailReportRecipientBlacklisted")) output = GenericErrorCodesEmailReportRecipientBlacklisted;
            if (inputStr == U("EventNamespaceNotAllowed")) output = GenericErrorCodesEventNamespaceNotAllowed;
            if (inputStr == U("EventEntityNotAllowed")) output = GenericErrorCodesEventEntityNotAllowed;
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

        enum PlayerConnectionState
        {
            PlayerConnectionStateUnassigned,
            PlayerConnectionStateConnecting,
            PlayerConnectionStateParticipating,
            PlayerConnectionStateParticipated
        };

        inline void ToJsonEnum(const PlayerConnectionState input, web::json::value& output)
        {
            if (input == PlayerConnectionStateUnassigned) output = web::json::value(U("Unassigned"));
            if (input == PlayerConnectionStateConnecting) output = web::json::value(U("Connecting"));
            if (input == PlayerConnectionStateParticipating) output = web::json::value(U("Participating"));
            if (input == PlayerConnectionStateParticipated) output = web::json::value(U("Participated"));
        }
        inline void FromJsonEnum(const web::json::value& input, PlayerConnectionState& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Unassigned")) output = PlayerConnectionStateUnassigned;
            if (inputStr == U("Connecting")) output = PlayerConnectionStateConnecting;
            if (inputStr == U("Participating")) output = PlayerConnectionStateParticipating;
            if (inputStr == U("Participated")) output = PlayerConnectionStateParticipated;
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

        enum ResultTableNodeType
        {
            ResultTableNodeTypeItemId,
            ResultTableNodeTypeTableId
        };

        inline void ToJsonEnum(const ResultTableNodeType input, web::json::value& output)
        {
            if (input == ResultTableNodeTypeItemId) output = web::json::value(U("ItemId"));
            if (input == ResultTableNodeTypeTableId) output = web::json::value(U("TableId"));
        }
        inline void FromJsonEnum(const web::json::value& input, ResultTableNodeType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("ItemId")) output = ResultTableNodeTypeItemId;
            if (inputStr == U("TableId")) output = ResultTableNodeTypeTableId;
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

        // Server Classes
        struct AdCampaignAttribution : public PlayFabBaseModel
        {
            time_t AttributedAt;
            std::string CampaignId;
            std::string Platform;

            AdCampaignAttribution() :
                PlayFabBaseModel(),
                AttributedAt(),
                CampaignId(),
                Platform()
            {}

            AdCampaignAttribution(const AdCampaignAttribution& src) :
                PlayFabBaseModel(),
                AttributedAt(src.AttributedAt),
                CampaignId(src.CampaignId),
                Platform(src.Platform)
            {}

            ~AdCampaignAttribution() { }

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

        struct AddCharacterVirtualCurrencyRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string CharacterId;
            std::string PlayFabId;
            std::string VirtualCurrency;

            AddCharacterVirtualCurrencyRequest() :
                PlayFabRequestCommon(),
                Amount(),
                CharacterId(),
                PlayFabId(),
                VirtualCurrency()
            {}

            AddCharacterVirtualCurrencyRequest(const AddCharacterVirtualCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~AddCharacterVirtualCurrencyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Amount")], Amount);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[U("Amount")] = each_Amount;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct AddFriendRequest : public PlayFabRequestCommon
        {
            std::string FriendEmail;
            std::string FriendPlayFabId;
            std::string FriendTitleDisplayName;
            std::string FriendUsername;
            std::string PlayFabId;

            AddFriendRequest() :
                PlayFabRequestCommon(),
                FriendEmail(),
                FriendPlayFabId(),
                FriendTitleDisplayName(),
                FriendUsername(),
                PlayFabId()
            {}

            AddFriendRequest(const AddFriendRequest& src) :
                PlayFabRequestCommon(),
                FriendEmail(src.FriendEmail),
                FriendPlayFabId(src.FriendPlayFabId),
                FriendTitleDisplayName(src.FriendTitleDisplayName),
                FriendUsername(src.FriendUsername),
                PlayFabId(src.PlayFabId)
            {}

            ~AddFriendRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FriendEmail")], FriendEmail);
                FromJsonUtilS(input[U("FriendPlayFabId")], FriendPlayFabId);
                FromJsonUtilS(input[U("FriendTitleDisplayName")], FriendTitleDisplayName);
                FromJsonUtilS(input[U("FriendUsername")], FriendUsername);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendEmail; ToJsonUtilS(FriendEmail, each_FriendEmail); output[U("FriendEmail")] = each_FriendEmail;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[U("FriendPlayFabId")] = each_FriendPlayFabId;
                web::json::value each_FriendTitleDisplayName; ToJsonUtilS(FriendTitleDisplayName, each_FriendTitleDisplayName); output[U("FriendTitleDisplayName")] = each_FriendTitleDisplayName;
                web::json::value each_FriendUsername; ToJsonUtilS(FriendUsername, each_FriendUsername); output[U("FriendUsername")] = each_FriendUsername;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct AddPlayerTagRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;
            std::string TagName;

            AddPlayerTagRequest() :
                PlayFabRequestCommon(),
                PlayFabId(),
                TagName()
            {}

            AddPlayerTagRequest(const AddPlayerTagRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            ~AddPlayerTagRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("TagName")], TagName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_TagName; ToJsonUtilS(TagName, each_TagName); output[U("TagName")] = each_TagName;
                return output;
            }
        };

        struct AddPlayerTagResult : public PlayFabResultCommon
        {

            AddPlayerTagResult() :
                PlayFabResultCommon()
            {}

            AddPlayerTagResult(const AddPlayerTagResult& src) :
                PlayFabResultCommon()
            {}

            ~AddPlayerTagResult() { }

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

        struct AddUserVirtualCurrencyRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string PlayFabId;
            std::string VirtualCurrency;

            AddUserVirtualCurrencyRequest() :
                PlayFabRequestCommon(),
                Amount(),
                PlayFabId(),
                VirtualCurrency()
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~AddUserVirtualCurrencyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Amount")], Amount);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[U("Amount")] = each_Amount;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct AdvancedPushPlatformMsg : public PlayFabBaseModel
        {
            std::string Json;
            PushNotificationPlatform Platform;

            AdvancedPushPlatformMsg() :
                PlayFabBaseModel(),
                Json(),
                Platform()
            {}

            AdvancedPushPlatformMsg(const AdvancedPushPlatformMsg& src) :
                PlayFabBaseModel(),
                Json(src.Json),
                Platform(src.Platform)
            {}

            ~AdvancedPushPlatformMsg() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Json")], Json);
                FromJsonEnum(input[U("Platform")], Platform);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Json; ToJsonUtilS(Json, each_Json); output[U("Json")] = each_Json;
                web::json::value each_Platform; ToJsonEnum(Platform, each_Platform); output[U("Platform")] = each_Platform;
                return output;
            }
        };

        struct AuthenticateSessionTicketRequest : public PlayFabRequestCommon
        {
            std::string SessionTicket;

            AuthenticateSessionTicketRequest() :
                PlayFabRequestCommon(),
                SessionTicket()
            {}

            AuthenticateSessionTicketRequest(const AuthenticateSessionTicketRequest& src) :
                PlayFabRequestCommon(),
                SessionTicket(src.SessionTicket)
            {}

            ~AuthenticateSessionTicketRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("SessionTicket")], SessionTicket);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SessionTicket; ToJsonUtilS(SessionTicket, each_SessionTicket); output[U("SessionTicket")] = each_SessionTicket;
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

        struct AuthenticateSessionTicketResult : public PlayFabResultCommon
        {
            Boxed<UserAccountInfo> UserInfo;

            AuthenticateSessionTicketResult() :
                PlayFabResultCommon(),
                UserInfo()
            {}

            AuthenticateSessionTicketResult(const AuthenticateSessionTicketResult& src) :
                PlayFabResultCommon(),
                UserInfo(src.UserInfo)
            {}

            ~AuthenticateSessionTicketResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("UserInfo")], UserInfo);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_UserInfo; ToJsonUtilO(UserInfo, each_UserInfo); output[U("UserInfo")] = each_UserInfo;
                return output;
            }
        };

        struct AwardSteamAchievementItem : public PlayFabBaseModel
        {
            std::string AchievementName;
            std::string PlayFabId;
            bool Result;

            AwardSteamAchievementItem() :
                PlayFabBaseModel(),
                AchievementName(),
                PlayFabId(),
                Result()
            {}

            AwardSteamAchievementItem(const AwardSteamAchievementItem& src) :
                PlayFabBaseModel(),
                AchievementName(src.AchievementName),
                PlayFabId(src.PlayFabId),
                Result(src.Result)
            {}

            ~AwardSteamAchievementItem() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AchievementName")], AchievementName);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilP(input[U("Result")], Result);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AchievementName; ToJsonUtilS(AchievementName, each_AchievementName); output[U("AchievementName")] = each_AchievementName;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Result; ToJsonUtilP(Result, each_Result); output[U("Result")] = each_Result;
                return output;
            }
        };

        struct AwardSteamAchievementRequest : public PlayFabRequestCommon
        {
            std::list<AwardSteamAchievementItem> Achievements;

            AwardSteamAchievementRequest() :
                PlayFabRequestCommon(),
                Achievements()
            {}

            AwardSteamAchievementRequest(const AwardSteamAchievementRequest& src) :
                PlayFabRequestCommon(),
                Achievements(src.Achievements)
            {}

            ~AwardSteamAchievementRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Achievements")], Achievements);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Achievements; ToJsonUtilO(Achievements, each_Achievements); output[U("Achievements")] = each_Achievements;
                return output;
            }
        };

        struct AwardSteamAchievementResult : public PlayFabResultCommon
        {
            std::list<AwardSteamAchievementItem> AchievementResults;

            AwardSteamAchievementResult() :
                PlayFabResultCommon(),
                AchievementResults()
            {}

            AwardSteamAchievementResult(const AwardSteamAchievementResult& src) :
                PlayFabResultCommon(),
                AchievementResults(src.AchievementResults)
            {}

            ~AwardSteamAchievementResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("AchievementResults")], AchievementResults);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AchievementResults; ToJsonUtilO(AchievementResults, each_AchievementResults); output[U("AchievementResults")] = each_AchievementResults;
                return output;
            }
        };

        struct BanInfo : public PlayFabBaseModel
        {
            bool Active;
            std::string BanId;
            Boxed<time_t> Created;
            Boxed<time_t> Expires;
            std::string IPAddress;
            std::string MACAddress;
            std::string PlayFabId;
            std::string Reason;

            BanInfo() :
                PlayFabBaseModel(),
                Active(),
                BanId(),
                Created(),
                Expires(),
                IPAddress(),
                MACAddress(),
                PlayFabId(),
                Reason()
            {}

            BanInfo(const BanInfo& src) :
                PlayFabBaseModel(),
                Active(src.Active),
                BanId(src.BanId),
                Created(src.Created),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            ~BanInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Active")], Active);
                FromJsonUtilS(input[U("BanId")], BanId);
                FromJsonUtilT(input[U("Created")], Created);
                FromJsonUtilT(input[U("Expires")], Expires);
                FromJsonUtilS(input[U("IPAddress")], IPAddress);
                FromJsonUtilS(input[U("MACAddress")], MACAddress);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("Reason")], Reason);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Active; ToJsonUtilP(Active, each_Active); output[U("Active")] = each_Active;
                web::json::value each_BanId; ToJsonUtilS(BanId, each_BanId); output[U("BanId")] = each_BanId;
                web::json::value each_Created; ToJsonUtilT(Created, each_Created); output[U("Created")] = each_Created;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[U("Expires")] = each_Expires;
                web::json::value each_IPAddress; ToJsonUtilS(IPAddress, each_IPAddress); output[U("IPAddress")] = each_IPAddress;
                web::json::value each_MACAddress; ToJsonUtilS(MACAddress, each_MACAddress); output[U("MACAddress")] = each_MACAddress;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Reason; ToJsonUtilS(Reason, each_Reason); output[U("Reason")] = each_Reason;
                return output;
            }
        };

        struct BanRequest : public PlayFabRequestCommon
        {
            Boxed<Uint32> DurationInHours;
            std::string IPAddress;
            std::string MACAddress;
            std::string PlayFabId;
            std::string Reason;

            BanRequest() :
                PlayFabRequestCommon(),
                DurationInHours(),
                IPAddress(),
                MACAddress(),
                PlayFabId(),
                Reason()
            {}

            BanRequest(const BanRequest& src) :
                PlayFabRequestCommon(),
                DurationInHours(src.DurationInHours),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            ~BanRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("DurationInHours")], DurationInHours);
                FromJsonUtilS(input[U("IPAddress")], IPAddress);
                FromJsonUtilS(input[U("MACAddress")], MACAddress);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("Reason")], Reason);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DurationInHours; ToJsonUtilP(DurationInHours, each_DurationInHours); output[U("DurationInHours")] = each_DurationInHours;
                web::json::value each_IPAddress; ToJsonUtilS(IPAddress, each_IPAddress); output[U("IPAddress")] = each_IPAddress;
                web::json::value each_MACAddress; ToJsonUtilS(MACAddress, each_MACAddress); output[U("MACAddress")] = each_MACAddress;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Reason; ToJsonUtilS(Reason, each_Reason); output[U("Reason")] = each_Reason;
                return output;
            }
        };

        struct BanUsersRequest : public PlayFabRequestCommon
        {
            std::list<BanRequest> Bans;

            BanUsersRequest() :
                PlayFabRequestCommon(),
                Bans()
            {}

            BanUsersRequest(const BanUsersRequest& src) :
                PlayFabRequestCommon(),
                Bans(src.Bans)
            {}

            ~BanUsersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Bans")], Bans);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Bans; ToJsonUtilO(Bans, each_Bans); output[U("Bans")] = each_Bans;
                return output;
            }
        };

        struct BanUsersResult : public PlayFabResultCommon
        {
            std::list<BanInfo> BanData;

            BanUsersResult() :
                PlayFabResultCommon(),
                BanData()
            {}

            BanUsersResult(const BanUsersResult& src) :
                PlayFabResultCommon(),
                BanData(src.BanData)
            {}

            ~BanUsersResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("BanData")], BanData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanData; ToJsonUtilO(BanData, each_BanData); output[U("BanData")] = each_BanData;
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

        struct ConsumeItemRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            Int32 ConsumeCount;
            std::string ItemInstanceId;
            std::string PlayFabId;

            ConsumeItemRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                ConsumeCount(),
                ItemInstanceId(),
                PlayFabId()
            {}

            ConsumeItemRequest(const ConsumeItemRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                ConsumeCount(src.ConsumeCount),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            ~ConsumeItemRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilP(input[U("ConsumeCount")], ConsumeCount);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ConsumeCount; ToJsonUtilP(ConsumeCount, each_ConsumeCount); output[U("ConsumeCount")] = each_ConsumeCount;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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

        struct ContactEmailInfo : public PlayFabBaseModel
        {
            std::string EmailAddress;
            std::string Name;
            Boxed<EmailVerificationStatus> VerificationStatus;

            ContactEmailInfo() :
                PlayFabBaseModel(),
                EmailAddress(),
                Name(),
                VerificationStatus()
            {}

            ContactEmailInfo(const ContactEmailInfo& src) :
                PlayFabBaseModel(),
                EmailAddress(src.EmailAddress),
                Name(src.Name),
                VerificationStatus(src.VerificationStatus)
            {}

            ~ContactEmailInfo() { }

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

        struct DeleteCharacterFromUserRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::string PlayFabId;
            bool SaveCharacterInventory;

            DeleteCharacterFromUserRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                PlayFabId(),
                SaveCharacterInventory()
            {}

            DeleteCharacterFromUserRequest(const DeleteCharacterFromUserRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId),
                SaveCharacterInventory(src.SaveCharacterInventory)
            {}

            ~DeleteCharacterFromUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilP(input[U("SaveCharacterInventory")], SaveCharacterInventory);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_SaveCharacterInventory; ToJsonUtilP(SaveCharacterInventory, each_SaveCharacterInventory); output[U("SaveCharacterInventory")] = each_SaveCharacterInventory;
                return output;
            }
        };

        struct DeleteCharacterFromUserResult : public PlayFabResultCommon
        {

            DeleteCharacterFromUserResult() :
                PlayFabResultCommon()
            {}

            DeleteCharacterFromUserResult(const DeleteCharacterFromUserResult& src) :
                PlayFabResultCommon()
            {}

            ~DeleteCharacterFromUserResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct DeleteSharedGroupRequest : public PlayFabRequestCommon
        {
            std::string SharedGroupId;

            DeleteSharedGroupRequest() :
                PlayFabRequestCommon(),
                SharedGroupId()
            {}

            DeleteSharedGroupRequest(const DeleteSharedGroupRequest& src) :
                PlayFabRequestCommon(),
                SharedGroupId(src.SharedGroupId)
            {}

            ~DeleteSharedGroupRequest() { }

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

        struct DeleteUsersRequest : public PlayFabRequestCommon
        {
            std::list<std::string> PlayFabIds;
            std::string TitleId;

            DeleteUsersRequest() :
                PlayFabRequestCommon(),
                PlayFabIds(),
                TitleId()
            {}

            DeleteUsersRequest(const DeleteUsersRequest& src) :
                PlayFabRequestCommon(),
                PlayFabIds(src.PlayFabIds),
                TitleId(src.TitleId)
            {}

            ~DeleteUsersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabIds")], PlayFabIds);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabIds; ToJsonUtilS(PlayFabIds, each_PlayFabIds); output[U("PlayFabIds")] = each_PlayFabIds;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct DeleteUsersResult : public PlayFabResultCommon
        {

            DeleteUsersResult() :
                PlayFabResultCommon()
            {}

            DeleteUsersResult(const DeleteUsersResult& src) :
                PlayFabResultCommon()
            {}

            ~DeleteUsersResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct DeregisterGameRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;

            DeregisterGameRequest() :
                PlayFabRequestCommon(),
                LobbyId()
            {}

            DeregisterGameRequest(const DeregisterGameRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId)
            {}

            ~DeregisterGameRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                return output;
            }
        };

        struct DeregisterGameResponse : public PlayFabResultCommon
        {

            DeregisterGameResponse() :
                PlayFabResultCommon()
            {}

            DeregisterGameResponse(const DeregisterGameResponse& src) :
                PlayFabResultCommon()
            {}

            ~DeregisterGameResponse() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
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

        struct EvaluateRandomResultTableRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string TableId;

            EvaluateRandomResultTableRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                TableId()
            {}

            EvaluateRandomResultTableRequest(const EvaluateRandomResultTableRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                TableId(src.TableId)
            {}

            ~EvaluateRandomResultTableRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("TableId")], TableId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_TableId; ToJsonUtilS(TableId, each_TableId); output[U("TableId")] = each_TableId;
                return output;
            }
        };

        struct EvaluateRandomResultTableResult : public PlayFabResultCommon
        {
            std::string ResultItemId;

            EvaluateRandomResultTableResult() :
                PlayFabResultCommon(),
                ResultItemId()
            {}

            EvaluateRandomResultTableResult(const EvaluateRandomResultTableResult& src) :
                PlayFabResultCommon(),
                ResultItemId(src.ResultItemId)
            {}

            ~EvaluateRandomResultTableResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ResultItemId")], ResultItemId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ResultItemId; ToJsonUtilS(ResultItemId, each_ResultItemId); output[U("ResultItemId")] = each_ResultItemId;
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

        struct ExecuteCloudScriptServerRequest : public PlayFabRequestCommon
        {
            std::string FunctionName;
            web::json::value FunctionParameter;
            Boxed<bool> GeneratePlayStreamEvent;
            std::string PlayFabId;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            Boxed<Int32> SpecificRevision;

            ExecuteCloudScriptServerRequest() :
                PlayFabRequestCommon(),
                FunctionName(),
                FunctionParameter(),
                GeneratePlayStreamEvent(),
                PlayFabId(),
                RevisionSelection(),
                SpecificRevision()
            {}

            ExecuteCloudScriptServerRequest(const ExecuteCloudScriptServerRequest& src) :
                PlayFabRequestCommon(),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent),
                PlayFabId(src.PlayFabId),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision)
            {}

            ~ExecuteCloudScriptServerRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FunctionName")], FunctionName);
                FunctionParameter = input[U("FunctionParameter")];
                FromJsonUtilP(input[U("GeneratePlayStreamEvent")], GeneratePlayStreamEvent);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilE(input[U("RevisionSelection")], RevisionSelection);
                FromJsonUtilP(input[U("SpecificRevision")], SpecificRevision);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output[U("FunctionName")] = each_FunctionName;
                output[U("FunctionParameter")] = FunctionParameter;
                web::json::value each_GeneratePlayStreamEvent; ToJsonUtilP(GeneratePlayStreamEvent, each_GeneratePlayStreamEvent); output[U("GeneratePlayStreamEvent")] = each_GeneratePlayStreamEvent;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_RevisionSelection; ToJsonUtilE(RevisionSelection, each_RevisionSelection); output[U("RevisionSelection")] = each_RevisionSelection;
                web::json::value each_SpecificRevision; ToJsonUtilP(SpecificRevision, each_SpecificRevision); output[U("SpecificRevision")] = each_SpecificRevision;
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

        struct GetAllSegmentsRequest : public PlayFabRequestCommon
        {

            GetAllSegmentsRequest() :
                PlayFabRequestCommon()
            {}

            GetAllSegmentsRequest(const GetAllSegmentsRequest& src) :
                PlayFabRequestCommon()
            {}

            ~GetAllSegmentsRequest() { }

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

        struct GetAllSegmentsResult : public PlayFabResultCommon
        {
            std::list<GetSegmentResult> Segments;

            GetAllSegmentsResult() :
                PlayFabResultCommon(),
                Segments()
            {}

            GetAllSegmentsResult(const GetAllSegmentsResult& src) :
                PlayFabResultCommon(),
                Segments(src.Segments)
            {}

            ~GetAllSegmentsResult() { }

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
            std::string PlayFabId;

            GetCharacterDataResult() :
                PlayFabResultCommon(),
                CharacterId(),
                Data(),
                DataVersion(),
                PlayFabId()
            {}

            GetCharacterDataResult(const GetCharacterDataResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                DataVersion(src.DataVersion),
                PlayFabId(src.PlayFabId)
            {}

            ~GetCharacterDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilO(input[U("Data")], Data);
                FromJsonUtilP(input[U("DataVersion")], DataVersion);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output[U("DataVersion")] = each_DataVersion;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GetCharacterInventoryRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string PlayFabId;

            GetCharacterInventoryRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                PlayFabId()
            {}

            GetCharacterInventoryRequest(const GetCharacterInventoryRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId)
            {}

            ~GetCharacterInventoryRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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
            std::string PlayFabId;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetCharacterInventoryResult() :
                PlayFabResultCommon(),
                CharacterId(),
                Inventory(),
                PlayFabId(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetCharacterInventoryResult(const GetCharacterInventoryResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            ~GetCharacterInventoryResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilO(input[U("Inventory")], Inventory);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilP(input[U("VirtualCurrency")], VirtualCurrency);
                FromJsonUtilO(input[U("VirtualCurrencyRechargeTimes")], VirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[U("Inventory")] = each_Inventory;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                web::json::value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output[U("VirtualCurrencyRechargeTimes")] = each_VirtualCurrencyRechargeTimes;
                return output;
            }
        };

        struct GetCharacterLeaderboardRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::string CharacterType;
            Int32 MaxResultsCount;
            Int32 StartPosition;
            std::string StatisticName;

            GetCharacterLeaderboardRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount(),
                StartPosition(),
                StatisticName()
            {}

            GetCharacterLeaderboardRequest(const GetCharacterLeaderboardRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                StartPosition(src.StartPosition),
                StatisticName(src.StatisticName)
            {}

            ~GetCharacterLeaderboardRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("CharacterType")], CharacterType);
                FromJsonUtilP(input[U("MaxResultsCount")], MaxResultsCount);
                FromJsonUtilP(input[U("StartPosition")], StartPosition);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
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
            std::string PlayFabId;

            GetCharacterStatisticsRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                PlayFabId()
            {}

            GetCharacterStatisticsRequest(const GetCharacterStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId)
            {}

            ~GetCharacterStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GetCharacterStatisticsResult : public PlayFabResultCommon
        {
            std::string CharacterId;
            std::map<std::string, Int32> CharacterStatistics;
            std::string PlayFabId;

            GetCharacterStatisticsResult() :
                PlayFabResultCommon(),
                CharacterId(),
                CharacterStatistics(),
                PlayFabId()
            {}

            GetCharacterStatisticsResult(const GetCharacterStatisticsResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics),
                PlayFabId(src.PlayFabId)
            {}

            ~GetCharacterStatisticsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilP(input[U("CharacterStatistics")], CharacterStatistics);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CharacterStatistics; ToJsonUtilP(CharacterStatistics, each_CharacterStatistics); output[U("CharacterStatistics")] = each_CharacterStatistics;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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

        struct GetFriendLeaderboardRequest : public PlayFabRequestCommon
        {
            Boxed<bool> IncludeFacebookFriends;
            Boxed<bool> IncludeSteamFriends;
            Int32 MaxResultsCount;
            std::string PlayFabId;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            Int32 StartPosition;
            std::string StatisticName;
            Boxed<Int32> Version;

            GetFriendLeaderboardRequest() :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                MaxResultsCount(),
                PlayFabId(),
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
                PlayFabId(src.PlayFabId),
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
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
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
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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
            std::string PlayFabId;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;

            GetFriendsListRequest() :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(),
                IncludeSteamFriends(),
                PlayFabId(),
                ProfileConstraints()
            {}

            GetFriendsListRequest(const GetFriendsListRequest& src) :
                PlayFabRequestCommon(),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                IncludeSteamFriends(src.IncludeSteamFriends),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints)
            {}

            ~GetFriendsListRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("IncludeFacebookFriends")], IncludeFacebookFriends);
                FromJsonUtilP(input[U("IncludeSteamFriends")], IncludeSteamFriends);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilO(input[U("ProfileConstraints")], ProfileConstraints);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_IncludeFacebookFriends; ToJsonUtilP(IncludeFacebookFriends, each_IncludeFacebookFriends); output[U("IncludeFacebookFriends")] = each_IncludeFacebookFriends;
                web::json::value each_IncludeSteamFriends; ToJsonUtilP(IncludeSteamFriends, each_IncludeSteamFriends); output[U("IncludeSteamFriends")] = each_IncludeSteamFriends;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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
            Int32 MaxResultsCount;
            std::string PlayFabId;
            std::string StatisticName;

            GetLeaderboardAroundCharacterRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount(),
                PlayFabId(),
                StatisticName()
            {}

            GetLeaderboardAroundCharacterRequest(const GetLeaderboardAroundCharacterRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                StatisticName(src.StatisticName)
            {}

            ~GetLeaderboardAroundCharacterRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("CharacterType")], CharacterType);
                FromJsonUtilP(input[U("MaxResultsCount")], MaxResultsCount);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[U("CharacterType")] = each_CharacterType;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[U("MaxResultsCount")] = each_MaxResultsCount;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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

        struct GetLeaderboardAroundUserRequest : public PlayFabRequestCommon
        {
            Int32 MaxResultsCount;
            std::string PlayFabId;
            Boxed<PlayerProfileViewConstraints> ProfileConstraints;
            std::string StatisticName;
            Boxed<Int32> Version;

            GetLeaderboardAroundUserRequest() :
                PlayFabRequestCommon(),
                MaxResultsCount(),
                PlayFabId(),
                ProfileConstraints(),
                StatisticName(),
                Version()
            {}

            GetLeaderboardAroundUserRequest(const GetLeaderboardAroundUserRequest& src) :
                PlayFabRequestCommon(),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            ~GetLeaderboardAroundUserRequest() { }

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

        struct GetLeaderboardAroundUserResult : public PlayFabResultCommon
        {
            std::list<PlayerLeaderboardEntry> Leaderboard;
            Boxed<time_t> NextReset;
            Int32 Version;

            GetLeaderboardAroundUserResult() :
                PlayFabResultCommon(),
                Leaderboard(),
                NextReset(),
                Version()
            {}

            GetLeaderboardAroundUserResult(const GetLeaderboardAroundUserResult& src) :
                PlayFabResultCommon(),
                Leaderboard(src.Leaderboard),
                NextReset(src.NextReset),
                Version(src.Version)
            {}

            ~GetLeaderboardAroundUserResult() { }

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
            std::string PlayFabId;
            std::string StatisticName;

            GetLeaderboardForUsersCharactersRequest() :
                PlayFabRequestCommon(),
                MaxResultsCount(),
                PlayFabId(),
                StatisticName()
            {}

            GetLeaderboardForUsersCharactersRequest(const GetLeaderboardForUsersCharactersRequest& src) :
                PlayFabRequestCommon(),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                StatisticName(src.StatisticName)
            {}

            ~GetLeaderboardForUsersCharactersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("MaxResultsCount")], MaxResultsCount);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_MaxResultsCount; ToJsonUtilP(MaxResultsCount, each_MaxResultsCount); output[U("MaxResultsCount")] = each_MaxResultsCount;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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
            Int32 MaxResultsCount;
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

        struct GetPlayersInSegmentRequest : public PlayFabRequestCommon
        {
            std::string ContinuationToken;
            Boxed<Uint32> MaxBatchSize;
            Boxed<Uint32> SecondsToLive;
            std::string SegmentId;

            GetPlayersInSegmentRequest() :
                PlayFabRequestCommon(),
                ContinuationToken(),
                MaxBatchSize(),
                SecondsToLive(),
                SegmentId()
            {}

            GetPlayersInSegmentRequest(const GetPlayersInSegmentRequest& src) :
                PlayFabRequestCommon(),
                ContinuationToken(src.ContinuationToken),
                MaxBatchSize(src.MaxBatchSize),
                SecondsToLive(src.SecondsToLive),
                SegmentId(src.SegmentId)
            {}

            ~GetPlayersInSegmentRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ContinuationToken")], ContinuationToken);
                FromJsonUtilP(input[U("MaxBatchSize")], MaxBatchSize);
                FromJsonUtilP(input[U("SecondsToLive")], SecondsToLive);
                FromJsonUtilS(input[U("SegmentId")], SegmentId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output[U("ContinuationToken")] = each_ContinuationToken;
                web::json::value each_MaxBatchSize; ToJsonUtilP(MaxBatchSize, each_MaxBatchSize); output[U("MaxBatchSize")] = each_MaxBatchSize;
                web::json::value each_SecondsToLive; ToJsonUtilP(SecondsToLive, each_SecondsToLive); output[U("SecondsToLive")] = each_SecondsToLive;
                web::json::value each_SegmentId; ToJsonUtilS(SegmentId, each_SegmentId); output[U("SegmentId")] = each_SegmentId;
                return output;
            }
        };

        struct PlayerLinkedAccount : public PlayFabBaseModel
        {
            std::string Email;
            Boxed<LoginIdentityProvider> Platform;
            std::string PlatformUserId;
            std::string Username;

            PlayerLinkedAccount() :
                PlayFabBaseModel(),
                Email(),
                Platform(),
                PlatformUserId(),
                Username()
            {}

            PlayerLinkedAccount(const PlayerLinkedAccount& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username)
            {}

            ~PlayerLinkedAccount() { }

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

        struct PlayerLocation : public PlayFabBaseModel
        {
            std::string City;
            ContinentCode pfContinentCode;
            CountryCode pfCountryCode;
            Boxed<double> Latitude;
            Boxed<double> Longitude;

            PlayerLocation() :
                PlayFabBaseModel(),
                City(),
                pfContinentCode(),
                pfCountryCode(),
                Latitude(),
                Longitude()
            {}

            PlayerLocation(const PlayerLocation& src) :
                PlayFabBaseModel(),
                City(src.City),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            ~PlayerLocation() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("City")], City);
                FromJsonEnum(input[U("pfContinentCode")], pfContinentCode);
                FromJsonEnum(input[U("pfCountryCode")], pfCountryCode);
                FromJsonUtilP(input[U("Latitude")], Latitude);
                FromJsonUtilP(input[U("Longitude")], Longitude);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_City; ToJsonUtilS(City, each_City); output[U("City")] = each_City;
                web::json::value each_pfContinentCode; ToJsonEnum(pfContinentCode, each_pfContinentCode); output[U("ContinentCode")] = each_pfContinentCode;
                web::json::value each_pfCountryCode; ToJsonEnum(pfCountryCode, each_pfCountryCode); output[U("CountryCode")] = each_pfCountryCode;
                web::json::value each_Latitude; ToJsonUtilP(Latitude, each_Latitude); output[U("Latitude")] = each_Latitude;
                web::json::value each_Longitude; ToJsonUtilP(Longitude, each_Longitude); output[U("Longitude")] = each_Longitude;
                return output;
            }
        };

        struct PlayerStatistic : public PlayFabBaseModel
        {
            std::string Id;
            std::string Name;
            Int32 StatisticValue;
            Int32 StatisticVersion;

            PlayerStatistic() :
                PlayFabBaseModel(),
                Id(),
                Name(),
                StatisticValue(),
                StatisticVersion()
            {}

            PlayerStatistic(const PlayerStatistic& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name),
                StatisticValue(src.StatisticValue),
                StatisticVersion(src.StatisticVersion)
            {}

            ~PlayerStatistic() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Id")], Id);
                FromJsonUtilS(input[U("Name")], Name);
                FromJsonUtilP(input[U("StatisticValue")], StatisticValue);
                FromJsonUtilP(input[U("StatisticVersion")], StatisticVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Id; ToJsonUtilS(Id, each_Id); output[U("Id")] = each_Id;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                web::json::value each_StatisticValue; ToJsonUtilP(StatisticValue, each_StatisticValue); output[U("StatisticValue")] = each_StatisticValue;
                web::json::value each_StatisticVersion; ToJsonUtilP(StatisticVersion, each_StatisticVersion); output[U("StatisticVersion")] = each_StatisticVersion;
                return output;
            }
        };

        struct PushNotificationRegistration : public PlayFabBaseModel
        {
            std::string NotificationEndpointARN;
            Boxed<PushNotificationPlatform> Platform;

            PushNotificationRegistration() :
                PlayFabBaseModel(),
                NotificationEndpointARN(),
                Platform()
            {}

            PushNotificationRegistration(const PushNotificationRegistration& src) :
                PlayFabBaseModel(),
                NotificationEndpointARN(src.NotificationEndpointARN),
                Platform(src.Platform)
            {}

            ~PushNotificationRegistration() { }

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

        struct PlayerProfile : public PlayFabBaseModel
        {
            std::list<AdCampaignAttribution> AdCampaignAttributions;
            std::string AvatarUrl;
            Boxed<time_t> BannedUntil;
            std::list<ContactEmailInfo> ContactEmailAddresses;
            Boxed<time_t> Created;
            std::string DisplayName;
            Boxed<time_t> LastLogin;
            std::list<PlayerLinkedAccount> LinkedAccounts;
            std::map<std::string, PlayerLocation> Locations;
            Boxed<LoginIdentityProvider> Origination;
            std::string PlayerId;
            std::list<PlayerStatistic> PlayerStatistics;
            std::string PublisherId;
            std::list<PushNotificationRegistration> PushNotificationRegistrations;
            std::map<std::string, Int32> Statistics;
            std::list<std::string> Tags;
            std::string TitleId;
            Boxed<Uint32> TotalValueToDateInUSD;
            std::map<std::string, Uint32> ValuesToDate;
            std::map<std::string, Int32> VirtualCurrencyBalances;

            PlayerProfile() :
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
                Origination(),
                PlayerId(),
                PlayerStatistics(),
                PublisherId(),
                PushNotificationRegistrations(),
                Statistics(),
                Tags(),
                TitleId(),
                TotalValueToDateInUSD(),
                ValuesToDate(),
                VirtualCurrencyBalances()
            {}

            PlayerProfile(const PlayerProfile& src) :
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
                Origination(src.Origination),
                PlayerId(src.PlayerId),
                PlayerStatistics(src.PlayerStatistics),
                PublisherId(src.PublisherId),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                Statistics(src.Statistics),
                Tags(src.Tags),
                TitleId(src.TitleId),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances)
            {}

            ~PlayerProfile() { }

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
                FromJsonUtilE(input[U("Origination")], Origination);
                FromJsonUtilS(input[U("PlayerId")], PlayerId);
                FromJsonUtilO(input[U("PlayerStatistics")], PlayerStatistics);
                FromJsonUtilS(input[U("PublisherId")], PublisherId);
                FromJsonUtilO(input[U("PushNotificationRegistrations")], PushNotificationRegistrations);
                FromJsonUtilP(input[U("Statistics")], Statistics);
                FromJsonUtilS(input[U("Tags")], Tags);
                FromJsonUtilS(input[U("TitleId")], TitleId);
                FromJsonUtilP(input[U("TotalValueToDateInUSD")], TotalValueToDateInUSD);
                FromJsonUtilP(input[U("ValuesToDate")], ValuesToDate);
                FromJsonUtilP(input[U("VirtualCurrencyBalances")], VirtualCurrencyBalances);
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
                web::json::value each_Origination; ToJsonUtilE(Origination, each_Origination); output[U("Origination")] = each_Origination;
                web::json::value each_PlayerId; ToJsonUtilS(PlayerId, each_PlayerId); output[U("PlayerId")] = each_PlayerId;
                web::json::value each_PlayerStatistics; ToJsonUtilO(PlayerStatistics, each_PlayerStatistics); output[U("PlayerStatistics")] = each_PlayerStatistics;
                web::json::value each_PublisherId; ToJsonUtilS(PublisherId, each_PublisherId); output[U("PublisherId")] = each_PublisherId;
                web::json::value each_PushNotificationRegistrations; ToJsonUtilO(PushNotificationRegistrations, each_PushNotificationRegistrations); output[U("PushNotificationRegistrations")] = each_PushNotificationRegistrations;
                web::json::value each_Statistics; ToJsonUtilP(Statistics, each_Statistics); output[U("Statistics")] = each_Statistics;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[U("Tags")] = each_Tags;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                web::json::value each_TotalValueToDateInUSD; ToJsonUtilP(TotalValueToDateInUSD, each_TotalValueToDateInUSD); output[U("TotalValueToDateInUSD")] = each_TotalValueToDateInUSD;
                web::json::value each_ValuesToDate; ToJsonUtilP(ValuesToDate, each_ValuesToDate); output[U("ValuesToDate")] = each_ValuesToDate;
                web::json::value each_VirtualCurrencyBalances; ToJsonUtilP(VirtualCurrencyBalances, each_VirtualCurrencyBalances); output[U("VirtualCurrencyBalances")] = each_VirtualCurrencyBalances;
                return output;
            }
        };

        struct GetPlayersInSegmentResult : public PlayFabResultCommon
        {
            std::string ContinuationToken;
            std::list<PlayerProfile> PlayerProfiles;
            Int32 ProfilesInSegment;

            GetPlayersInSegmentResult() :
                PlayFabResultCommon(),
                ContinuationToken(),
                PlayerProfiles(),
                ProfilesInSegment()
            {}

            GetPlayersInSegmentResult(const GetPlayersInSegmentResult& src) :
                PlayFabResultCommon(),
                ContinuationToken(src.ContinuationToken),
                PlayerProfiles(src.PlayerProfiles),
                ProfilesInSegment(src.ProfilesInSegment)
            {}

            ~GetPlayersInSegmentResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ContinuationToken")], ContinuationToken);
                FromJsonUtilO(input[U("PlayerProfiles")], PlayerProfiles);
                FromJsonUtilP(input[U("ProfilesInSegment")], ProfilesInSegment);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ContinuationToken; ToJsonUtilS(ContinuationToken, each_ContinuationToken); output[U("ContinuationToken")] = each_ContinuationToken;
                web::json::value each_PlayerProfiles; ToJsonUtilO(PlayerProfiles, each_PlayerProfiles); output[U("PlayerProfiles")] = each_PlayerProfiles;
                web::json::value each_ProfilesInSegment; ToJsonUtilP(ProfilesInSegment, each_ProfilesInSegment); output[U("ProfilesInSegment")] = each_ProfilesInSegment;
                return output;
            }
        };

        struct GetPlayersSegmentsRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            GetPlayersSegmentsRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            GetPlayersSegmentsRequest(const GetPlayersSegmentsRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayersSegmentsRequest() { }

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
            std::string PlayFabId;
            std::list<std::string> StatisticNames;
            std::list<StatisticNameVersion> StatisticNameVersions;

            GetPlayerStatisticsRequest() :
                PlayFabRequestCommon(),
                PlayFabId(),
                StatisticNames(),
                StatisticNameVersions()
            {}

            GetPlayerStatisticsRequest(const GetPlayerStatisticsRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId),
                StatisticNames(src.StatisticNames),
                StatisticNameVersions(src.StatisticNameVersions)
            {}

            ~GetPlayerStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("StatisticNames")], StatisticNames);
                FromJsonUtilO(input[U("StatisticNameVersions")], StatisticNameVersions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_StatisticNames; ToJsonUtilS(StatisticNames, each_StatisticNames); output[U("StatisticNames")] = each_StatisticNames;
                web::json::value each_StatisticNameVersions; ToJsonUtilO(StatisticNameVersions, each_StatisticNameVersions); output[U("StatisticNameVersions")] = each_StatisticNameVersions;
                return output;
            }
        };

        struct GetPlayerStatisticsResult : public PlayFabResultCommon
        {
            std::string PlayFabId;
            std::list<StatisticValue> Statistics;

            GetPlayerStatisticsResult() :
                PlayFabResultCommon(),
                PlayFabId(),
                Statistics()
            {}

            GetPlayerStatisticsResult(const GetPlayerStatisticsResult& src) :
                PlayFabResultCommon(),
                PlayFabId(src.PlayFabId),
                Statistics(src.Statistics)
            {}

            ~GetPlayerStatisticsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilO(input[U("Statistics")], Statistics);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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

        struct GetRandomResultTablesRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::list<std::string> TableIDs;

            GetRandomResultTablesRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                TableIDs()
            {}

            GetRandomResultTablesRequest(const GetRandomResultTablesRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                TableIDs(src.TableIDs)
            {}

            ~GetRandomResultTablesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("TableIDs")], TableIDs);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_TableIDs; ToJsonUtilS(TableIDs, each_TableIDs); output[U("TableIDs")] = each_TableIDs;
                return output;
            }
        };

        struct ResultTableNode : public PlayFabBaseModel
        {
            std::string ResultItem;
            ResultTableNodeType ResultItemType;
            Int32 Weight;

            ResultTableNode() :
                PlayFabBaseModel(),
                ResultItem(),
                ResultItemType(),
                Weight()
            {}

            ResultTableNode(const ResultTableNode& src) :
                PlayFabBaseModel(),
                ResultItem(src.ResultItem),
                ResultItemType(src.ResultItemType),
                Weight(src.Weight)
            {}

            ~ResultTableNode() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ResultItem")], ResultItem);
                FromJsonEnum(input[U("ResultItemType")], ResultItemType);
                FromJsonUtilP(input[U("Weight")], Weight);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ResultItem; ToJsonUtilS(ResultItem, each_ResultItem); output[U("ResultItem")] = each_ResultItem;
                web::json::value each_ResultItemType; ToJsonEnum(ResultItemType, each_ResultItemType); output[U("ResultItemType")] = each_ResultItemType;
                web::json::value each_Weight; ToJsonUtilP(Weight, each_Weight); output[U("Weight")] = each_Weight;
                return output;
            }
        };

        struct RandomResultTableListing : public PlayFabBaseModel
        {
            std::string CatalogVersion;
            std::list<ResultTableNode> Nodes;
            std::string TableId;

            RandomResultTableListing() :
                PlayFabBaseModel(),
                CatalogVersion(),
                Nodes(),
                TableId()
            {}

            RandomResultTableListing(const RandomResultTableListing& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                Nodes(src.Nodes),
                TableId(src.TableId)
            {}

            ~RandomResultTableListing() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilO(input[U("Nodes")], Nodes);
                FromJsonUtilS(input[U("TableId")], TableId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_Nodes; ToJsonUtilO(Nodes, each_Nodes); output[U("Nodes")] = each_Nodes;
                web::json::value each_TableId; ToJsonUtilS(TableId, each_TableId); output[U("TableId")] = each_TableId;
                return output;
            }
        };

        struct GetRandomResultTablesResult : public PlayFabResultCommon
        {
            std::map<std::string, RandomResultTableListing> Tables;

            GetRandomResultTablesResult() :
                PlayFabResultCommon(),
                Tables()
            {}

            GetRandomResultTablesResult(const GetRandomResultTablesResult& src) :
                PlayFabResultCommon(),
                Tables(src.Tables)
            {}

            ~GetRandomResultTablesResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Tables")], Tables);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Tables; ToJsonUtilO(Tables, each_Tables); output[U("Tables")] = each_Tables;
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

        struct GetUserAccountInfoRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            GetUserAccountInfoRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            GetUserAccountInfoRequest(const GetUserAccountInfoRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~GetUserAccountInfoRequest() { }

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

        struct GetUserAccountInfoResult : public PlayFabResultCommon
        {
            Boxed<UserAccountInfo> UserInfo;

            GetUserAccountInfoResult() :
                PlayFabResultCommon(),
                UserInfo()
            {}

            GetUserAccountInfoResult(const GetUserAccountInfoResult& src) :
                PlayFabResultCommon(),
                UserInfo(src.UserInfo)
            {}

            ~GetUserAccountInfoResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("UserInfo")], UserInfo);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_UserInfo; ToJsonUtilO(UserInfo, each_UserInfo); output[U("UserInfo")] = each_UserInfo;
                return output;
            }
        };

        struct GetUserBansRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            GetUserBansRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            GetUserBansRequest(const GetUserBansRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~GetUserBansRequest() { }

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

        struct GetUserBansResult : public PlayFabResultCommon
        {
            std::list<BanInfo> BanData;

            GetUserBansResult() :
                PlayFabResultCommon(),
                BanData()
            {}

            GetUserBansResult(const GetUserBansResult& src) :
                PlayFabResultCommon(),
                BanData(src.BanData)
            {}

            ~GetUserBansResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("BanData")], BanData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanData; ToJsonUtilO(BanData, each_BanData); output[U("BanData")] = each_BanData;
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
            std::string PlayFabId;

            GetUserDataResult() :
                PlayFabResultCommon(),
                Data(),
                DataVersion(),
                PlayFabId()
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabResultCommon(),
                Data(src.Data),
                DataVersion(src.DataVersion),
                PlayFabId(src.PlayFabId)
            {}

            ~GetUserDataResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Data")], Data);
                FromJsonUtilP(input[U("DataVersion")], DataVersion);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilO(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_DataVersion; ToJsonUtilP(DataVersion, each_DataVersion); output[U("DataVersion")] = each_DataVersion;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GetUserInventoryRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            GetUserInventoryRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~GetUserInventoryRequest() { }

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

        struct GetUserInventoryResult : public PlayFabResultCommon
        {
            std::list<ItemInstance> Inventory;
            std::string PlayFabId;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabResultCommon(),
                Inventory(),
                PlayFabId(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabResultCommon(),
                Inventory(src.Inventory),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            ~GetUserInventoryResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Inventory")], Inventory);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilP(input[U("VirtualCurrency")], VirtualCurrency);
                FromJsonUtilO(input[U("VirtualCurrencyRechargeTimes")], VirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[U("Inventory")] = each_Inventory;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                web::json::value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output[U("VirtualCurrencyRechargeTimes")] = each_VirtualCurrencyRechargeTimes;
                return output;
            }
        };

        struct GrantCharacterToUserRequest : public PlayFabRequestCommon
        {
            std::string CharacterName;
            std::string CharacterType;
            std::string PlayFabId;

            GrantCharacterToUserRequest() :
                PlayFabRequestCommon(),
                CharacterName(),
                CharacterType(),
                PlayFabId()
            {}

            GrantCharacterToUserRequest(const GrantCharacterToUserRequest& src) :
                PlayFabRequestCommon(),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType),
                PlayFabId(src.PlayFabId)
            {}

            ~GrantCharacterToUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterName")], CharacterName);
                FromJsonUtilS(input[U("CharacterType")], CharacterType);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterName; ToJsonUtilS(CharacterName, each_CharacterName); output[U("CharacterName")] = each_CharacterName;
                web::json::value each_CharacterType; ToJsonUtilS(CharacterType, each_CharacterType); output[U("CharacterType")] = each_CharacterType;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GrantCharacterToUserResult : public PlayFabResultCommon
        {
            std::string CharacterId;

            GrantCharacterToUserResult() :
                PlayFabResultCommon(),
                CharacterId()
            {}

            GrantCharacterToUserResult(const GrantCharacterToUserResult& src) :
                PlayFabResultCommon(),
                CharacterId(src.CharacterId)
            {}

            ~GrantCharacterToUserResult() { }

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

        struct GrantedItemInstance : public PlayFabBaseModel
        {
            std::string Annotation;
            std::list<std::string> BundleContents;
            std::string BundleParent;
            std::string CatalogVersion;
            std::string CharacterId;
            std::map<std::string, std::string> CustomData;
            std::string DisplayName;
            Boxed<time_t> Expiration;
            std::string ItemClass;
            std::string ItemId;
            std::string ItemInstanceId;
            std::string PlayFabId;
            Boxed<time_t> PurchaseDate;
            Boxed<Int32> RemainingUses;
            bool Result;
            std::string UnitCurrency;
            Uint32 UnitPrice;
            Boxed<Int32> UsesIncrementedBy;

            GrantedItemInstance() :
                PlayFabBaseModel(),
                Annotation(),
                BundleContents(),
                BundleParent(),
                CatalogVersion(),
                CharacterId(),
                CustomData(),
                DisplayName(),
                Expiration(),
                ItemClass(),
                ItemId(),
                ItemInstanceId(),
                PlayFabId(),
                PurchaseDate(),
                RemainingUses(),
                Result(),
                UnitCurrency(),
                UnitPrice(),
                UsesIncrementedBy()
            {}

            GrantedItemInstance(const GrantedItemInstance& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                BundleContents(src.BundleContents),
                BundleParent(src.BundleParent),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CustomData(src.CustomData),
                DisplayName(src.DisplayName),
                Expiration(src.Expiration),
                ItemClass(src.ItemClass),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId),
                PurchaseDate(src.PurchaseDate),
                RemainingUses(src.RemainingUses),
                Result(src.Result),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                UsesIncrementedBy(src.UsesIncrementedBy)
            {}

            ~GrantedItemInstance() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Annotation")], Annotation);
                FromJsonUtilS(input[U("BundleContents")], BundleContents);
                FromJsonUtilS(input[U("BundleParent")], BundleParent);
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("CustomData")], CustomData);
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilT(input[U("Expiration")], Expiration);
                FromJsonUtilS(input[U("ItemClass")], ItemClass);
                FromJsonUtilS(input[U("ItemId")], ItemId);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilT(input[U("PurchaseDate")], PurchaseDate);
                FromJsonUtilP(input[U("RemainingUses")], RemainingUses);
                FromJsonUtilP(input[U("Result")], Result);
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
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CustomData; ToJsonUtilS(CustomData, each_CustomData); output[U("CustomData")] = each_CustomData;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_Expiration; ToJsonUtilT(Expiration, each_Expiration); output[U("Expiration")] = each_Expiration;
                web::json::value each_ItemClass; ToJsonUtilS(ItemClass, each_ItemClass); output[U("ItemClass")] = each_ItemClass;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_PurchaseDate; ToJsonUtilT(PurchaseDate, each_PurchaseDate); output[U("PurchaseDate")] = each_PurchaseDate;
                web::json::value each_RemainingUses; ToJsonUtilP(RemainingUses, each_RemainingUses); output[U("RemainingUses")] = each_RemainingUses;
                web::json::value each_Result; ToJsonUtilP(Result, each_Result); output[U("Result")] = each_Result;
                web::json::value each_UnitCurrency; ToJsonUtilS(UnitCurrency, each_UnitCurrency); output[U("UnitCurrency")] = each_UnitCurrency;
                web::json::value each_UnitPrice; ToJsonUtilP(UnitPrice, each_UnitPrice); output[U("UnitPrice")] = each_UnitPrice;
                web::json::value each_UsesIncrementedBy; ToJsonUtilP(UsesIncrementedBy, each_UsesIncrementedBy); output[U("UsesIncrementedBy")] = each_UsesIncrementedBy;
                return output;
            }
        };

        struct GrantItemsToCharacterRequest : public PlayFabRequestCommon
        {
            std::string Annotation;
            std::string CatalogVersion;
            std::string CharacterId;
            std::list<std::string> ItemIds;
            std::string PlayFabId;

            GrantItemsToCharacterRequest() :
                PlayFabRequestCommon(),
                Annotation(),
                CatalogVersion(),
                CharacterId(),
                ItemIds(),
                PlayFabId()
            {}

            GrantItemsToCharacterRequest(const GrantItemsToCharacterRequest& src) :
                PlayFabRequestCommon(),
                Annotation(src.Annotation),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ItemIds(src.ItemIds),
                PlayFabId(src.PlayFabId)
            {}

            ~GrantItemsToCharacterRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Annotation")], Annotation);
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("ItemIds")], ItemIds);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output[U("Annotation")] = each_Annotation;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ItemIds; ToJsonUtilS(ItemIds, each_ItemIds); output[U("ItemIds")] = each_ItemIds;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GrantItemsToCharacterResult : public PlayFabResultCommon
        {
            std::list<GrantedItemInstance> ItemGrantResults;

            GrantItemsToCharacterResult() :
                PlayFabResultCommon(),
                ItemGrantResults()
            {}

            GrantItemsToCharacterResult(const GrantItemsToCharacterResult& src) :
                PlayFabResultCommon(),
                ItemGrantResults(src.ItemGrantResults)
            {}

            ~GrantItemsToCharacterResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("ItemGrantResults")], ItemGrantResults);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ItemGrantResults; ToJsonUtilO(ItemGrantResults, each_ItemGrantResults); output[U("ItemGrantResults")] = each_ItemGrantResults;
                return output;
            }
        };

        struct GrantItemsToUserRequest : public PlayFabRequestCommon
        {
            std::string Annotation;
            std::string CatalogVersion;
            std::list<std::string> ItemIds;
            std::string PlayFabId;

            GrantItemsToUserRequest() :
                PlayFabRequestCommon(),
                Annotation(),
                CatalogVersion(),
                ItemIds(),
                PlayFabId()
            {}

            GrantItemsToUserRequest(const GrantItemsToUserRequest& src) :
                PlayFabRequestCommon(),
                Annotation(src.Annotation),
                CatalogVersion(src.CatalogVersion),
                ItemIds(src.ItemIds),
                PlayFabId(src.PlayFabId)
            {}

            ~GrantItemsToUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Annotation")], Annotation);
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("ItemIds")], ItemIds);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output[U("Annotation")] = each_Annotation;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_ItemIds; ToJsonUtilS(ItemIds, each_ItemIds); output[U("ItemIds")] = each_ItemIds;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GrantItemsToUserResult : public PlayFabResultCommon
        {
            std::list<GrantedItemInstance> ItemGrantResults;

            GrantItemsToUserResult() :
                PlayFabResultCommon(),
                ItemGrantResults()
            {}

            GrantItemsToUserResult(const GrantItemsToUserResult& src) :
                PlayFabResultCommon(),
                ItemGrantResults(src.ItemGrantResults)
            {}

            ~GrantItemsToUserResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("ItemGrantResults")], ItemGrantResults);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ItemGrantResults; ToJsonUtilO(ItemGrantResults, each_ItemGrantResults); output[U("ItemGrantResults")] = each_ItemGrantResults;
                return output;
            }
        };

        struct ItemGrant : public PlayFabBaseModel
        {
            std::string Annotation;
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::string ItemId;
            std::list<std::string> KeysToRemove;
            std::string PlayFabId;

            ItemGrant() :
                PlayFabBaseModel(),
                Annotation(),
                CharacterId(),
                Data(),
                ItemId(),
                KeysToRemove(),
                PlayFabId()
            {}

            ItemGrant(const ItemGrant& src) :
                PlayFabBaseModel(),
                Annotation(src.Annotation),
                CharacterId(src.CharacterId),
                Data(src.Data),
                ItemId(src.ItemId),
                KeysToRemove(src.KeysToRemove),
                PlayFabId(src.PlayFabId)
            {}

            ~ItemGrant() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Annotation")], Annotation);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("Data")], Data);
                FromJsonUtilS(input[U("ItemId")], ItemId);
                FromJsonUtilS(input[U("KeysToRemove")], KeysToRemove);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Annotation; ToJsonUtilS(Annotation, each_Annotation); output[U("Annotation")] = each_Annotation;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[U("KeysToRemove")] = each_KeysToRemove;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct GrantItemsToUsersRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::list<ItemGrant> ItemGrants;

            GrantItemsToUsersRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                ItemGrants()
            {}

            GrantItemsToUsersRequest(const GrantItemsToUsersRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                ItemGrants(src.ItemGrants)
            {}

            ~GrantItemsToUsersRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilO(input[U("ItemGrants")], ItemGrants);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_ItemGrants; ToJsonUtilO(ItemGrants, each_ItemGrants); output[U("ItemGrants")] = each_ItemGrants;
                return output;
            }
        };

        struct GrantItemsToUsersResult : public PlayFabResultCommon
        {
            std::list<GrantedItemInstance> ItemGrantResults;

            GrantItemsToUsersResult() :
                PlayFabResultCommon(),
                ItemGrantResults()
            {}

            GrantItemsToUsersResult(const GrantItemsToUsersResult& src) :
                PlayFabResultCommon(),
                ItemGrantResults(src.ItemGrantResults)
            {}

            ~GrantItemsToUsersResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("ItemGrantResults")], ItemGrantResults);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ItemGrantResults; ToJsonUtilO(ItemGrantResults, each_ItemGrantResults); output[U("ItemGrantResults")] = each_ItemGrantResults;
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

        struct ModifyCharacterVirtualCurrencyResult : public PlayFabResultCommon
        {
            Int32 Balance;
            std::string VirtualCurrency;

            ModifyCharacterVirtualCurrencyResult() :
                PlayFabResultCommon(),
                Balance(),
                VirtualCurrency()
            {}

            ModifyCharacterVirtualCurrencyResult(const ModifyCharacterVirtualCurrencyResult& src) :
                PlayFabResultCommon(),
                Balance(src.Balance),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~ModifyCharacterVirtualCurrencyResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Balance")], Balance);
                FromJsonUtilS(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Balance; ToJsonUtilP(Balance, each_Balance); output[U("Balance")] = each_Balance;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct ModifyItemUsesRequest : public PlayFabRequestCommon
        {
            std::string ItemInstanceId;
            std::string PlayFabId;
            Int32 UsesToAdd;

            ModifyItemUsesRequest() :
                PlayFabRequestCommon(),
                ItemInstanceId(),
                PlayFabId(),
                UsesToAdd()
            {}

            ModifyItemUsesRequest(const ModifyItemUsesRequest& src) :
                PlayFabRequestCommon(),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId),
                UsesToAdd(src.UsesToAdd)
            {}

            ~ModifyItemUsesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilP(input[U("UsesToAdd")], UsesToAdd);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_UsesToAdd; ToJsonUtilP(UsesToAdd, each_UsesToAdd); output[U("UsesToAdd")] = each_UsesToAdd;
                return output;
            }
        };

        struct ModifyItemUsesResult : public PlayFabResultCommon
        {
            std::string ItemInstanceId;
            Int32 RemainingUses;

            ModifyItemUsesResult() :
                PlayFabResultCommon(),
                ItemInstanceId(),
                RemainingUses()
            {}

            ModifyItemUsesResult(const ModifyItemUsesResult& src) :
                PlayFabResultCommon(),
                ItemInstanceId(src.ItemInstanceId),
                RemainingUses(src.RemainingUses)
            {}

            ~ModifyItemUsesResult() { }

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

        struct MoveItemToCharacterFromCharacterRequest : public PlayFabRequestCommon
        {
            std::string GivingCharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;
            std::string ReceivingCharacterId;

            MoveItemToCharacterFromCharacterRequest() :
                PlayFabRequestCommon(),
                GivingCharacterId(),
                ItemInstanceId(),
                PlayFabId(),
                ReceivingCharacterId()
            {}

            MoveItemToCharacterFromCharacterRequest(const MoveItemToCharacterFromCharacterRequest& src) :
                PlayFabRequestCommon(),
                GivingCharacterId(src.GivingCharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId),
                ReceivingCharacterId(src.ReceivingCharacterId)
            {}

            ~MoveItemToCharacterFromCharacterRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("GivingCharacterId")], GivingCharacterId);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("ReceivingCharacterId")], ReceivingCharacterId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GivingCharacterId; ToJsonUtilS(GivingCharacterId, each_GivingCharacterId); output[U("GivingCharacterId")] = each_GivingCharacterId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_ReceivingCharacterId; ToJsonUtilS(ReceivingCharacterId, each_ReceivingCharacterId); output[U("ReceivingCharacterId")] = each_ReceivingCharacterId;
                return output;
            }
        };

        struct MoveItemToCharacterFromCharacterResult : public PlayFabResultCommon
        {

            MoveItemToCharacterFromCharacterResult() :
                PlayFabResultCommon()
            {}

            MoveItemToCharacterFromCharacterResult(const MoveItemToCharacterFromCharacterResult& src) :
                PlayFabResultCommon()
            {}

            ~MoveItemToCharacterFromCharacterResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct MoveItemToCharacterFromUserRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            MoveItemToCharacterFromUserRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            MoveItemToCharacterFromUserRequest(const MoveItemToCharacterFromUserRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            ~MoveItemToCharacterFromUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct MoveItemToCharacterFromUserResult : public PlayFabResultCommon
        {

            MoveItemToCharacterFromUserResult() :
                PlayFabResultCommon()
            {}

            MoveItemToCharacterFromUserResult(const MoveItemToCharacterFromUserResult& src) :
                PlayFabResultCommon()
            {}

            ~MoveItemToCharacterFromUserResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct MoveItemToUserFromCharacterRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            MoveItemToUserFromCharacterRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            MoveItemToUserFromCharacterRequest(const MoveItemToUserFromCharacterRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            ~MoveItemToUserFromCharacterRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct MoveItemToUserFromCharacterResult : public PlayFabResultCommon
        {

            MoveItemToUserFromCharacterResult() :
                PlayFabResultCommon()
            {}

            MoveItemToUserFromCharacterResult(const MoveItemToUserFromCharacterResult& src) :
                PlayFabResultCommon()
            {}

            ~MoveItemToUserFromCharacterResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct NotifyMatchmakerPlayerLeftRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;
            std::string PlayFabId;

            NotifyMatchmakerPlayerLeftRequest() :
                PlayFabRequestCommon(),
                LobbyId(),
                PlayFabId()
            {}

            NotifyMatchmakerPlayerLeftRequest(const NotifyMatchmakerPlayerLeftRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId),
                PlayFabId(src.PlayFabId)
            {}

            ~NotifyMatchmakerPlayerLeftRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct NotifyMatchmakerPlayerLeftResult : public PlayFabResultCommon
        {
            Boxed<PlayerConnectionState> PlayerState;

            NotifyMatchmakerPlayerLeftResult() :
                PlayFabResultCommon(),
                PlayerState()
            {}

            NotifyMatchmakerPlayerLeftResult(const NotifyMatchmakerPlayerLeftResult& src) :
                PlayFabResultCommon(),
                PlayerState(src.PlayerState)
            {}

            ~NotifyMatchmakerPlayerLeftResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("PlayerState")], PlayerState);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayerState; ToJsonUtilE(PlayerState, each_PlayerState); output[U("PlayerState")] = each_PlayerState;
                return output;
            }
        };

        struct PushNotificationPackage : public PlayFabBaseModel
        {
            Int32 Badge;
            std::string CustomData;
            std::string Icon;
            std::string Message;
            std::string Sound;
            std::string Title;

            PushNotificationPackage() :
                PlayFabBaseModel(),
                Badge(),
                CustomData(),
                Icon(),
                Message(),
                Sound(),
                Title()
            {}

            PushNotificationPackage(const PushNotificationPackage& src) :
                PlayFabBaseModel(),
                Badge(src.Badge),
                CustomData(src.CustomData),
                Icon(src.Icon),
                Message(src.Message),
                Sound(src.Sound),
                Title(src.Title)
            {}

            ~PushNotificationPackage() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Badge")], Badge);
                FromJsonUtilS(input[U("CustomData")], CustomData);
                FromJsonUtilS(input[U("Icon")], Icon);
                FromJsonUtilS(input[U("Message")], Message);
                FromJsonUtilS(input[U("Sound")], Sound);
                FromJsonUtilS(input[U("Title")], Title);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Badge; ToJsonUtilP(Badge, each_Badge); output[U("Badge")] = each_Badge;
                web::json::value each_CustomData; ToJsonUtilS(CustomData, each_CustomData); output[U("CustomData")] = each_CustomData;
                web::json::value each_Icon; ToJsonUtilS(Icon, each_Icon); output[U("Icon")] = each_Icon;
                web::json::value each_Message; ToJsonUtilS(Message, each_Message); output[U("Message")] = each_Message;
                web::json::value each_Sound; ToJsonUtilS(Sound, each_Sound); output[U("Sound")] = each_Sound;
                web::json::value each_Title; ToJsonUtilS(Title, each_Title); output[U("Title")] = each_Title;
                return output;
            }
        };

        struct RedeemCouponRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string CouponCode;
            std::string PlayFabId;

            RedeemCouponRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                CouponCode(),
                PlayFabId()
            {}

            RedeemCouponRequest(const RedeemCouponRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                CouponCode(src.CouponCode),
                PlayFabId(src.PlayFabId)
            {}

            ~RedeemCouponRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("CouponCode")], CouponCode);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CouponCode; ToJsonUtilS(CouponCode, each_CouponCode); output[U("CouponCode")] = each_CouponCode;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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

        struct RedeemMatchmakerTicketRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;
            std::string Ticket;

            RedeemMatchmakerTicketRequest() :
                PlayFabRequestCommon(),
                LobbyId(),
                Ticket()
            {}

            RedeemMatchmakerTicketRequest(const RedeemMatchmakerTicketRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId),
                Ticket(src.Ticket)
            {}

            ~RedeemMatchmakerTicketRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
                FromJsonUtilS(input[U("Ticket")], Ticket);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                web::json::value each_Ticket; ToJsonUtilS(Ticket, each_Ticket); output[U("Ticket")] = each_Ticket;
                return output;
            }
        };

        struct RedeemMatchmakerTicketResult : public PlayFabResultCommon
        {
            std::string Error;
            bool TicketIsValid;
            Boxed<UserAccountInfo> UserInfo;

            RedeemMatchmakerTicketResult() :
                PlayFabResultCommon(),
                Error(),
                TicketIsValid(),
                UserInfo()
            {}

            RedeemMatchmakerTicketResult(const RedeemMatchmakerTicketResult& src) :
                PlayFabResultCommon(),
                Error(src.Error),
                TicketIsValid(src.TicketIsValid),
                UserInfo(src.UserInfo)
            {}

            ~RedeemMatchmakerTicketResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Error")], Error);
                FromJsonUtilP(input[U("TicketIsValid")], TicketIsValid);
                FromJsonUtilO(input[U("UserInfo")], UserInfo);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Error; ToJsonUtilS(Error, each_Error); output[U("Error")] = each_Error;
                web::json::value each_TicketIsValid; ToJsonUtilP(TicketIsValid, each_TicketIsValid); output[U("TicketIsValid")] = each_TicketIsValid;
                web::json::value each_UserInfo; ToJsonUtilO(UserInfo, each_UserInfo); output[U("UserInfo")] = each_UserInfo;
                return output;
            }
        };

        struct RefreshGameServerInstanceHeartbeatRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;

            RefreshGameServerInstanceHeartbeatRequest() :
                PlayFabRequestCommon(),
                LobbyId()
            {}

            RefreshGameServerInstanceHeartbeatRequest(const RefreshGameServerInstanceHeartbeatRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId)
            {}

            ~RefreshGameServerInstanceHeartbeatRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                return output;
            }
        };

        struct RefreshGameServerInstanceHeartbeatResult : public PlayFabResultCommon
        {

            RefreshGameServerInstanceHeartbeatResult() :
                PlayFabResultCommon()
            {}

            RefreshGameServerInstanceHeartbeatResult(const RefreshGameServerInstanceHeartbeatResult& src) :
                PlayFabResultCommon()
            {}

            ~RefreshGameServerInstanceHeartbeatResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RegisterGameRequest : public PlayFabRequestCommon
        {
            std::string Build;
            std::string GameMode;
            std::string LobbyId;
            Region pfRegion;
            std::string ServerHost;
            std::string ServerIPV6Address;
            std::string ServerPort;
            std::map<std::string, std::string> Tags;

            RegisterGameRequest() :
                PlayFabRequestCommon(),
                Build(),
                GameMode(),
                LobbyId(),
                pfRegion(),
                ServerHost(),
                ServerIPV6Address(),
                ServerPort(),
                Tags()
            {}

            RegisterGameRequest(const RegisterGameRequest& src) :
                PlayFabRequestCommon(),
                Build(src.Build),
                GameMode(src.GameMode),
                LobbyId(src.LobbyId),
                pfRegion(src.pfRegion),
                ServerHost(src.ServerHost),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort),
                Tags(src.Tags)
            {}

            ~RegisterGameRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Build")], Build);
                FromJsonUtilS(input[U("GameMode")], GameMode);
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
                FromJsonEnum(input[U("pfRegion")], pfRegion);
                FromJsonUtilS(input[U("ServerHost")], ServerHost);
                FromJsonUtilS(input[U("ServerIPV6Address")], ServerIPV6Address);
                FromJsonUtilS(input[U("ServerPort")], ServerPort);
                FromJsonUtilS(input[U("Tags")], Tags);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Build; ToJsonUtilS(Build, each_Build); output[U("Build")] = each_Build;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[U("GameMode")] = each_GameMode;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                web::json::value each_pfRegion; ToJsonEnum(pfRegion, each_pfRegion); output[U("Region")] = each_pfRegion;
                web::json::value each_ServerHost; ToJsonUtilS(ServerHost, each_ServerHost); output[U("ServerHost")] = each_ServerHost;
                web::json::value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output[U("ServerIPV6Address")] = each_ServerIPV6Address;
                web::json::value each_ServerPort; ToJsonUtilS(ServerPort, each_ServerPort); output[U("ServerPort")] = each_ServerPort;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[U("Tags")] = each_Tags;
                return output;
            }
        };

        struct RegisterGameResponse : public PlayFabResultCommon
        {
            std::string LobbyId;

            RegisterGameResponse() :
                PlayFabResultCommon(),
                LobbyId()
            {}

            RegisterGameResponse(const RegisterGameResponse& src) :
                PlayFabResultCommon(),
                LobbyId(src.LobbyId)
            {}

            ~RegisterGameResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                return output;
            }
        };

        struct RemoveFriendRequest : public PlayFabRequestCommon
        {
            std::string FriendPlayFabId;
            std::string PlayFabId;

            RemoveFriendRequest() :
                PlayFabRequestCommon(),
                FriendPlayFabId(),
                PlayFabId()
            {}

            RemoveFriendRequest(const RemoveFriendRequest& src) :
                PlayFabRequestCommon(),
                FriendPlayFabId(src.FriendPlayFabId),
                PlayFabId(src.PlayFabId)
            {}

            ~RemoveFriendRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FriendPlayFabId")], FriendPlayFabId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[U("FriendPlayFabId")] = each_FriendPlayFabId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct RemovePlayerTagRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;
            std::string TagName;

            RemovePlayerTagRequest() :
                PlayFabRequestCommon(),
                PlayFabId(),
                TagName()
            {}

            RemovePlayerTagRequest(const RemovePlayerTagRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            ~RemovePlayerTagRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("TagName")], TagName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_TagName; ToJsonUtilS(TagName, each_TagName); output[U("TagName")] = each_TagName;
                return output;
            }
        };

        struct RemovePlayerTagResult : public PlayFabResultCommon
        {

            RemovePlayerTagResult() :
                PlayFabResultCommon()
            {}

            RemovePlayerTagResult(const RemovePlayerTagResult& src) :
                PlayFabResultCommon()
            {}

            ~RemovePlayerTagResult() { }

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

        struct ReportPlayerServerRequest : public PlayFabRequestCommon
        {
            std::string Comment;
            std::string ReporteeId;
            std::string ReporterId;

            ReportPlayerServerRequest() :
                PlayFabRequestCommon(),
                Comment(),
                ReporteeId(),
                ReporterId()
            {}

            ReportPlayerServerRequest(const ReportPlayerServerRequest& src) :
                PlayFabRequestCommon(),
                Comment(src.Comment),
                ReporteeId(src.ReporteeId),
                ReporterId(src.ReporterId)
            {}

            ~ReportPlayerServerRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Comment")], Comment);
                FromJsonUtilS(input[U("ReporteeId")], ReporteeId);
                FromJsonUtilS(input[U("ReporterId")], ReporterId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[U("Comment")] = each_Comment;
                web::json::value each_ReporteeId; ToJsonUtilS(ReporteeId, each_ReporteeId); output[U("ReporteeId")] = each_ReporteeId;
                web::json::value each_ReporterId; ToJsonUtilS(ReporterId, each_ReporterId); output[U("ReporterId")] = each_ReporterId;
                return output;
            }
        };

        struct ReportPlayerServerResult : public PlayFabResultCommon
        {
            Int32 SubmissionsRemaining;

            ReportPlayerServerResult() :
                PlayFabResultCommon(),
                SubmissionsRemaining()
            {}

            ReportPlayerServerResult(const ReportPlayerServerResult& src) :
                PlayFabResultCommon(),
                SubmissionsRemaining(src.SubmissionsRemaining)
            {}

            ~ReportPlayerServerResult() { }

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

        struct RevokeAllBansForUserRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            RevokeAllBansForUserRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            RevokeAllBansForUserRequest(const RevokeAllBansForUserRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~RevokeAllBansForUserRequest() { }

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

        struct RevokeAllBansForUserResult : public PlayFabResultCommon
        {
            std::list<BanInfo> BanData;

            RevokeAllBansForUserResult() :
                PlayFabResultCommon(),
                BanData()
            {}

            RevokeAllBansForUserResult(const RevokeAllBansForUserResult& src) :
                PlayFabResultCommon(),
                BanData(src.BanData)
            {}

            ~RevokeAllBansForUserResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("BanData")], BanData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanData; ToJsonUtilO(BanData, each_BanData); output[U("BanData")] = each_BanData;
                return output;
            }
        };

        struct RevokeBansRequest : public PlayFabRequestCommon
        {
            std::list<std::string> BanIds;

            RevokeBansRequest() :
                PlayFabRequestCommon(),
                BanIds()
            {}

            RevokeBansRequest(const RevokeBansRequest& src) :
                PlayFabRequestCommon(),
                BanIds(src.BanIds)
            {}

            ~RevokeBansRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BanIds")], BanIds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanIds; ToJsonUtilS(BanIds, each_BanIds); output[U("BanIds")] = each_BanIds;
                return output;
            }
        };

        struct RevokeBansResult : public PlayFabResultCommon
        {
            std::list<BanInfo> BanData;

            RevokeBansResult() :
                PlayFabResultCommon(),
                BanData()
            {}

            RevokeBansResult(const RevokeBansResult& src) :
                PlayFabResultCommon(),
                BanData(src.BanData)
            {}

            ~RevokeBansResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("BanData")], BanData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanData; ToJsonUtilO(BanData, each_BanData); output[U("BanData")] = each_BanData;
                return output;
            }
        };

        struct RevokeInventoryItem : public PlayFabBaseModel
        {
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            RevokeInventoryItem() :
                PlayFabBaseModel(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            RevokeInventoryItem(const RevokeInventoryItem& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            ~RevokeInventoryItem() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct RevokeInventoryItemRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::string ItemInstanceId;
            std::string PlayFabId;

            RevokeInventoryItemRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                ItemInstanceId(),
                PlayFabId()
            {}

            RevokeInventoryItemRequest(const RevokeInventoryItemRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            ~RevokeInventoryItemRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct RevokeInventoryItemsRequest : public PlayFabRequestCommon
        {
            std::list<RevokeInventoryItem> Items;

            RevokeInventoryItemsRequest() :
                PlayFabRequestCommon(),
                Items()
            {}

            RevokeInventoryItemsRequest(const RevokeInventoryItemsRequest& src) :
                PlayFabRequestCommon(),
                Items(src.Items)
            {}

            ~RevokeInventoryItemsRequest() { }

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

        struct RevokeItemError : public PlayFabBaseModel
        {
            Boxed<GenericErrorCodes> Error;
            Boxed<RevokeInventoryItem> Item;

            RevokeItemError() :
                PlayFabBaseModel(),
                Error(),
                Item()
            {}

            RevokeItemError(const RevokeItemError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Item(src.Item)
            {}

            ~RevokeItemError() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("Error")], Error);
                FromJsonUtilO(input[U("Item")], Item);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Error; ToJsonUtilE(Error, each_Error); output[U("Error")] = each_Error;
                web::json::value each_Item; ToJsonUtilO(Item, each_Item); output[U("Item")] = each_Item;
                return output;
            }
        };

        struct RevokeInventoryItemsResult : public PlayFabResultCommon
        {
            std::list<RevokeItemError> Errors;

            RevokeInventoryItemsResult() :
                PlayFabResultCommon(),
                Errors()
            {}

            RevokeInventoryItemsResult(const RevokeInventoryItemsResult& src) :
                PlayFabResultCommon(),
                Errors(src.Errors)
            {}

            ~RevokeInventoryItemsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Errors")], Errors);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Errors; ToJsonUtilO(Errors, each_Errors); output[U("Errors")] = each_Errors;
                return output;
            }
        };

        struct RevokeInventoryResult : public PlayFabResultCommon
        {

            RevokeInventoryResult() :
                PlayFabResultCommon()
            {}

            RevokeInventoryResult(const RevokeInventoryResult& src) :
                PlayFabResultCommon()
            {}

            ~RevokeInventoryResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SendCustomAccountRecoveryEmailRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string EmailTemplateId;
            std::string Username;

            SendCustomAccountRecoveryEmailRequest() :
                PlayFabRequestCommon(),
                Email(),
                EmailTemplateId(),
                Username()
            {}

            SendCustomAccountRecoveryEmailRequest(const SendCustomAccountRecoveryEmailRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                EmailTemplateId(src.EmailTemplateId),
                Username(src.Username)
            {}

            ~SendCustomAccountRecoveryEmailRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Email")], Email);
                FromJsonUtilS(input[U("EmailTemplateId")], EmailTemplateId);
                FromJsonUtilS(input[U("Username")], Username);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[U("Email")] = each_Email;
                web::json::value each_EmailTemplateId; ToJsonUtilS(EmailTemplateId, each_EmailTemplateId); output[U("EmailTemplateId")] = each_EmailTemplateId;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                return output;
            }
        };

        struct SendCustomAccountRecoveryEmailResult : public PlayFabResultCommon
        {

            SendCustomAccountRecoveryEmailResult() :
                PlayFabResultCommon()
            {}

            SendCustomAccountRecoveryEmailResult(const SendCustomAccountRecoveryEmailResult& src) :
                PlayFabResultCommon()
            {}

            ~SendCustomAccountRecoveryEmailResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SendEmailFromTemplateRequest : public PlayFabRequestCommon
        {
            std::string EmailTemplateId;
            std::string PlayFabId;

            SendEmailFromTemplateRequest() :
                PlayFabRequestCommon(),
                EmailTemplateId(),
                PlayFabId()
            {}

            SendEmailFromTemplateRequest(const SendEmailFromTemplateRequest& src) :
                PlayFabRequestCommon(),
                EmailTemplateId(src.EmailTemplateId),
                PlayFabId(src.PlayFabId)
            {}

            ~SendEmailFromTemplateRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("EmailTemplateId")], EmailTemplateId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_EmailTemplateId; ToJsonUtilS(EmailTemplateId, each_EmailTemplateId); output[U("EmailTemplateId")] = each_EmailTemplateId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct SendEmailFromTemplateResult : public PlayFabResultCommon
        {

            SendEmailFromTemplateResult() :
                PlayFabResultCommon()
            {}

            SendEmailFromTemplateResult(const SendEmailFromTemplateResult& src) :
                PlayFabResultCommon()
            {}

            ~SendEmailFromTemplateResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SendPushNotificationRequest : public PlayFabRequestCommon
        {
            std::list<AdvancedPushPlatformMsg> AdvancedPlatformDelivery;
            std::string Message;
            Boxed<PushNotificationPackage> Package;
            std::string Recipient;
            std::string Subject;
            std::list<PushNotificationPlatform> TargetPlatforms;

            SendPushNotificationRequest() :
                PlayFabRequestCommon(),
                AdvancedPlatformDelivery(),
                Message(),
                Package(),
                Recipient(),
                Subject(),
                TargetPlatforms()
            {}

            SendPushNotificationRequest(const SendPushNotificationRequest& src) :
                PlayFabRequestCommon(),
                AdvancedPlatformDelivery(src.AdvancedPlatformDelivery),
                Message(src.Message),
                Package(src.Package),
                Recipient(src.Recipient),
                Subject(src.Subject),
                TargetPlatforms(src.TargetPlatforms)
            {}

            ~SendPushNotificationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("AdvancedPlatformDelivery")], AdvancedPlatformDelivery);
                FromJsonUtilS(input[U("Message")], Message);
                FromJsonUtilO(input[U("Package")], Package);
                FromJsonUtilS(input[U("Recipient")], Recipient);
                FromJsonUtilS(input[U("Subject")], Subject);
                FromJsonUtilE(input[U("TargetPlatforms")], TargetPlatforms);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AdvancedPlatformDelivery; ToJsonUtilO(AdvancedPlatformDelivery, each_AdvancedPlatformDelivery); output[U("AdvancedPlatformDelivery")] = each_AdvancedPlatformDelivery;
                web::json::value each_Message; ToJsonUtilS(Message, each_Message); output[U("Message")] = each_Message;
                web::json::value each_Package; ToJsonUtilO(Package, each_Package); output[U("Package")] = each_Package;
                web::json::value each_Recipient; ToJsonUtilS(Recipient, each_Recipient); output[U("Recipient")] = each_Recipient;
                web::json::value each_Subject; ToJsonUtilS(Subject, each_Subject); output[U("Subject")] = each_Subject;
                web::json::value each_TargetPlatforms; ToJsonUtilE(TargetPlatforms, each_TargetPlatforms); output[U("TargetPlatforms")] = each_TargetPlatforms;
                return output;
            }
        };

        struct SendPushNotificationResult : public PlayFabResultCommon
        {

            SendPushNotificationResult() :
                PlayFabResultCommon()
            {}

            SendPushNotificationResult(const SendPushNotificationResult& src) :
                PlayFabResultCommon()
            {}

            ~SendPushNotificationResult() { }

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
            std::string PlayFabId;
            std::list<std::string> Tags;

            SetFriendTagsRequest() :
                PlayFabRequestCommon(),
                FriendPlayFabId(),
                PlayFabId(),
                Tags()
            {}

            SetFriendTagsRequest(const SetFriendTagsRequest& src) :
                PlayFabRequestCommon(),
                FriendPlayFabId(src.FriendPlayFabId),
                PlayFabId(src.PlayFabId),
                Tags(src.Tags)
            {}

            ~SetFriendTagsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FriendPlayFabId")], FriendPlayFabId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("Tags")], Tags);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendPlayFabId; ToJsonUtilS(FriendPlayFabId, each_FriendPlayFabId); output[U("FriendPlayFabId")] = each_FriendPlayFabId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[U("Tags")] = each_Tags;
                return output;
            }
        };

        struct SetGameServerInstanceDataRequest : public PlayFabRequestCommon
        {
            std::string GameServerData;
            std::string LobbyId;

            SetGameServerInstanceDataRequest() :
                PlayFabRequestCommon(),
                GameServerData(),
                LobbyId()
            {}

            SetGameServerInstanceDataRequest(const SetGameServerInstanceDataRequest& src) :
                PlayFabRequestCommon(),
                GameServerData(src.GameServerData),
                LobbyId(src.LobbyId)
            {}

            ~SetGameServerInstanceDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("GameServerData")], GameServerData);
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameServerData; ToJsonUtilS(GameServerData, each_GameServerData); output[U("GameServerData")] = each_GameServerData;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                return output;
            }
        };

        struct SetGameServerInstanceDataResult : public PlayFabResultCommon
        {

            SetGameServerInstanceDataResult() :
                PlayFabResultCommon()
            {}

            SetGameServerInstanceDataResult(const SetGameServerInstanceDataResult& src) :
                PlayFabResultCommon()
            {}

            ~SetGameServerInstanceDataResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetGameServerInstanceStateRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;
            GameInstanceState State;

            SetGameServerInstanceStateRequest() :
                PlayFabRequestCommon(),
                LobbyId(),
                State()
            {}

            SetGameServerInstanceStateRequest(const SetGameServerInstanceStateRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId),
                State(src.State)
            {}

            ~SetGameServerInstanceStateRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
                FromJsonEnum(input[U("State")], State);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                web::json::value each_State; ToJsonEnum(State, each_State); output[U("State")] = each_State;
                return output;
            }
        };

        struct SetGameServerInstanceStateResult : public PlayFabResultCommon
        {

            SetGameServerInstanceStateResult() :
                PlayFabResultCommon()
            {}

            SetGameServerInstanceStateResult(const SetGameServerInstanceStateResult& src) :
                PlayFabResultCommon()
            {}

            ~SetGameServerInstanceStateResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetGameServerInstanceTagsRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;
            std::map<std::string, std::string> Tags;

            SetGameServerInstanceTagsRequest() :
                PlayFabRequestCommon(),
                LobbyId(),
                Tags()
            {}

            SetGameServerInstanceTagsRequest(const SetGameServerInstanceTagsRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId),
                Tags(src.Tags)
            {}

            ~SetGameServerInstanceTagsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
                FromJsonUtilS(input[U("Tags")], Tags);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                web::json::value each_Tags; ToJsonUtilS(Tags, each_Tags); output[U("Tags")] = each_Tags;
                return output;
            }
        };

        struct SetGameServerInstanceTagsResult : public PlayFabResultCommon
        {

            SetGameServerInstanceTagsResult() :
                PlayFabResultCommon()
            {}

            SetGameServerInstanceTagsResult(const SetGameServerInstanceTagsResult& src) :
                PlayFabResultCommon()
            {}

            ~SetGameServerInstanceTagsResult() { }

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
            std::string PlayerSecret;
            std::string PlayFabId;

            SetPlayerSecretRequest() :
                PlayFabRequestCommon(),
                PlayerSecret(),
                PlayFabId()
            {}

            SetPlayerSecretRequest(const SetPlayerSecretRequest& src) :
                PlayFabRequestCommon(),
                PlayerSecret(src.PlayerSecret),
                PlayFabId(src.PlayFabId)
            {}

            ~SetPlayerSecretRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PlayerSecret")], PlayerSecret);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PlayerSecret; ToJsonUtilS(PlayerSecret, each_PlayerSecret); output[U("PlayerSecret")] = each_PlayerSecret;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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

        struct SetPublisherDataRequest : public PlayFabRequestCommon
        {
            std::string Key;
            std::string Value;

            SetPublisherDataRequest() :
                PlayFabRequestCommon(),
                Key(),
                Value()
            {}

            SetPublisherDataRequest(const SetPublisherDataRequest& src) :
                PlayFabRequestCommon(),
                Key(src.Key),
                Value(src.Value)
            {}

            ~SetPublisherDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Key")], Key);
                FromJsonUtilS(input[U("Value")], Value);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[U("Key")] = each_Key;
                web::json::value each_Value; ToJsonUtilS(Value, each_Value); output[U("Value")] = each_Value;
                return output;
            }
        };

        struct SetPublisherDataResult : public PlayFabResultCommon
        {

            SetPublisherDataResult() :
                PlayFabResultCommon()
            {}

            SetPublisherDataResult(const SetPublisherDataResult& src) :
                PlayFabResultCommon()
            {}

            ~SetPublisherDataResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SetTitleDataRequest : public PlayFabRequestCommon
        {
            std::string Key;
            std::string Value;

            SetTitleDataRequest() :
                PlayFabRequestCommon(),
                Key(),
                Value()
            {}

            SetTitleDataRequest(const SetTitleDataRequest& src) :
                PlayFabRequestCommon(),
                Key(src.Key),
                Value(src.Value)
            {}

            ~SetTitleDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Key")], Key);
                FromJsonUtilS(input[U("Value")], Value);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[U("Key")] = each_Key;
                web::json::value each_Value; ToJsonUtilS(Value, each_Value); output[U("Value")] = each_Value;
                return output;
            }
        };

        struct SetTitleDataResult : public PlayFabResultCommon
        {

            SetTitleDataResult() :
                PlayFabResultCommon()
            {}

            SetTitleDataResult(const SetTitleDataResult& src) :
                PlayFabResultCommon()
            {}

            ~SetTitleDataResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
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

        struct SubtractCharacterVirtualCurrencyRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string CharacterId;
            std::string PlayFabId;
            std::string VirtualCurrency;

            SubtractCharacterVirtualCurrencyRequest() :
                PlayFabRequestCommon(),
                Amount(),
                CharacterId(),
                PlayFabId(),
                VirtualCurrency()
            {}

            SubtractCharacterVirtualCurrencyRequest(const SubtractCharacterVirtualCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~SubtractCharacterVirtualCurrencyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Amount")], Amount);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[U("Amount")] = each_Amount;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct SubtractUserVirtualCurrencyRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string PlayFabId;
            std::string VirtualCurrency;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabRequestCommon(),
                Amount(),
                PlayFabId(),
                VirtualCurrency()
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency)
            {}

            ~SubtractUserVirtualCurrencyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Amount")], Amount);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("VirtualCurrency")], VirtualCurrency);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[U("Amount")] = each_Amount;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_VirtualCurrency; ToJsonUtilS(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                return output;
            }
        };

        struct UnlockContainerInstanceRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ContainerItemInstanceId;
            std::string KeyItemInstanceId;
            std::string PlayFabId;

            UnlockContainerInstanceRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemInstanceId(),
                KeyItemInstanceId(),
                PlayFabId()
            {}

            UnlockContainerInstanceRequest(const UnlockContainerInstanceRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemInstanceId(src.ContainerItemInstanceId),
                KeyItemInstanceId(src.KeyItemInstanceId),
                PlayFabId(src.PlayFabId)
            {}

            ~UnlockContainerInstanceRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("ContainerItemInstanceId")], ContainerItemInstanceId);
                FromJsonUtilS(input[U("KeyItemInstanceId")], KeyItemInstanceId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ContainerItemInstanceId; ToJsonUtilS(ContainerItemInstanceId, each_ContainerItemInstanceId); output[U("ContainerItemInstanceId")] = each_ContainerItemInstanceId;
                web::json::value each_KeyItemInstanceId; ToJsonUtilS(KeyItemInstanceId, each_KeyItemInstanceId); output[U("KeyItemInstanceId")] = each_KeyItemInstanceId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct UnlockContainerItemRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string CharacterId;
            std::string ContainerItemId;
            std::string PlayFabId;

            UnlockContainerItemRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                CharacterId(),
                ContainerItemId(),
                PlayFabId()
            {}

            UnlockContainerItemRequest(const UnlockContainerItemRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId),
                ContainerItemId(src.ContainerItemId),
                PlayFabId(src.PlayFabId)
            {}

            ~UnlockContainerItemRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("ContainerItemId")], ContainerItemId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_ContainerItemId; ToJsonUtilS(ContainerItemId, each_ContainerItemId); output[U("ContainerItemId")] = each_ContainerItemId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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
            std::string PlayFabId;

            UpdateAvatarUrlRequest() :
                PlayFabRequestCommon(),
                ImageUrl(),
                PlayFabId()
            {}

            UpdateAvatarUrlRequest(const UpdateAvatarUrlRequest& src) :
                PlayFabRequestCommon(),
                ImageUrl(src.ImageUrl),
                PlayFabId(src.PlayFabId)
            {}

            ~UpdateAvatarUrlRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ImageUrl")], ImageUrl);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ImageUrl; ToJsonUtilS(ImageUrl, each_ImageUrl); output[U("ImageUrl")] = each_ImageUrl;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct UpdateBanRequest : public PlayFabRequestCommon
        {
            Boxed<bool> Active;
            std::string BanId;
            Boxed<time_t> Expires;
            std::string IPAddress;
            std::string MACAddress;
            Boxed<bool> Permanent;
            std::string Reason;

            UpdateBanRequest() :
                PlayFabRequestCommon(),
                Active(),
                BanId(),
                Expires(),
                IPAddress(),
                MACAddress(),
                Permanent(),
                Reason()
            {}

            UpdateBanRequest(const UpdateBanRequest& src) :
                PlayFabRequestCommon(),
                Active(src.Active),
                BanId(src.BanId),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Permanent(src.Permanent),
                Reason(src.Reason)
            {}

            ~UpdateBanRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Active")], Active);
                FromJsonUtilS(input[U("BanId")], BanId);
                FromJsonUtilT(input[U("Expires")], Expires);
                FromJsonUtilS(input[U("IPAddress")], IPAddress);
                FromJsonUtilS(input[U("MACAddress")], MACAddress);
                FromJsonUtilP(input[U("Permanent")], Permanent);
                FromJsonUtilS(input[U("Reason")], Reason);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Active; ToJsonUtilP(Active, each_Active); output[U("Active")] = each_Active;
                web::json::value each_BanId; ToJsonUtilS(BanId, each_BanId); output[U("BanId")] = each_BanId;
                web::json::value each_Expires; ToJsonUtilT(Expires, each_Expires); output[U("Expires")] = each_Expires;
                web::json::value each_IPAddress; ToJsonUtilS(IPAddress, each_IPAddress); output[U("IPAddress")] = each_IPAddress;
                web::json::value each_MACAddress; ToJsonUtilS(MACAddress, each_MACAddress); output[U("MACAddress")] = each_MACAddress;
                web::json::value each_Permanent; ToJsonUtilP(Permanent, each_Permanent); output[U("Permanent")] = each_Permanent;
                web::json::value each_Reason; ToJsonUtilS(Reason, each_Reason); output[U("Reason")] = each_Reason;
                return output;
            }
        };

        struct UpdateBansRequest : public PlayFabRequestCommon
        {
            std::list<UpdateBanRequest> Bans;

            UpdateBansRequest() :
                PlayFabRequestCommon(),
                Bans()
            {}

            UpdateBansRequest(const UpdateBansRequest& src) :
                PlayFabRequestCommon(),
                Bans(src.Bans)
            {}

            ~UpdateBansRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Bans")], Bans);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Bans; ToJsonUtilO(Bans, each_Bans); output[U("Bans")] = each_Bans;
                return output;
            }
        };

        struct UpdateBansResult : public PlayFabResultCommon
        {
            std::list<BanInfo> BanData;

            UpdateBansResult() :
                PlayFabResultCommon(),
                BanData()
            {}

            UpdateBansResult(const UpdateBansResult& src) :
                PlayFabResultCommon(),
                BanData(src.BanData)
            {}

            ~UpdateBansResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("BanData")], BanData);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BanData; ToJsonUtilO(BanData, each_BanData); output[U("BanData")] = each_BanData;
                return output;
            }
        };

        struct UpdateCharacterDataRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;
            std::string PlayFabId;

            UpdateCharacterDataRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                Data(),
                KeysToRemove(),
                Permission(),
                PlayFabId()
            {}

            UpdateCharacterDataRequest(const UpdateCharacterDataRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                PlayFabId(src.PlayFabId)
            {}

            ~UpdateCharacterDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("Data")], Data);
                FromJsonUtilS(input[U("KeysToRemove")], KeysToRemove);
                FromJsonUtilE(input[U("Permission")], Permission);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[U("KeysToRemove")] = each_KeysToRemove;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[U("Permission")] = each_Permission;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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
            std::string PlayFabId;

            UpdateCharacterStatisticsRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                CharacterStatistics(),
                PlayFabId()
            {}

            UpdateCharacterStatisticsRequest(const UpdateCharacterStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics),
                PlayFabId(src.PlayFabId)
            {}

            ~UpdateCharacterStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilP(input[U("CharacterStatistics")], CharacterStatistics);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_CharacterStatistics; ToJsonUtilP(CharacterStatistics, each_CharacterStatistics); output[U("CharacterStatistics")] = each_CharacterStatistics;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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
            Boxed<bool> ForceUpdate;
            std::string PlayFabId;
            std::list<StatisticUpdate> Statistics;

            UpdatePlayerStatisticsRequest() :
                PlayFabRequestCommon(),
                ForceUpdate(),
                PlayFabId(),
                Statistics()
            {}

            UpdatePlayerStatisticsRequest(const UpdatePlayerStatisticsRequest& src) :
                PlayFabRequestCommon(),
                ForceUpdate(src.ForceUpdate),
                PlayFabId(src.PlayFabId),
                Statistics(src.Statistics)
            {}

            ~UpdatePlayerStatisticsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("ForceUpdate")], ForceUpdate);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilO(input[U("Statistics")], Statistics);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ForceUpdate; ToJsonUtilP(ForceUpdate, each_ForceUpdate); output[U("ForceUpdate")] = each_ForceUpdate;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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
            std::string PlayFabId;

            UpdateUserDataRequest() :
                PlayFabRequestCommon(),
                Data(),
                KeysToRemove(),
                Permission(),
                PlayFabId()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabRequestCommon(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission),
                PlayFabId(src.PlayFabId)
            {}

            ~UpdateUserDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Data")], Data);
                FromJsonUtilS(input[U("KeysToRemove")], KeysToRemove);
                FromJsonUtilE(input[U("Permission")], Permission);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[U("KeysToRemove")] = each_KeysToRemove;
                web::json::value each_Permission; ToJsonUtilE(Permission, each_Permission); output[U("Permission")] = each_Permission;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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

        struct UpdateUserInternalDataRequest : public PlayFabRequestCommon
        {
            std::map<std::string, std::string> Data;
            std::list<std::string> KeysToRemove;
            std::string PlayFabId;

            UpdateUserInternalDataRequest() :
                PlayFabRequestCommon(),
                Data(),
                KeysToRemove(),
                PlayFabId()
            {}

            UpdateUserInternalDataRequest(const UpdateUserInternalDataRequest& src) :
                PlayFabRequestCommon(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                PlayFabId(src.PlayFabId)
            {}

            ~UpdateUserInternalDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Data")], Data);
                FromJsonUtilS(input[U("KeysToRemove")], KeysToRemove);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[U("KeysToRemove")] = each_KeysToRemove;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                return output;
            }
        };

        struct UpdateUserInventoryItemDataRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::map<std::string, std::string> Data;
            std::string ItemInstanceId;
            std::list<std::string> KeysToRemove;
            std::string PlayFabId;

            UpdateUserInventoryItemDataRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                Data(),
                ItemInstanceId(),
                KeysToRemove(),
                PlayFabId()
            {}

            UpdateUserInventoryItemDataRequest(const UpdateUserInventoryItemDataRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                ItemInstanceId(src.ItemInstanceId),
                KeysToRemove(src.KeysToRemove),
                PlayFabId(src.PlayFabId)
            {}

            ~UpdateUserInventoryItemDataRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("Data")], Data);
                FromJsonUtilS(input[U("ItemInstanceId")], ItemInstanceId);
                FromJsonUtilS(input[U("KeysToRemove")], KeysToRemove);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_Data; ToJsonUtilS(Data, each_Data); output[U("Data")] = each_Data;
                web::json::value each_ItemInstanceId; ToJsonUtilS(ItemInstanceId, each_ItemInstanceId); output[U("ItemInstanceId")] = each_ItemInstanceId;
                web::json::value each_KeysToRemove; ToJsonUtilS(KeysToRemove, each_KeysToRemove); output[U("KeysToRemove")] = each_KeysToRemove;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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

        struct WriteServerCharacterEventRequest : public PlayFabRequestCommon
        {
            web::json::value Body; // Not truly arbitrary. See documentation for restrictions on format
            std::string CharacterId;
            std::string EventName;
            std::string PlayFabId;
            Boxed<time_t> Timestamp;

            WriteServerCharacterEventRequest() :
                PlayFabRequestCommon(),
                Body(),
                CharacterId(),
                EventName(),
                PlayFabId(),
                Timestamp()
            {}

            WriteServerCharacterEventRequest(const WriteServerCharacterEventRequest& src) :
                PlayFabRequestCommon(),
                Body(src.Body),
                CharacterId(src.CharacterId),
                EventName(src.EventName),
                PlayFabId(src.PlayFabId),
                Timestamp(src.Timestamp)
            {}

            ~WriteServerCharacterEventRequest() { }

            void FromJson(web::json::value& input) override
            {
                Body = input[U("Body")];
                FromJsonUtilS(input[U("CharacterId")], CharacterId);
                FromJsonUtilS(input[U("EventName")], EventName);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("Body")] = Body;
                web::json::value each_CharacterId; ToJsonUtilS(CharacterId, each_CharacterId); output[U("CharacterId")] = each_CharacterId;
                web::json::value each_EventName; ToJsonUtilS(EventName, each_EventName); output[U("EventName")] = each_EventName;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
                return output;
            }
        };

        struct WriteServerPlayerEventRequest : public PlayFabRequestCommon
        {
            web::json::value Body; // Not truly arbitrary. See documentation for restrictions on format
            std::string EventName;
            std::string PlayFabId;
            Boxed<time_t> Timestamp;

            WriteServerPlayerEventRequest() :
                PlayFabRequestCommon(),
                Body(),
                EventName(),
                PlayFabId(),
                Timestamp()
            {}

            WriteServerPlayerEventRequest(const WriteServerPlayerEventRequest& src) :
                PlayFabRequestCommon(),
                Body(src.Body),
                EventName(src.EventName),
                PlayFabId(src.PlayFabId),
                Timestamp(src.Timestamp)
            {}

            ~WriteServerPlayerEventRequest() { }

            void FromJson(web::json::value& input) override
            {
                Body = input[U("Body")];
                FromJsonUtilS(input[U("EventName")], EventName);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("Body")] = Body;
                web::json::value each_EventName; ToJsonUtilS(EventName, each_EventName); output[U("EventName")] = each_EventName;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
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
