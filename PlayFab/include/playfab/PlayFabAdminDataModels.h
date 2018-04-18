#pragma once

#ifdef ENABLE_PLAYFABADMIN_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace AdminModels
    {
        // Admin Enums
        enum AuthTokenType
        {
            AuthTokenTypeEmail
        };

        inline void ToJsonEnum(const AuthTokenType input, web::json::value& output)
        {
            if (input == AuthTokenTypeEmail) output = web::json::value(U("Email"));
        }
        inline void FromJsonEnum(const web::json::value& input, AuthTokenType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Email")) output = AuthTokenTypeEmail;
        }

        enum Conditionals
        {
            ConditionalsAny,
            ConditionalsTrue,
            ConditionalsFalse
        };

        inline void ToJsonEnum(const Conditionals input, web::json::value& output)
        {
            if (input == ConditionalsAny) output = web::json::value(U("Any"));
            if (input == ConditionalsTrue) output = web::json::value(U("True"));
            if (input == ConditionalsFalse) output = web::json::value(U("False"));
        }
        inline void FromJsonEnum(const web::json::value& input, Conditionals& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Any")) output = ConditionalsAny;
            if (inputStr == U("True")) output = ConditionalsTrue;
            if (inputStr == U("False")) output = ConditionalsFalse;
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

        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        inline void ToJsonEnum(const EffectType input, web::json::value& output)
        {
            if (input == EffectTypeAllow) output = web::json::value(U("Allow"));
            if (input == EffectTypeDeny) output = web::json::value(U("Deny"));
        }
        inline void FromJsonEnum(const web::json::value& input, EffectType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Allow")) output = EffectTypeAllow;
            if (inputStr == U("Deny")) output = EffectTypeDeny;
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

        enum GameBuildStatus
        {
            GameBuildStatusAvailable,
            GameBuildStatusValidating,
            GameBuildStatusInvalidBuildPackage,
            GameBuildStatusProcessing,
            GameBuildStatusFailedToProcess
        };

        inline void ToJsonEnum(const GameBuildStatus input, web::json::value& output)
        {
            if (input == GameBuildStatusAvailable) output = web::json::value(U("Available"));
            if (input == GameBuildStatusValidating) output = web::json::value(U("Validating"));
            if (input == GameBuildStatusInvalidBuildPackage) output = web::json::value(U("InvalidBuildPackage"));
            if (input == GameBuildStatusProcessing) output = web::json::value(U("Processing"));
            if (input == GameBuildStatusFailedToProcess) output = web::json::value(U("FailedToProcess"));
        }
        inline void FromJsonEnum(const web::json::value& input, GameBuildStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Available")) output = GameBuildStatusAvailable;
            if (inputStr == U("Validating")) output = GameBuildStatusValidating;
            if (inputStr == U("InvalidBuildPackage")) output = GameBuildStatusInvalidBuildPackage;
            if (inputStr == U("Processing")) output = GameBuildStatusProcessing;
            if (inputStr == U("FailedToProcess")) output = GameBuildStatusFailedToProcess;
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

        enum PushSetupPlatform
        {
            PushSetupPlatformGCM,
            PushSetupPlatformAPNS,
            PushSetupPlatformAPNS_SANDBOX
        };

        inline void ToJsonEnum(const PushSetupPlatform input, web::json::value& output)
        {
            if (input == PushSetupPlatformGCM) output = web::json::value(U("GCM"));
            if (input == PushSetupPlatformAPNS) output = web::json::value(U("APNS"));
            if (input == PushSetupPlatformAPNS_SANDBOX) output = web::json::value(U("APNS_SANDBOX"));
        }
        inline void FromJsonEnum(const web::json::value& input, PushSetupPlatform& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("GCM")) output = PushSetupPlatformGCM;
            if (inputStr == U("APNS")) output = PushSetupPlatformAPNS;
            if (inputStr == U("APNS_SANDBOX")) output = PushSetupPlatformAPNS_SANDBOX;
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

        enum ResolutionOutcome
        {
            ResolutionOutcomeRevoke,
            ResolutionOutcomeReinstate,
            ResolutionOutcomeManual
        };

        inline void ToJsonEnum(const ResolutionOutcome input, web::json::value& output)
        {
            if (input == ResolutionOutcomeRevoke) output = web::json::value(U("Revoke"));
            if (input == ResolutionOutcomeReinstate) output = web::json::value(U("Reinstate"));
            if (input == ResolutionOutcomeManual) output = web::json::value(U("Manual"));
        }
        inline void FromJsonEnum(const web::json::value& input, ResolutionOutcome& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Revoke")) output = ResolutionOutcomeRevoke;
            if (inputStr == U("Reinstate")) output = ResolutionOutcomeReinstate;
            if (inputStr == U("Manual")) output = ResolutionOutcomeManual;
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

        enum ScheduledTaskType
        {
            ScheduledTaskTypeCloudScript,
            ScheduledTaskTypeActionsOnPlayerSegment
        };

        inline void ToJsonEnum(const ScheduledTaskType input, web::json::value& output)
        {
            if (input == ScheduledTaskTypeCloudScript) output = web::json::value(U("CloudScript"));
            if (input == ScheduledTaskTypeActionsOnPlayerSegment) output = web::json::value(U("ActionsOnPlayerSegment"));
        }
        inline void FromJsonEnum(const web::json::value& input, ScheduledTaskType& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("CloudScript")) output = ScheduledTaskTypeCloudScript;
            if (inputStr == U("ActionsOnPlayerSegment")) output = ScheduledTaskTypeActionsOnPlayerSegment;
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

        enum StatisticAggregationMethod
        {
            StatisticAggregationMethodLast,
            StatisticAggregationMethodMin,
            StatisticAggregationMethodMax,
            StatisticAggregationMethodSum
        };

        inline void ToJsonEnum(const StatisticAggregationMethod input, web::json::value& output)
        {
            if (input == StatisticAggregationMethodLast) output = web::json::value(U("Last"));
            if (input == StatisticAggregationMethodMin) output = web::json::value(U("Min"));
            if (input == StatisticAggregationMethodMax) output = web::json::value(U("Max"));
            if (input == StatisticAggregationMethodSum) output = web::json::value(U("Sum"));
        }
        inline void FromJsonEnum(const web::json::value& input, StatisticAggregationMethod& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Last")) output = StatisticAggregationMethodLast;
            if (inputStr == U("Min")) output = StatisticAggregationMethodMin;
            if (inputStr == U("Max")) output = StatisticAggregationMethodMax;
            if (inputStr == U("Sum")) output = StatisticAggregationMethodSum;
        }

        enum StatisticResetIntervalOption
        {
            StatisticResetIntervalOptionNever,
            StatisticResetIntervalOptionHour,
            StatisticResetIntervalOptionDay,
            StatisticResetIntervalOptionWeek,
            StatisticResetIntervalOptionMonth
        };

        inline void ToJsonEnum(const StatisticResetIntervalOption input, web::json::value& output)
        {
            if (input == StatisticResetIntervalOptionNever) output = web::json::value(U("Never"));
            if (input == StatisticResetIntervalOptionHour) output = web::json::value(U("Hour"));
            if (input == StatisticResetIntervalOptionDay) output = web::json::value(U("Day"));
            if (input == StatisticResetIntervalOptionWeek) output = web::json::value(U("Week"));
            if (input == StatisticResetIntervalOptionMonth) output = web::json::value(U("Month"));
        }
        inline void FromJsonEnum(const web::json::value& input, StatisticResetIntervalOption& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Never")) output = StatisticResetIntervalOptionNever;
            if (inputStr == U("Hour")) output = StatisticResetIntervalOptionHour;
            if (inputStr == U("Day")) output = StatisticResetIntervalOptionDay;
            if (inputStr == U("Week")) output = StatisticResetIntervalOptionWeek;
            if (inputStr == U("Month")) output = StatisticResetIntervalOptionMonth;
        }

        enum StatisticVersionArchivalStatus
        {
            StatisticVersionArchivalStatusNotScheduled,
            StatisticVersionArchivalStatusScheduled,
            StatisticVersionArchivalStatusQueued,
            StatisticVersionArchivalStatusInProgress,
            StatisticVersionArchivalStatusComplete
        };

        inline void ToJsonEnum(const StatisticVersionArchivalStatus input, web::json::value& output)
        {
            if (input == StatisticVersionArchivalStatusNotScheduled) output = web::json::value(U("NotScheduled"));
            if (input == StatisticVersionArchivalStatusScheduled) output = web::json::value(U("Scheduled"));
            if (input == StatisticVersionArchivalStatusQueued) output = web::json::value(U("Queued"));
            if (input == StatisticVersionArchivalStatusInProgress) output = web::json::value(U("InProgress"));
            if (input == StatisticVersionArchivalStatusComplete) output = web::json::value(U("Complete"));
        }
        inline void FromJsonEnum(const web::json::value& input, StatisticVersionArchivalStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("NotScheduled")) output = StatisticVersionArchivalStatusNotScheduled;
            if (inputStr == U("Scheduled")) output = StatisticVersionArchivalStatusScheduled;
            if (inputStr == U("Queued")) output = StatisticVersionArchivalStatusQueued;
            if (inputStr == U("InProgress")) output = StatisticVersionArchivalStatusInProgress;
            if (inputStr == U("Complete")) output = StatisticVersionArchivalStatusComplete;
        }

        enum StatisticVersionStatus
        {
            StatisticVersionStatusActive,
            StatisticVersionStatusSnapshotPending,
            StatisticVersionStatusSnapshot,
            StatisticVersionStatusArchivalPending,
            StatisticVersionStatusArchived
        };

        inline void ToJsonEnum(const StatisticVersionStatus input, web::json::value& output)
        {
            if (input == StatisticVersionStatusActive) output = web::json::value(U("Active"));
            if (input == StatisticVersionStatusSnapshotPending) output = web::json::value(U("SnapshotPending"));
            if (input == StatisticVersionStatusSnapshot) output = web::json::value(U("Snapshot"));
            if (input == StatisticVersionStatusArchivalPending) output = web::json::value(U("ArchivalPending"));
            if (input == StatisticVersionStatusArchived) output = web::json::value(U("Archived"));
        }
        inline void FromJsonEnum(const web::json::value& input, StatisticVersionStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Active")) output = StatisticVersionStatusActive;
            if (inputStr == U("SnapshotPending")) output = StatisticVersionStatusSnapshotPending;
            if (inputStr == U("Snapshot")) output = StatisticVersionStatusSnapshot;
            if (inputStr == U("ArchivalPending")) output = StatisticVersionStatusArchivalPending;
            if (inputStr == U("Archived")) output = StatisticVersionStatusArchived;
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

        enum TaskInstanceStatus
        {
            TaskInstanceStatusSucceeded,
            TaskInstanceStatusStarting,
            TaskInstanceStatusInProgress,
            TaskInstanceStatusFailed,
            TaskInstanceStatusAborted,
            TaskInstanceStatusPending
        };

        inline void ToJsonEnum(const TaskInstanceStatus input, web::json::value& output)
        {
            if (input == TaskInstanceStatusSucceeded) output = web::json::value(U("Succeeded"));
            if (input == TaskInstanceStatusStarting) output = web::json::value(U("Starting"));
            if (input == TaskInstanceStatusInProgress) output = web::json::value(U("InProgress"));
            if (input == TaskInstanceStatusFailed) output = web::json::value(U("Failed"));
            if (input == TaskInstanceStatusAborted) output = web::json::value(U("Aborted"));
            if (input == TaskInstanceStatusPending) output = web::json::value(U("Pending"));
        }
        inline void FromJsonEnum(const web::json::value& input, TaskInstanceStatus& output)
        {
            if (!input.is_string()) return;
            const utility::string_t& inputStr = input.as_string();
            if (inputStr == U("Succeeded")) output = TaskInstanceStatusSucceeded;
            if (inputStr == U("Starting")) output = TaskInstanceStatusStarting;
            if (inputStr == U("InProgress")) output = TaskInstanceStatusInProgress;
            if (inputStr == U("Failed")) output = TaskInstanceStatusFailed;
            if (inputStr == U("Aborted")) output = TaskInstanceStatusAborted;
            if (inputStr == U("Pending")) output = TaskInstanceStatusPending;
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

        // Admin Classes
        struct AbortTaskInstanceRequest : public PlayFabRequestCommon
        {
            std::string TaskInstanceId;

            AbortTaskInstanceRequest() :
                PlayFabRequestCommon(),
                TaskInstanceId()
            {}

            AbortTaskInstanceRequest(const AbortTaskInstanceRequest& src) :
                PlayFabRequestCommon(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            ~AbortTaskInstanceRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("TaskInstanceId")], TaskInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[U("TaskInstanceId")] = each_TaskInstanceId;
                return output;
            }
        };

        struct ActionsOnPlayersInSegmentTaskParameter : public PlayFabBaseModel
        {
            std::string ActionId;
            std::string SegmentId;

            ActionsOnPlayersInSegmentTaskParameter() :
                PlayFabBaseModel(),
                ActionId(),
                SegmentId()
            {}

            ActionsOnPlayersInSegmentTaskParameter(const ActionsOnPlayersInSegmentTaskParameter& src) :
                PlayFabBaseModel(),
                ActionId(src.ActionId),
                SegmentId(src.SegmentId)
            {}

            ~ActionsOnPlayersInSegmentTaskParameter() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ActionId")], ActionId);
                FromJsonUtilS(input[U("SegmentId")], SegmentId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActionId; ToJsonUtilS(ActionId, each_ActionId); output[U("ActionId")] = each_ActionId;
                web::json::value each_SegmentId; ToJsonUtilS(SegmentId, each_SegmentId); output[U("SegmentId")] = each_SegmentId;
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

        struct ActionsOnPlayersInSegmentTaskSummary : public PlayFabBaseModel
        {
            Boxed<time_t> CompletedAt;
            std::string ErrorMessage;
            Boxed<bool> ErrorWasFatal;
            Boxed<double> EstimatedSecondsRemaining;
            Boxed<double> PercentComplete;
            std::string ScheduledByUserId;
            time_t StartedAt;
            Boxed<TaskInstanceStatus> Status;
            Boxed<NameIdentifier> TaskIdentifier;
            std::string TaskInstanceId;
            Boxed<Int32> TotalPlayersInSegment;
            Boxed<Int32> TotalPlayersProcessed;

            ActionsOnPlayersInSegmentTaskSummary() :
                PlayFabBaseModel(),
                CompletedAt(),
                ErrorMessage(),
                ErrorWasFatal(),
                EstimatedSecondsRemaining(),
                PercentComplete(),
                ScheduledByUserId(),
                StartedAt(),
                Status(),
                TaskIdentifier(),
                TaskInstanceId(),
                TotalPlayersInSegment(),
                TotalPlayersProcessed()
            {}

            ActionsOnPlayersInSegmentTaskSummary(const ActionsOnPlayersInSegmentTaskSummary& src) :
                PlayFabBaseModel(),
                CompletedAt(src.CompletedAt),
                ErrorMessage(src.ErrorMessage),
                ErrorWasFatal(src.ErrorWasFatal),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                PercentComplete(src.PercentComplete),
                ScheduledByUserId(src.ScheduledByUserId),
                StartedAt(src.StartedAt),
                Status(src.Status),
                TaskIdentifier(src.TaskIdentifier),
                TaskInstanceId(src.TaskInstanceId),
                TotalPlayersInSegment(src.TotalPlayersInSegment),
                TotalPlayersProcessed(src.TotalPlayersProcessed)
            {}

            ~ActionsOnPlayersInSegmentTaskSummary() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("CompletedAt")], CompletedAt);
                FromJsonUtilS(input[U("ErrorMessage")], ErrorMessage);
                FromJsonUtilP(input[U("ErrorWasFatal")], ErrorWasFatal);
                FromJsonUtilP(input[U("EstimatedSecondsRemaining")], EstimatedSecondsRemaining);
                FromJsonUtilP(input[U("PercentComplete")], PercentComplete);
                FromJsonUtilS(input[U("ScheduledByUserId")], ScheduledByUserId);
                FromJsonUtilT(input[U("StartedAt")], StartedAt);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilO(input[U("TaskIdentifier")], TaskIdentifier);
                FromJsonUtilS(input[U("TaskInstanceId")], TaskInstanceId);
                FromJsonUtilP(input[U("TotalPlayersInSegment")], TotalPlayersInSegment);
                FromJsonUtilP(input[U("TotalPlayersProcessed")], TotalPlayersProcessed);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CompletedAt; ToJsonUtilT(CompletedAt, each_CompletedAt); output[U("CompletedAt")] = each_CompletedAt;
                web::json::value each_ErrorMessage; ToJsonUtilS(ErrorMessage, each_ErrorMessage); output[U("ErrorMessage")] = each_ErrorMessage;
                web::json::value each_ErrorWasFatal; ToJsonUtilP(ErrorWasFatal, each_ErrorWasFatal); output[U("ErrorWasFatal")] = each_ErrorWasFatal;
                web::json::value each_EstimatedSecondsRemaining; ToJsonUtilP(EstimatedSecondsRemaining, each_EstimatedSecondsRemaining); output[U("EstimatedSecondsRemaining")] = each_EstimatedSecondsRemaining;
                web::json::value each_PercentComplete; ToJsonUtilP(PercentComplete, each_PercentComplete); output[U("PercentComplete")] = each_PercentComplete;
                web::json::value each_ScheduledByUserId; ToJsonUtilS(ScheduledByUserId, each_ScheduledByUserId); output[U("ScheduledByUserId")] = each_ScheduledByUserId;
                web::json::value each_StartedAt; ToJsonUtilT(StartedAt, each_StartedAt); output[U("StartedAt")] = each_StartedAt;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
                web::json::value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output[U("TaskIdentifier")] = each_TaskIdentifier;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[U("TaskInstanceId")] = each_TaskInstanceId;
                web::json::value each_TotalPlayersInSegment; ToJsonUtilP(TotalPlayersInSegment, each_TotalPlayersInSegment); output[U("TotalPlayersInSegment")] = each_TotalPlayersInSegment;
                web::json::value each_TotalPlayersProcessed; ToJsonUtilP(TotalPlayersProcessed, each_TotalPlayersProcessed); output[U("TotalPlayersProcessed")] = each_TotalPlayersProcessed;
                return output;
            }
        };

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

        struct AddNewsRequest : public PlayFabRequestCommon
        {
            std::string Body;
            Boxed<time_t> Timestamp;
            std::string Title;

            AddNewsRequest() :
                PlayFabRequestCommon(),
                Body(),
                Timestamp(),
                Title()
            {}

            AddNewsRequest(const AddNewsRequest& src) :
                PlayFabRequestCommon(),
                Body(src.Body),
                Timestamp(src.Timestamp),
                Title(src.Title)
            {}

            ~AddNewsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Body")], Body);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
                FromJsonUtilS(input[U("Title")], Title);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Body; ToJsonUtilS(Body, each_Body); output[U("Body")] = each_Body;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
                web::json::value each_Title; ToJsonUtilS(Title, each_Title); output[U("Title")] = each_Title;
                return output;
            }
        };

        struct AddNewsResult : public PlayFabResultCommon
        {
            std::string NewsId;

            AddNewsResult() :
                PlayFabResultCommon(),
                NewsId()
            {}

            AddNewsResult(const AddNewsResult& src) :
                PlayFabResultCommon(),
                NewsId(src.NewsId)
            {}

            ~AddNewsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("NewsId")], NewsId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_NewsId; ToJsonUtilS(NewsId, each_NewsId); output[U("NewsId")] = each_NewsId;
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

        struct AddServerBuildRequest : public PlayFabRequestCommon
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;

            AddServerBuildRequest() :
                PlayFabRequestCommon(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                ExecutablePath(),
                MaxGamesPerHost(),
                MinFreeGameSlots()
            {}

            AddServerBuildRequest(const AddServerBuildRequest& src) :
                PlayFabRequestCommon(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots)
            {}

            ~AddServerBuildRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("ActiveRegions")], ActiveRegions);
                FromJsonUtilS(input[U("BuildId")], BuildId);
                FromJsonUtilS(input[U("CommandLineTemplate")], CommandLineTemplate);
                FromJsonUtilS(input[U("Comment")], Comment);
                FromJsonUtilS(input[U("ExecutablePath")], ExecutablePath);
                FromJsonUtilP(input[U("MaxGamesPerHost")], MaxGamesPerHost);
                FromJsonUtilP(input[U("MinFreeGameSlots")], MinFreeGameSlots);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output[U("ActiveRegions")] = each_ActiveRegions;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[U("BuildId")] = each_BuildId;
                web::json::value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output[U("CommandLineTemplate")] = each_CommandLineTemplate;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[U("Comment")] = each_Comment;
                web::json::value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output[U("ExecutablePath")] = each_ExecutablePath;
                web::json::value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output[U("MaxGamesPerHost")] = each_MaxGamesPerHost;
                web::json::value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output[U("MinFreeGameSlots")] = each_MinFreeGameSlots;
                return output;
            }
        };

        struct AddServerBuildResult : public PlayFabResultCommon
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<GameBuildStatus> Status;
            time_t Timestamp;
            std::string TitleId;

            AddServerBuildResult() :
                PlayFabResultCommon(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                ExecutablePath(),
                MaxGamesPerHost(),
                MinFreeGameSlots(),
                Status(),
                Timestamp(),
                TitleId()
            {}

            AddServerBuildResult(const AddServerBuildResult& src) :
                PlayFabResultCommon(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Status(src.Status),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId)
            {}

            ~AddServerBuildResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("ActiveRegions")], ActiveRegions);
                FromJsonUtilS(input[U("BuildId")], BuildId);
                FromJsonUtilS(input[U("CommandLineTemplate")], CommandLineTemplate);
                FromJsonUtilS(input[U("Comment")], Comment);
                FromJsonUtilS(input[U("ExecutablePath")], ExecutablePath);
                FromJsonUtilP(input[U("MaxGamesPerHost")], MaxGamesPerHost);
                FromJsonUtilP(input[U("MinFreeGameSlots")], MinFreeGameSlots);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output[U("ActiveRegions")] = each_ActiveRegions;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[U("BuildId")] = each_BuildId;
                web::json::value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output[U("CommandLineTemplate")] = each_CommandLineTemplate;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[U("Comment")] = each_Comment;
                web::json::value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output[U("ExecutablePath")] = each_ExecutablePath;
                web::json::value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output[U("MaxGamesPerHost")] = each_MaxGamesPerHost;
                web::json::value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output[U("MinFreeGameSlots")] = each_MinFreeGameSlots;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
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

        struct VirtualCurrencyData : public PlayFabBaseModel
        {
            std::string CurrencyCode;
            std::string DisplayName;
            Boxed<Int32> InitialDeposit;
            Boxed<Int32> RechargeMax;
            Boxed<Int32> RechargeRate;

            VirtualCurrencyData() :
                PlayFabBaseModel(),
                CurrencyCode(),
                DisplayName(),
                InitialDeposit(),
                RechargeMax(),
                RechargeRate()
            {}

            VirtualCurrencyData(const VirtualCurrencyData& src) :
                PlayFabBaseModel(),
                CurrencyCode(src.CurrencyCode),
                DisplayName(src.DisplayName),
                InitialDeposit(src.InitialDeposit),
                RechargeMax(src.RechargeMax),
                RechargeRate(src.RechargeRate)
            {}

            ~VirtualCurrencyData() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CurrencyCode")], CurrencyCode);
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilP(input[U("InitialDeposit")], InitialDeposit);
                FromJsonUtilP(input[U("RechargeMax")], RechargeMax);
                FromJsonUtilP(input[U("RechargeRate")], RechargeRate);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CurrencyCode; ToJsonUtilS(CurrencyCode, each_CurrencyCode); output[U("CurrencyCode")] = each_CurrencyCode;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_InitialDeposit; ToJsonUtilP(InitialDeposit, each_InitialDeposit); output[U("InitialDeposit")] = each_InitialDeposit;
                web::json::value each_RechargeMax; ToJsonUtilP(RechargeMax, each_RechargeMax); output[U("RechargeMax")] = each_RechargeMax;
                web::json::value each_RechargeRate; ToJsonUtilP(RechargeRate, each_RechargeRate); output[U("RechargeRate")] = each_RechargeRate;
                return output;
            }
        };

        struct AddVirtualCurrencyTypesRequest : public PlayFabRequestCommon
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            AddVirtualCurrencyTypesRequest() :
                PlayFabRequestCommon(),
                VirtualCurrencies()
            {}

            AddVirtualCurrencyTypesRequest(const AddVirtualCurrencyTypesRequest& src) :
                PlayFabRequestCommon(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            ~AddVirtualCurrencyTypesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("VirtualCurrencies")], VirtualCurrencies);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_VirtualCurrencies; ToJsonUtilO(VirtualCurrencies, each_VirtualCurrencies); output[U("VirtualCurrencies")] = each_VirtualCurrencies;
                return output;
            }
        };

        struct ApiCondition : public PlayFabBaseModel
        {
            Boxed<Conditionals> HasSignatureOrEncryption;

            ApiCondition() :
                PlayFabBaseModel(),
                HasSignatureOrEncryption()
            {}

            ApiCondition(const ApiCondition& src) :
                PlayFabBaseModel(),
                HasSignatureOrEncryption(src.HasSignatureOrEncryption)
            {}

            ~ApiCondition() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("HasSignatureOrEncryption")], HasSignatureOrEncryption);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_HasSignatureOrEncryption; ToJsonUtilE(HasSignatureOrEncryption, each_HasSignatureOrEncryption); output[U("HasSignatureOrEncryption")] = each_HasSignatureOrEncryption;
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

        struct BlankResult : public PlayFabResultCommon
        {

            BlankResult() :
                PlayFabResultCommon()
            {}

            BlankResult(const BlankResult& src) :
                PlayFabResultCommon()
            {}

            ~BlankResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
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

        struct CheckLimitedEditionItemAvailabilityRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string ItemId;

            CheckLimitedEditionItemAvailabilityRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                ItemId()
            {}

            CheckLimitedEditionItemAvailabilityRequest(const CheckLimitedEditionItemAvailabilityRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                ItemId(src.ItemId)
            {}

            ~CheckLimitedEditionItemAvailabilityRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("ItemId")], ItemId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                return output;
            }
        };

        struct CheckLimitedEditionItemAvailabilityResult : public PlayFabResultCommon
        {
            Int32 Amount;

            CheckLimitedEditionItemAvailabilityResult() :
                PlayFabResultCommon(),
                Amount()
            {}

            CheckLimitedEditionItemAvailabilityResult(const CheckLimitedEditionItemAvailabilityResult& src) :
                PlayFabResultCommon(),
                Amount(src.Amount)
            {}

            ~CheckLimitedEditionItemAvailabilityResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Amount")], Amount);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[U("Amount")] = each_Amount;
                return output;
            }
        };

        struct CloudScriptFile : public PlayFabBaseModel
        {
            std::string FileContents;
            std::string Filename;

            CloudScriptFile() :
                PlayFabBaseModel(),
                FileContents(),
                Filename()
            {}

            CloudScriptFile(const CloudScriptFile& src) :
                PlayFabBaseModel(),
                FileContents(src.FileContents),
                Filename(src.Filename)
            {}

            ~CloudScriptFile() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FileContents")], FileContents);
                FromJsonUtilS(input[U("Filename")], Filename);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FileContents; ToJsonUtilS(FileContents, each_FileContents); output[U("FileContents")] = each_FileContents;
                web::json::value each_Filename; ToJsonUtilS(Filename, each_Filename); output[U("Filename")] = each_Filename;
                return output;
            }
        };

        struct CloudScriptTaskParameter : public PlayFabBaseModel
        {
            web::json::value Argument;
            std::string FunctionName;

            CloudScriptTaskParameter() :
                PlayFabBaseModel(),
                Argument(),
                FunctionName()
            {}

            CloudScriptTaskParameter(const CloudScriptTaskParameter& src) :
                PlayFabBaseModel(),
                Argument(src.Argument),
                FunctionName(src.FunctionName)
            {}

            ~CloudScriptTaskParameter() { }

            void FromJson(web::json::value& input) override
            {
                Argument = input[U("Argument")];
                FromJsonUtilS(input[U("FunctionName")], FunctionName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                output[U("Argument")] = Argument;
                web::json::value each_FunctionName; ToJsonUtilS(FunctionName, each_FunctionName); output[U("FunctionName")] = each_FunctionName;
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

        struct CloudScriptTaskSummary : public PlayFabBaseModel
        {
            Boxed<time_t> CompletedAt;
            Boxed<double> EstimatedSecondsRemaining;
            Boxed<double> PercentComplete;
            Boxed<ExecuteCloudScriptResult> Result;
            std::string ScheduledByUserId;
            time_t StartedAt;
            Boxed<TaskInstanceStatus> Status;
            Boxed<NameIdentifier> TaskIdentifier;
            std::string TaskInstanceId;

            CloudScriptTaskSummary() :
                PlayFabBaseModel(),
                CompletedAt(),
                EstimatedSecondsRemaining(),
                PercentComplete(),
                Result(),
                ScheduledByUserId(),
                StartedAt(),
                Status(),
                TaskIdentifier(),
                TaskInstanceId()
            {}

            CloudScriptTaskSummary(const CloudScriptTaskSummary& src) :
                PlayFabBaseModel(),
                CompletedAt(src.CompletedAt),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                PercentComplete(src.PercentComplete),
                Result(src.Result),
                ScheduledByUserId(src.ScheduledByUserId),
                StartedAt(src.StartedAt),
                Status(src.Status),
                TaskIdentifier(src.TaskIdentifier),
                TaskInstanceId(src.TaskInstanceId)
            {}

            ~CloudScriptTaskSummary() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("CompletedAt")], CompletedAt);
                FromJsonUtilP(input[U("EstimatedSecondsRemaining")], EstimatedSecondsRemaining);
                FromJsonUtilP(input[U("PercentComplete")], PercentComplete);
                FromJsonUtilO(input[U("Result")], Result);
                FromJsonUtilS(input[U("ScheduledByUserId")], ScheduledByUserId);
                FromJsonUtilT(input[U("StartedAt")], StartedAt);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilO(input[U("TaskIdentifier")], TaskIdentifier);
                FromJsonUtilS(input[U("TaskInstanceId")], TaskInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CompletedAt; ToJsonUtilT(CompletedAt, each_CompletedAt); output[U("CompletedAt")] = each_CompletedAt;
                web::json::value each_EstimatedSecondsRemaining; ToJsonUtilP(EstimatedSecondsRemaining, each_EstimatedSecondsRemaining); output[U("EstimatedSecondsRemaining")] = each_EstimatedSecondsRemaining;
                web::json::value each_PercentComplete; ToJsonUtilP(PercentComplete, each_PercentComplete); output[U("PercentComplete")] = each_PercentComplete;
                web::json::value each_Result; ToJsonUtilO(Result, each_Result); output[U("Result")] = each_Result;
                web::json::value each_ScheduledByUserId; ToJsonUtilS(ScheduledByUserId, each_ScheduledByUserId); output[U("ScheduledByUserId")] = each_ScheduledByUserId;
                web::json::value each_StartedAt; ToJsonUtilT(StartedAt, each_StartedAt); output[U("StartedAt")] = each_StartedAt;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
                web::json::value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output[U("TaskIdentifier")] = each_TaskIdentifier;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[U("TaskInstanceId")] = each_TaskInstanceId;
                return output;
            }
        };

        struct CloudScriptVersionStatus : public PlayFabBaseModel
        {
            Int32 LatestRevision;
            Int32 PublishedRevision;
            Int32 Version;

            CloudScriptVersionStatus() :
                PlayFabBaseModel(),
                LatestRevision(),
                PublishedRevision(),
                Version()
            {}

            CloudScriptVersionStatus(const CloudScriptVersionStatus& src) :
                PlayFabBaseModel(),
                LatestRevision(src.LatestRevision),
                PublishedRevision(src.PublishedRevision),
                Version(src.Version)
            {}

            ~CloudScriptVersionStatus() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("LatestRevision")], LatestRevision);
                FromJsonUtilP(input[U("PublishedRevision")], PublishedRevision);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_LatestRevision; ToJsonUtilP(LatestRevision, each_LatestRevision); output[U("LatestRevision")] = each_LatestRevision;
                web::json::value each_PublishedRevision; ToJsonUtilP(PublishedRevision, each_PublishedRevision); output[U("PublishedRevision")] = each_PublishedRevision;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
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

        struct ContentInfo : public PlayFabBaseModel
        {
            std::string Key;
            time_t LastModified;
            Uint32 Size;

            ContentInfo() :
                PlayFabBaseModel(),
                Key(),
                LastModified(),
                Size()
            {}

            ContentInfo(const ContentInfo& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                LastModified(src.LastModified),
                Size(src.Size)
            {}

            ~ContentInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Key")], Key);
                FromJsonUtilT(input[U("LastModified")], LastModified);
                FromJsonUtilP(input[U("Size")], Size);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[U("Key")] = each_Key;
                web::json::value each_LastModified; ToJsonUtilT(LastModified, each_LastModified); output[U("LastModified")] = each_LastModified;
                web::json::value each_Size; ToJsonUtilP(Size, each_Size); output[U("Size")] = each_Size;
                return output;
            }
        };

        struct CreateActionsOnPlayerSegmentTaskRequest : public PlayFabRequestCommon
        {
            std::string Description;
            bool IsActive;
            std::string Name;
            ActionsOnPlayersInSegmentTaskParameter Parameter;
            std::string Schedule;

            CreateActionsOnPlayerSegmentTaskRequest() :
                PlayFabRequestCommon(),
                Description(),
                IsActive(),
                Name(),
                Parameter(),
                Schedule()
            {}

            CreateActionsOnPlayerSegmentTaskRequest(const CreateActionsOnPlayerSegmentTaskRequest& src) :
                PlayFabRequestCommon(),
                Description(src.Description),
                IsActive(src.IsActive),
                Name(src.Name),
                Parameter(src.Parameter),
                Schedule(src.Schedule)
            {}

            ~CreateActionsOnPlayerSegmentTaskRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Description")], Description);
                FromJsonUtilP(input[U("IsActive")], IsActive);
                FromJsonUtilS(input[U("Name")], Name);
                FromJsonUtilO(input[U("Parameter")], Parameter);
                FromJsonUtilS(input[U("Schedule")], Schedule);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[U("Description")] = each_Description;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[U("IsActive")] = each_IsActive;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                web::json::value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output[U("Parameter")] = each_Parameter;
                web::json::value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output[U("Schedule")] = each_Schedule;
                return output;
            }
        };

        struct CreateCloudScriptTaskRequest : public PlayFabRequestCommon
        {
            std::string Description;
            bool IsActive;
            std::string Name;
            CloudScriptTaskParameter Parameter;
            std::string Schedule;

            CreateCloudScriptTaskRequest() :
                PlayFabRequestCommon(),
                Description(),
                IsActive(),
                Name(),
                Parameter(),
                Schedule()
            {}

            CreateCloudScriptTaskRequest(const CreateCloudScriptTaskRequest& src) :
                PlayFabRequestCommon(),
                Description(src.Description),
                IsActive(src.IsActive),
                Name(src.Name),
                Parameter(src.Parameter),
                Schedule(src.Schedule)
            {}

            ~CreateCloudScriptTaskRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Description")], Description);
                FromJsonUtilP(input[U("IsActive")], IsActive);
                FromJsonUtilS(input[U("Name")], Name);
                FromJsonUtilO(input[U("Parameter")], Parameter);
                FromJsonUtilS(input[U("Schedule")], Schedule);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[U("Description")] = each_Description;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[U("IsActive")] = each_IsActive;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                web::json::value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output[U("Parameter")] = each_Parameter;
                web::json::value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output[U("Schedule")] = each_Schedule;
                return output;
            }
        };

        struct CreatePlayerSharedSecretRequest : public PlayFabRequestCommon
        {
            std::string FriendlyName;

            CreatePlayerSharedSecretRequest() :
                PlayFabRequestCommon(),
                FriendlyName()
            {}

            CreatePlayerSharedSecretRequest(const CreatePlayerSharedSecretRequest& src) :
                PlayFabRequestCommon(),
                FriendlyName(src.FriendlyName)
            {}

            ~CreatePlayerSharedSecretRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("FriendlyName")], FriendlyName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_FriendlyName; ToJsonUtilS(FriendlyName, each_FriendlyName); output[U("FriendlyName")] = each_FriendlyName;
                return output;
            }
        };

        struct CreatePlayerSharedSecretResult : public PlayFabResultCommon
        {
            std::string SecretKey;

            CreatePlayerSharedSecretResult() :
                PlayFabResultCommon(),
                SecretKey()
            {}

            CreatePlayerSharedSecretResult(const CreatePlayerSharedSecretResult& src) :
                PlayFabResultCommon(),
                SecretKey(src.SecretKey)
            {}

            ~CreatePlayerSharedSecretResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("SecretKey")], SecretKey);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output[U("SecretKey")] = each_SecretKey;
                return output;
            }
        };

        struct CreatePlayerStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            CreatePlayerStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                AggregationMethod(),
                StatisticName(),
                VersionChangeInterval()
            {}

            CreatePlayerStatisticDefinitionRequest(const CreatePlayerStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                AggregationMethod(src.AggregationMethod),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            ~CreatePlayerStatisticDefinitionRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("AggregationMethod")], AggregationMethod);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilE(input[U("VersionChangeInterval")], VersionChangeInterval);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output[U("AggregationMethod")] = each_AggregationMethod;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_VersionChangeInterval; ToJsonUtilE(VersionChangeInterval, each_VersionChangeInterval); output[U("VersionChangeInterval")] = each_VersionChangeInterval;
                return output;
            }
        };

        struct PlayerStatisticDefinition : public PlayFabBaseModel
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            Uint32 CurrentVersion;
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            PlayerStatisticDefinition() :
                PlayFabBaseModel(),
                AggregationMethod(),
                CurrentVersion(),
                StatisticName(),
                VersionChangeInterval()
            {}

            PlayerStatisticDefinition(const PlayerStatisticDefinition& src) :
                PlayFabBaseModel(),
                AggregationMethod(src.AggregationMethod),
                CurrentVersion(src.CurrentVersion),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            ~PlayerStatisticDefinition() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("AggregationMethod")], AggregationMethod);
                FromJsonUtilP(input[U("CurrentVersion")], CurrentVersion);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilE(input[U("VersionChangeInterval")], VersionChangeInterval);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output[U("AggregationMethod")] = each_AggregationMethod;
                web::json::value each_CurrentVersion; ToJsonUtilP(CurrentVersion, each_CurrentVersion); output[U("CurrentVersion")] = each_CurrentVersion;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_VersionChangeInterval; ToJsonUtilE(VersionChangeInterval, each_VersionChangeInterval); output[U("VersionChangeInterval")] = each_VersionChangeInterval;
                return output;
            }
        };

        struct CreatePlayerStatisticDefinitionResult : public PlayFabResultCommon
        {
            Boxed<PlayerStatisticDefinition> Statistic;

            CreatePlayerStatisticDefinitionResult() :
                PlayFabResultCommon(),
                Statistic()
            {}

            CreatePlayerStatisticDefinitionResult(const CreatePlayerStatisticDefinitionResult& src) :
                PlayFabResultCommon(),
                Statistic(src.Statistic)
            {}

            ~CreatePlayerStatisticDefinitionResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Statistic")], Statistic);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Statistic; ToJsonUtilO(Statistic, each_Statistic); output[U("Statistic")] = each_Statistic;
                return output;
            }
        };

        struct CreateTaskResult : public PlayFabResultCommon
        {
            std::string TaskId;

            CreateTaskResult() :
                PlayFabResultCommon(),
                TaskId()
            {}

            CreateTaskResult(const CreateTaskResult& src) :
                PlayFabResultCommon(),
                TaskId(src.TaskId)
            {}

            ~CreateTaskResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("TaskId")], TaskId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TaskId; ToJsonUtilS(TaskId, each_TaskId); output[U("TaskId")] = each_TaskId;
                return output;
            }
        };

        struct DeleteContentRequest : public PlayFabRequestCommon
        {
            std::string Key;

            DeleteContentRequest() :
                PlayFabRequestCommon(),
                Key()
            {}

            DeleteContentRequest(const DeleteContentRequest& src) :
                PlayFabRequestCommon(),
                Key(src.Key)
            {}

            ~DeleteContentRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Key")], Key);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[U("Key")] = each_Key;
                return output;
            }
        };

        struct DeletePlayerRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            DeletePlayerRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            DeletePlayerRequest(const DeletePlayerRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~DeletePlayerRequest() { }

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

        struct DeletePlayerResult : public PlayFabResultCommon
        {

            DeletePlayerResult() :
                PlayFabResultCommon()
            {}

            DeletePlayerResult(const DeletePlayerResult& src) :
                PlayFabResultCommon()
            {}

            ~DeletePlayerResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct DeletePlayerSharedSecretRequest : public PlayFabRequestCommon
        {
            std::string SecretKey;

            DeletePlayerSharedSecretRequest() :
                PlayFabRequestCommon(),
                SecretKey()
            {}

            DeletePlayerSharedSecretRequest(const DeletePlayerSharedSecretRequest& src) :
                PlayFabRequestCommon(),
                SecretKey(src.SecretKey)
            {}

            ~DeletePlayerSharedSecretRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("SecretKey")], SecretKey);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output[U("SecretKey")] = each_SecretKey;
                return output;
            }
        };

        struct DeletePlayerSharedSecretResult : public PlayFabResultCommon
        {

            DeletePlayerSharedSecretResult() :
                PlayFabResultCommon()
            {}

            DeletePlayerSharedSecretResult(const DeletePlayerSharedSecretResult& src) :
                PlayFabResultCommon()
            {}

            ~DeletePlayerSharedSecretResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct DeleteStoreRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::string StoreId;

            DeleteStoreRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                StoreId()
            {}

            DeleteStoreRequest(const DeleteStoreRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId)
            {}

            ~DeleteStoreRequest() { }

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

        struct DeleteStoreResult : public PlayFabResultCommon
        {

            DeleteStoreResult() :
                PlayFabResultCommon()
            {}

            DeleteStoreResult(const DeleteStoreResult& src) :
                PlayFabResultCommon()
            {}

            ~DeleteStoreResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct DeleteTaskRequest : public PlayFabRequestCommon
        {
            Boxed<NameIdentifier> Identifier;

            DeleteTaskRequest() :
                PlayFabRequestCommon(),
                Identifier()
            {}

            DeleteTaskRequest(const DeleteTaskRequest& src) :
                PlayFabRequestCommon(),
                Identifier(src.Identifier)
            {}

            ~DeleteTaskRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Identifier")], Identifier);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output[U("Identifier")] = each_Identifier;
                return output;
            }
        };

        struct DeleteTitleRequest : public PlayFabRequestCommon
        {

            DeleteTitleRequest() :
                PlayFabRequestCommon()
            {}

            DeleteTitleRequest(const DeleteTitleRequest& src) :
                PlayFabRequestCommon()
            {}

            ~DeleteTitleRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct DeleteTitleResult : public PlayFabResultCommon
        {

            DeleteTitleResult() :
                PlayFabResultCommon()
            {}

            DeleteTitleResult(const DeleteTitleResult& src) :
                PlayFabResultCommon()
            {}

            ~DeleteTitleResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
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

        struct GameModeInfo : public PlayFabBaseModel
        {
            std::string Gamemode;
            Uint32 MaxPlayerCount;
            Uint32 MinPlayerCount;
            Boxed<bool> StartOpen;

            GameModeInfo() :
                PlayFabBaseModel(),
                Gamemode(),
                MaxPlayerCount(),
                MinPlayerCount(),
                StartOpen()
            {}

            GameModeInfo(const GameModeInfo& src) :
                PlayFabBaseModel(),
                Gamemode(src.Gamemode),
                MaxPlayerCount(src.MaxPlayerCount),
                MinPlayerCount(src.MinPlayerCount),
                StartOpen(src.StartOpen)
            {}

            ~GameModeInfo() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Gamemode")], Gamemode);
                FromJsonUtilP(input[U("MaxPlayerCount")], MaxPlayerCount);
                FromJsonUtilP(input[U("MinPlayerCount")], MinPlayerCount);
                FromJsonUtilP(input[U("StartOpen")], StartOpen);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Gamemode; ToJsonUtilS(Gamemode, each_Gamemode); output[U("Gamemode")] = each_Gamemode;
                web::json::value each_MaxPlayerCount; ToJsonUtilP(MaxPlayerCount, each_MaxPlayerCount); output[U("MaxPlayerCount")] = each_MaxPlayerCount;
                web::json::value each_MinPlayerCount; ToJsonUtilP(MinPlayerCount, each_MinPlayerCount); output[U("MinPlayerCount")] = each_MinPlayerCount;
                web::json::value each_StartOpen; ToJsonUtilP(StartOpen, each_StartOpen); output[U("StartOpen")] = each_StartOpen;
                return output;
            }
        };

        struct GetActionsOnPlayersInSegmentTaskInstanceResult : public PlayFabResultCommon
        {
            Boxed<ActionsOnPlayersInSegmentTaskParameter> Parameter;
            Boxed<ActionsOnPlayersInSegmentTaskSummary> Summary;

            GetActionsOnPlayersInSegmentTaskInstanceResult() :
                PlayFabResultCommon(),
                Parameter(),
                Summary()
            {}

            GetActionsOnPlayersInSegmentTaskInstanceResult(const GetActionsOnPlayersInSegmentTaskInstanceResult& src) :
                PlayFabResultCommon(),
                Parameter(src.Parameter),
                Summary(src.Summary)
            {}

            ~GetActionsOnPlayersInSegmentTaskInstanceResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Parameter")], Parameter);
                FromJsonUtilO(input[U("Summary")], Summary);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output[U("Parameter")] = each_Parameter;
                web::json::value each_Summary; ToJsonUtilO(Summary, each_Summary); output[U("Summary")] = each_Summary;
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

        struct GetCloudScriptRevisionRequest : public PlayFabRequestCommon
        {
            Boxed<Int32> Revision;
            Boxed<Int32> Version;

            GetCloudScriptRevisionRequest() :
                PlayFabRequestCommon(),
                Revision(),
                Version()
            {}

            GetCloudScriptRevisionRequest(const GetCloudScriptRevisionRequest& src) :
                PlayFabRequestCommon(),
                Revision(src.Revision),
                Version(src.Version)
            {}

            ~GetCloudScriptRevisionRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Revision")], Revision);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[U("Revision")] = each_Revision;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetCloudScriptRevisionResult : public PlayFabResultCommon
        {
            time_t CreatedAt;
            std::list<CloudScriptFile> Files;
            bool IsPublished;
            Int32 Revision;
            Int32 Version;

            GetCloudScriptRevisionResult() :
                PlayFabResultCommon(),
                CreatedAt(),
                Files(),
                IsPublished(),
                Revision(),
                Version()
            {}

            GetCloudScriptRevisionResult(const GetCloudScriptRevisionResult& src) :
                PlayFabResultCommon(),
                CreatedAt(src.CreatedAt),
                Files(src.Files),
                IsPublished(src.IsPublished),
                Revision(src.Revision),
                Version(src.Version)
            {}

            ~GetCloudScriptRevisionResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("CreatedAt")], CreatedAt);
                FromJsonUtilO(input[U("Files")], Files);
                FromJsonUtilP(input[U("IsPublished")], IsPublished);
                FromJsonUtilP(input[U("Revision")], Revision);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CreatedAt; ToJsonUtilT(CreatedAt, each_CreatedAt); output[U("CreatedAt")] = each_CreatedAt;
                web::json::value each_Files; ToJsonUtilO(Files, each_Files); output[U("Files")] = each_Files;
                web::json::value each_IsPublished; ToJsonUtilP(IsPublished, each_IsPublished); output[U("IsPublished")] = each_IsPublished;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[U("Revision")] = each_Revision;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct GetCloudScriptTaskInstanceResult : public PlayFabResultCommon
        {
            Boxed<CloudScriptTaskParameter> Parameter;
            Boxed<CloudScriptTaskSummary> Summary;

            GetCloudScriptTaskInstanceResult() :
                PlayFabResultCommon(),
                Parameter(),
                Summary()
            {}

            GetCloudScriptTaskInstanceResult(const GetCloudScriptTaskInstanceResult& src) :
                PlayFabResultCommon(),
                Parameter(src.Parameter),
                Summary(src.Summary)
            {}

            ~GetCloudScriptTaskInstanceResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Parameter")], Parameter);
                FromJsonUtilO(input[U("Summary")], Summary);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Parameter; ToJsonUtilO(Parameter, each_Parameter); output[U("Parameter")] = each_Parameter;
                web::json::value each_Summary; ToJsonUtilO(Summary, each_Summary); output[U("Summary")] = each_Summary;
                return output;
            }
        };

        struct GetCloudScriptVersionsRequest : public PlayFabRequestCommon
        {

            GetCloudScriptVersionsRequest() :
                PlayFabRequestCommon()
            {}

            GetCloudScriptVersionsRequest(const GetCloudScriptVersionsRequest& src) :
                PlayFabRequestCommon()
            {}

            ~GetCloudScriptVersionsRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetCloudScriptVersionsResult : public PlayFabResultCommon
        {
            std::list<CloudScriptVersionStatus> Versions;

            GetCloudScriptVersionsResult() :
                PlayFabResultCommon(),
                Versions()
            {}

            GetCloudScriptVersionsResult(const GetCloudScriptVersionsResult& src) :
                PlayFabResultCommon(),
                Versions(src.Versions)
            {}

            ~GetCloudScriptVersionsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Versions")], Versions);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Versions; ToJsonUtilO(Versions, each_Versions); output[U("Versions")] = each_Versions;
                return output;
            }
        };

        struct GetContentListRequest : public PlayFabRequestCommon
        {
            std::string Prefix;

            GetContentListRequest() :
                PlayFabRequestCommon(),
                Prefix()
            {}

            GetContentListRequest(const GetContentListRequest& src) :
                PlayFabRequestCommon(),
                Prefix(src.Prefix)
            {}

            ~GetContentListRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Prefix")], Prefix);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Prefix; ToJsonUtilS(Prefix, each_Prefix); output[U("Prefix")] = each_Prefix;
                return output;
            }
        };

        struct GetContentListResult : public PlayFabResultCommon
        {
            std::list<ContentInfo> Contents;
            Int32 ItemCount;
            Uint32 TotalSize;

            GetContentListResult() :
                PlayFabResultCommon(),
                Contents(),
                ItemCount(),
                TotalSize()
            {}

            GetContentListResult(const GetContentListResult& src) :
                PlayFabResultCommon(),
                Contents(src.Contents),
                ItemCount(src.ItemCount),
                TotalSize(src.TotalSize)
            {}

            ~GetContentListResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Contents")], Contents);
                FromJsonUtilP(input[U("ItemCount")], ItemCount);
                FromJsonUtilP(input[U("TotalSize")], TotalSize);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Contents; ToJsonUtilO(Contents, each_Contents); output[U("Contents")] = each_Contents;
                web::json::value each_ItemCount; ToJsonUtilP(ItemCount, each_ItemCount); output[U("ItemCount")] = each_ItemCount;
                web::json::value each_TotalSize; ToJsonUtilP(TotalSize, each_TotalSize); output[U("TotalSize")] = each_TotalSize;
                return output;
            }
        };

        struct GetContentUploadUrlRequest : public PlayFabRequestCommon
        {
            std::string ContentType;
            std::string Key;

            GetContentUploadUrlRequest() :
                PlayFabRequestCommon(),
                ContentType(),
                Key()
            {}

            GetContentUploadUrlRequest(const GetContentUploadUrlRequest& src) :
                PlayFabRequestCommon(),
                ContentType(src.ContentType),
                Key(src.Key)
            {}

            ~GetContentUploadUrlRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ContentType")], ContentType);
                FromJsonUtilS(input[U("Key")], Key);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ContentType; ToJsonUtilS(ContentType, each_ContentType); output[U("ContentType")] = each_ContentType;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[U("Key")] = each_Key;
                return output;
            }
        };

        struct GetContentUploadUrlResult : public PlayFabResultCommon
        {
            std::string URL;

            GetContentUploadUrlResult() :
                PlayFabResultCommon(),
                URL()
            {}

            GetContentUploadUrlResult(const GetContentUploadUrlResult& src) :
                PlayFabResultCommon(),
                URL(src.URL)
            {}

            ~GetContentUploadUrlResult() { }

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

        struct GetDataReportRequest : public PlayFabRequestCommon
        {
            Int32 Day;
            Int32 Month;
            std::string ReportName;
            Int32 Year;

            GetDataReportRequest() :
                PlayFabRequestCommon(),
                Day(),
                Month(),
                ReportName(),
                Year()
            {}

            GetDataReportRequest(const GetDataReportRequest& src) :
                PlayFabRequestCommon(),
                Day(src.Day),
                Month(src.Month),
                ReportName(src.ReportName),
                Year(src.Year)
            {}

            ~GetDataReportRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Day")], Day);
                FromJsonUtilP(input[U("Month")], Month);
                FromJsonUtilS(input[U("ReportName")], ReportName);
                FromJsonUtilP(input[U("Year")], Year);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Day; ToJsonUtilP(Day, each_Day); output[U("Day")] = each_Day;
                web::json::value each_Month; ToJsonUtilP(Month, each_Month); output[U("Month")] = each_Month;
                web::json::value each_ReportName; ToJsonUtilS(ReportName, each_ReportName); output[U("ReportName")] = each_ReportName;
                web::json::value each_Year; ToJsonUtilP(Year, each_Year); output[U("Year")] = each_Year;
                return output;
            }
        };

        struct GetDataReportResult : public PlayFabResultCommon
        {
            std::string DownloadUrl;

            GetDataReportResult() :
                PlayFabResultCommon(),
                DownloadUrl()
            {}

            GetDataReportResult(const GetDataReportResult& src) :
                PlayFabResultCommon(),
                DownloadUrl(src.DownloadUrl)
            {}

            ~GetDataReportResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DownloadUrl")], DownloadUrl);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DownloadUrl; ToJsonUtilS(DownloadUrl, each_DownloadUrl); output[U("DownloadUrl")] = each_DownloadUrl;
                return output;
            }
        };

        struct GetMatchmakerGameInfoRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;

            GetMatchmakerGameInfoRequest() :
                PlayFabRequestCommon(),
                LobbyId()
            {}

            GetMatchmakerGameInfoRequest(const GetMatchmakerGameInfoRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId)
            {}

            ~GetMatchmakerGameInfoRequest() { }

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

        struct GetMatchmakerGameInfoResult : public PlayFabResultCommon
        {
            std::string BuildVersion;
            Boxed<time_t> EndTime;
            std::string LobbyId;
            std::string Mode;
            std::list<std::string> Players;
            Boxed<Region> pfRegion;
            std::string ServerAddress;
            Uint32 ServerPort;
            time_t StartTime;
            std::string TitleId;

            GetMatchmakerGameInfoResult() :
                PlayFabResultCommon(),
                BuildVersion(),
                EndTime(),
                LobbyId(),
                Mode(),
                Players(),
                pfRegion(),
                ServerAddress(),
                ServerPort(),
                StartTime(),
                TitleId()
            {}

            GetMatchmakerGameInfoResult(const GetMatchmakerGameInfoResult& src) :
                PlayFabResultCommon(),
                BuildVersion(src.BuildVersion),
                EndTime(src.EndTime),
                LobbyId(src.LobbyId),
                Mode(src.Mode),
                Players(src.Players),
                pfRegion(src.pfRegion),
                ServerAddress(src.ServerAddress),
                ServerPort(src.ServerPort),
                StartTime(src.StartTime),
                TitleId(src.TitleId)
            {}

            ~GetMatchmakerGameInfoResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildVersion")], BuildVersion);
                FromJsonUtilT(input[U("EndTime")], EndTime);
                FromJsonUtilS(input[U("LobbyId")], LobbyId);
                FromJsonUtilS(input[U("Mode")], Mode);
                FromJsonUtilS(input[U("Players")], Players);
                FromJsonUtilE(input[U("pfRegion")], pfRegion);
                FromJsonUtilS(input[U("ServerAddress")], ServerAddress);
                FromJsonUtilP(input[U("ServerPort")], ServerPort);
                FromJsonUtilT(input[U("StartTime")], StartTime);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[U("BuildVersion")] = each_BuildVersion;
                web::json::value each_EndTime; ToJsonUtilT(EndTime, each_EndTime); output[U("EndTime")] = each_EndTime;
                web::json::value each_LobbyId; ToJsonUtilS(LobbyId, each_LobbyId); output[U("LobbyId")] = each_LobbyId;
                web::json::value each_Mode; ToJsonUtilS(Mode, each_Mode); output[U("Mode")] = each_Mode;
                web::json::value each_Players; ToJsonUtilS(Players, each_Players); output[U("Players")] = each_Players;
                web::json::value each_pfRegion; ToJsonUtilE(pfRegion, each_pfRegion); output[U("Region")] = each_pfRegion;
                web::json::value each_ServerAddress; ToJsonUtilS(ServerAddress, each_ServerAddress); output[U("ServerAddress")] = each_ServerAddress;
                web::json::value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output[U("ServerPort")] = each_ServerPort;
                web::json::value each_StartTime; ToJsonUtilT(StartTime, each_StartTime); output[U("StartTime")] = each_StartTime;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct GetMatchmakerGameModesRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;

            GetMatchmakerGameModesRequest() :
                PlayFabRequestCommon(),
                BuildVersion()
            {}

            GetMatchmakerGameModesRequest(const GetMatchmakerGameModesRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion)
            {}

            ~GetMatchmakerGameModesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildVersion")], BuildVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[U("BuildVersion")] = each_BuildVersion;
                return output;
            }
        };

        struct GetMatchmakerGameModesResult : public PlayFabResultCommon
        {
            std::list<GameModeInfo> GameModes;

            GetMatchmakerGameModesResult() :
                PlayFabResultCommon(),
                GameModes()
            {}

            GetMatchmakerGameModesResult(const GetMatchmakerGameModesResult& src) :
                PlayFabResultCommon(),
                GameModes(src.GameModes)
            {}

            ~GetMatchmakerGameModesResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("GameModes")], GameModes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameModes; ToJsonUtilO(GameModes, each_GameModes); output[U("GameModes")] = each_GameModes;
                return output;
            }
        };

        struct GetPlayerIdFromAuthTokenRequest : public PlayFabRequestCommon
        {
            std::string Token;
            AuthTokenType TokenType;

            GetPlayerIdFromAuthTokenRequest() :
                PlayFabRequestCommon(),
                Token(),
                TokenType()
            {}

            GetPlayerIdFromAuthTokenRequest(const GetPlayerIdFromAuthTokenRequest& src) :
                PlayFabRequestCommon(),
                Token(src.Token),
                TokenType(src.TokenType)
            {}

            ~GetPlayerIdFromAuthTokenRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Token")], Token);
                FromJsonEnum(input[U("TokenType")], TokenType);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Token; ToJsonUtilS(Token, each_Token); output[U("Token")] = each_Token;
                web::json::value each_TokenType; ToJsonEnum(TokenType, each_TokenType); output[U("TokenType")] = each_TokenType;
                return output;
            }
        };

        struct GetPlayerIdFromAuthTokenResult : public PlayFabResultCommon
        {
            std::string PlayFabId;

            GetPlayerIdFromAuthTokenResult() :
                PlayFabResultCommon(),
                PlayFabId()
            {}

            GetPlayerIdFromAuthTokenResult(const GetPlayerIdFromAuthTokenResult& src) :
                PlayFabResultCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~GetPlayerIdFromAuthTokenResult() { }

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

        struct GetPlayerSharedSecretsRequest : public PlayFabRequestCommon
        {

            GetPlayerSharedSecretsRequest() :
                PlayFabRequestCommon()
            {}

            GetPlayerSharedSecretsRequest(const GetPlayerSharedSecretsRequest& src) :
                PlayFabRequestCommon()
            {}

            ~GetPlayerSharedSecretsRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct SharedSecret : public PlayFabBaseModel
        {
            bool Disabled;
            std::string FriendlyName;
            std::string SecretKey;

            SharedSecret() :
                PlayFabBaseModel(),
                Disabled(),
                FriendlyName(),
                SecretKey()
            {}

            SharedSecret(const SharedSecret& src) :
                PlayFabBaseModel(),
                Disabled(src.Disabled),
                FriendlyName(src.FriendlyName),
                SecretKey(src.SecretKey)
            {}

            ~SharedSecret() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Disabled")], Disabled);
                FromJsonUtilS(input[U("FriendlyName")], FriendlyName);
                FromJsonUtilS(input[U("SecretKey")], SecretKey);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Disabled; ToJsonUtilP(Disabled, each_Disabled); output[U("Disabled")] = each_Disabled;
                web::json::value each_FriendlyName; ToJsonUtilS(FriendlyName, each_FriendlyName); output[U("FriendlyName")] = each_FriendlyName;
                web::json::value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output[U("SecretKey")] = each_SecretKey;
                return output;
            }
        };

        struct GetPlayerSharedSecretsResult : public PlayFabResultCommon
        {
            std::list<SharedSecret> SharedSecrets;

            GetPlayerSharedSecretsResult() :
                PlayFabResultCommon(),
                SharedSecrets()
            {}

            GetPlayerSharedSecretsResult(const GetPlayerSharedSecretsResult& src) :
                PlayFabResultCommon(),
                SharedSecrets(src.SharedSecrets)
            {}

            ~GetPlayerSharedSecretsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("SharedSecrets")], SharedSecrets);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_SharedSecrets; ToJsonUtilO(SharedSecrets, each_SharedSecrets); output[U("SharedSecrets")] = each_SharedSecrets;
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

        struct GetPlayerStatisticDefinitionsRequest : public PlayFabRequestCommon
        {

            GetPlayerStatisticDefinitionsRequest() :
                PlayFabRequestCommon()
            {}

            GetPlayerStatisticDefinitionsRequest(const GetPlayerStatisticDefinitionsRequest& src) :
                PlayFabRequestCommon()
            {}

            ~GetPlayerStatisticDefinitionsRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct GetPlayerStatisticDefinitionsResult : public PlayFabResultCommon
        {
            std::list<PlayerStatisticDefinition> Statistics;

            GetPlayerStatisticDefinitionsResult() :
                PlayFabResultCommon(),
                Statistics()
            {}

            GetPlayerStatisticDefinitionsResult(const GetPlayerStatisticDefinitionsResult& src) :
                PlayFabResultCommon(),
                Statistics(src.Statistics)
            {}

            ~GetPlayerStatisticDefinitionsResult() { }

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
            std::string ArchiveDownloadUrl;
            Boxed<time_t> DeactivationTime;
            Boxed<time_t> ScheduledActivationTime;
            Boxed<time_t> ScheduledDeactivationTime;
            std::string StatisticName;
            Boxed<StatisticVersionStatus> Status;
            Uint32 Version;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                ActivationTime(),
                ArchiveDownloadUrl(),
                DeactivationTime(),
                ScheduledActivationTime(),
                ScheduledDeactivationTime(),
                StatisticName(),
                Status(),
                Version()
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                ActivationTime(src.ActivationTime),
                ArchiveDownloadUrl(src.ArchiveDownloadUrl),
                DeactivationTime(src.DeactivationTime),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                StatisticName(src.StatisticName),
                Status(src.Status),
                Version(src.Version)
            {}

            ~PlayerStatisticVersion() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("ActivationTime")], ActivationTime);
                FromJsonUtilS(input[U("ArchiveDownloadUrl")], ArchiveDownloadUrl);
                FromJsonUtilT(input[U("DeactivationTime")], DeactivationTime);
                FromJsonUtilT(input[U("ScheduledActivationTime")], ScheduledActivationTime);
                FromJsonUtilT(input[U("ScheduledDeactivationTime")], ScheduledDeactivationTime);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActivationTime; ToJsonUtilT(ActivationTime, each_ActivationTime); output[U("ActivationTime")] = each_ActivationTime;
                web::json::value each_ArchiveDownloadUrl; ToJsonUtilS(ArchiveDownloadUrl, each_ArchiveDownloadUrl); output[U("ArchiveDownloadUrl")] = each_ArchiveDownloadUrl;
                web::json::value each_DeactivationTime; ToJsonUtilT(DeactivationTime, each_DeactivationTime); output[U("DeactivationTime")] = each_DeactivationTime;
                web::json::value each_ScheduledActivationTime; ToJsonUtilT(ScheduledActivationTime, each_ScheduledActivationTime); output[U("ScheduledActivationTime")] = each_ScheduledActivationTime;
                web::json::value each_ScheduledDeactivationTime; ToJsonUtilT(ScheduledDeactivationTime, each_ScheduledDeactivationTime); output[U("ScheduledDeactivationTime")] = each_ScheduledDeactivationTime;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
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

        struct GetPolicyRequest : public PlayFabRequestCommon
        {
            std::string PolicyName;

            GetPolicyRequest() :
                PlayFabRequestCommon(),
                PolicyName()
            {}

            GetPolicyRequest(const GetPolicyRequest& src) :
                PlayFabRequestCommon(),
                PolicyName(src.PolicyName)
            {}

            ~GetPolicyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PolicyName")], PolicyName);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output[U("PolicyName")] = each_PolicyName;
                return output;
            }
        };

        struct PermissionStatement : public PlayFabBaseModel
        {
            std::string Action;
            Boxed<ApiCondition> ApiConditions;
            std::string Comment;
            EffectType Effect;
            std::string Principal;
            std::string Resource;

            PermissionStatement() :
                PlayFabBaseModel(),
                Action(),
                ApiConditions(),
                Comment(),
                Effect(),
                Principal(),
                Resource()
            {}

            PermissionStatement(const PermissionStatement& src) :
                PlayFabBaseModel(),
                Action(src.Action),
                ApiConditions(src.ApiConditions),
                Comment(src.Comment),
                Effect(src.Effect),
                Principal(src.Principal),
                Resource(src.Resource)
            {}

            ~PermissionStatement() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Action")], Action);
                FromJsonUtilO(input[U("ApiConditions")], ApiConditions);
                FromJsonUtilS(input[U("Comment")], Comment);
                FromJsonEnum(input[U("Effect")], Effect);
                FromJsonUtilS(input[U("Principal")], Principal);
                FromJsonUtilS(input[U("Resource")], Resource);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Action; ToJsonUtilS(Action, each_Action); output[U("Action")] = each_Action;
                web::json::value each_ApiConditions; ToJsonUtilO(ApiConditions, each_ApiConditions); output[U("ApiConditions")] = each_ApiConditions;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[U("Comment")] = each_Comment;
                web::json::value each_Effect; ToJsonEnum(Effect, each_Effect); output[U("Effect")] = each_Effect;
                web::json::value each_Principal; ToJsonUtilS(Principal, each_Principal); output[U("Principal")] = each_Principal;
                web::json::value each_Resource; ToJsonUtilS(Resource, each_Resource); output[U("Resource")] = each_Resource;
                return output;
            }
        };

        struct GetPolicyResponse : public PlayFabResultCommon
        {
            std::string PolicyName;
            std::list<PermissionStatement> Statements;

            GetPolicyResponse() :
                PlayFabResultCommon(),
                PolicyName(),
                Statements()
            {}

            GetPolicyResponse(const GetPolicyResponse& src) :
                PlayFabResultCommon(),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            ~GetPolicyResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PolicyName")], PolicyName);
                FromJsonUtilO(input[U("Statements")], Statements);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output[U("PolicyName")] = each_PolicyName;
                web::json::value each_Statements; ToJsonUtilO(Statements, each_Statements); output[U("Statements")] = each_Statements;
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

            GetRandomResultTablesRequest() :
                PlayFabRequestCommon(),
                CatalogVersion()
            {}

            GetRandomResultTablesRequest(const GetRandomResultTablesRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion)
            {}

            ~GetRandomResultTablesRequest() { }

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

        struct GetServerBuildInfoRequest : public PlayFabRequestCommon
        {
            std::string BuildId;

            GetServerBuildInfoRequest() :
                PlayFabRequestCommon(),
                BuildId()
            {}

            GetServerBuildInfoRequest(const GetServerBuildInfoRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId)
            {}

            ~GetServerBuildInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildId")], BuildId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[U("BuildId")] = each_BuildId;
                return output;
            }
        };

        struct GetServerBuildInfoResult : public PlayFabResultCommon
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string Comment;
            std::string ErrorMessage;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<GameBuildStatus> Status;
            time_t Timestamp;
            std::string TitleId;

            GetServerBuildInfoResult() :
                PlayFabResultCommon(),
                ActiveRegions(),
                BuildId(),
                Comment(),
                ErrorMessage(),
                MaxGamesPerHost(),
                MinFreeGameSlots(),
                Status(),
                Timestamp(),
                TitleId()
            {}

            GetServerBuildInfoResult(const GetServerBuildInfoResult& src) :
                PlayFabResultCommon(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                Comment(src.Comment),
                ErrorMessage(src.ErrorMessage),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Status(src.Status),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId)
            {}

            ~GetServerBuildInfoResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("ActiveRegions")], ActiveRegions);
                FromJsonUtilS(input[U("BuildId")], BuildId);
                FromJsonUtilS(input[U("Comment")], Comment);
                FromJsonUtilS(input[U("ErrorMessage")], ErrorMessage);
                FromJsonUtilP(input[U("MaxGamesPerHost")], MaxGamesPerHost);
                FromJsonUtilP(input[U("MinFreeGameSlots")], MinFreeGameSlots);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output[U("ActiveRegions")] = each_ActiveRegions;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[U("BuildId")] = each_BuildId;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[U("Comment")] = each_Comment;
                web::json::value each_ErrorMessage; ToJsonUtilS(ErrorMessage, each_ErrorMessage); output[U("ErrorMessage")] = each_ErrorMessage;
                web::json::value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output[U("MaxGamesPerHost")] = each_MaxGamesPerHost;
                web::json::value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output[U("MinFreeGameSlots")] = each_MinFreeGameSlots;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
                return output;
            }
        };

        struct GetServerBuildUploadURLRequest : public PlayFabRequestCommon
        {
            std::string BuildId;

            GetServerBuildUploadURLRequest() :
                PlayFabRequestCommon(),
                BuildId()
            {}

            GetServerBuildUploadURLRequest(const GetServerBuildUploadURLRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId)
            {}

            ~GetServerBuildUploadURLRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildId")], BuildId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[U("BuildId")] = each_BuildId;
                return output;
            }
        };

        struct GetServerBuildUploadURLResult : public PlayFabResultCommon
        {
            std::string URL;

            GetServerBuildUploadURLResult() :
                PlayFabResultCommon(),
                URL()
            {}

            GetServerBuildUploadURLResult(const GetServerBuildUploadURLResult& src) :
                PlayFabResultCommon(),
                URL(src.URL)
            {}

            ~GetServerBuildUploadURLResult() { }

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

        struct GetTaskInstanceRequest : public PlayFabRequestCommon
        {
            std::string TaskInstanceId;

            GetTaskInstanceRequest() :
                PlayFabRequestCommon(),
                TaskInstanceId()
            {}

            GetTaskInstanceRequest(const GetTaskInstanceRequest& src) :
                PlayFabRequestCommon(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            ~GetTaskInstanceRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("TaskInstanceId")], TaskInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[U("TaskInstanceId")] = each_TaskInstanceId;
                return output;
            }
        };

        struct GetTaskInstancesRequest : public PlayFabRequestCommon
        {
            Boxed<time_t> StartedAtRangeFrom;
            Boxed<time_t> StartedAtRangeTo;
            Boxed<TaskInstanceStatus> StatusFilter;
            Boxed<NameIdentifier> TaskIdentifier;

            GetTaskInstancesRequest() :
                PlayFabRequestCommon(),
                StartedAtRangeFrom(),
                StartedAtRangeTo(),
                StatusFilter(),
                TaskIdentifier()
            {}

            GetTaskInstancesRequest(const GetTaskInstancesRequest& src) :
                PlayFabRequestCommon(),
                StartedAtRangeFrom(src.StartedAtRangeFrom),
                StartedAtRangeTo(src.StartedAtRangeTo),
                StatusFilter(src.StatusFilter),
                TaskIdentifier(src.TaskIdentifier)
            {}

            ~GetTaskInstancesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("StartedAtRangeFrom")], StartedAtRangeFrom);
                FromJsonUtilT(input[U("StartedAtRangeTo")], StartedAtRangeTo);
                FromJsonUtilE(input[U("StatusFilter")], StatusFilter);
                FromJsonUtilO(input[U("TaskIdentifier")], TaskIdentifier);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StartedAtRangeFrom; ToJsonUtilT(StartedAtRangeFrom, each_StartedAtRangeFrom); output[U("StartedAtRangeFrom")] = each_StartedAtRangeFrom;
                web::json::value each_StartedAtRangeTo; ToJsonUtilT(StartedAtRangeTo, each_StartedAtRangeTo); output[U("StartedAtRangeTo")] = each_StartedAtRangeTo;
                web::json::value each_StatusFilter; ToJsonUtilE(StatusFilter, each_StatusFilter); output[U("StatusFilter")] = each_StatusFilter;
                web::json::value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output[U("TaskIdentifier")] = each_TaskIdentifier;
                return output;
            }
        };

        struct TaskInstanceBasicSummary : public PlayFabBaseModel
        {
            Boxed<time_t> CompletedAt;
            Boxed<double> EstimatedSecondsRemaining;
            Boxed<double> PercentComplete;
            std::string ScheduledByUserId;
            time_t StartedAt;
            Boxed<TaskInstanceStatus> Status;
            Boxed<NameIdentifier> TaskIdentifier;
            std::string TaskInstanceId;
            Boxed<ScheduledTaskType> Type;

            TaskInstanceBasicSummary() :
                PlayFabBaseModel(),
                CompletedAt(),
                EstimatedSecondsRemaining(),
                PercentComplete(),
                ScheduledByUserId(),
                StartedAt(),
                Status(),
                TaskIdentifier(),
                TaskInstanceId(),
                Type()
            {}

            TaskInstanceBasicSummary(const TaskInstanceBasicSummary& src) :
                PlayFabBaseModel(),
                CompletedAt(src.CompletedAt),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                PercentComplete(src.PercentComplete),
                ScheduledByUserId(src.ScheduledByUserId),
                StartedAt(src.StartedAt),
                Status(src.Status),
                TaskIdentifier(src.TaskIdentifier),
                TaskInstanceId(src.TaskInstanceId),
                Type(src.Type)
            {}

            ~TaskInstanceBasicSummary() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilT(input[U("CompletedAt")], CompletedAt);
                FromJsonUtilP(input[U("EstimatedSecondsRemaining")], EstimatedSecondsRemaining);
                FromJsonUtilP(input[U("PercentComplete")], PercentComplete);
                FromJsonUtilS(input[U("ScheduledByUserId")], ScheduledByUserId);
                FromJsonUtilT(input[U("StartedAt")], StartedAt);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilO(input[U("TaskIdentifier")], TaskIdentifier);
                FromJsonUtilS(input[U("TaskInstanceId")], TaskInstanceId);
                FromJsonUtilE(input[U("Type")], Type);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CompletedAt; ToJsonUtilT(CompletedAt, each_CompletedAt); output[U("CompletedAt")] = each_CompletedAt;
                web::json::value each_EstimatedSecondsRemaining; ToJsonUtilP(EstimatedSecondsRemaining, each_EstimatedSecondsRemaining); output[U("EstimatedSecondsRemaining")] = each_EstimatedSecondsRemaining;
                web::json::value each_PercentComplete; ToJsonUtilP(PercentComplete, each_PercentComplete); output[U("PercentComplete")] = each_PercentComplete;
                web::json::value each_ScheduledByUserId; ToJsonUtilS(ScheduledByUserId, each_ScheduledByUserId); output[U("ScheduledByUserId")] = each_ScheduledByUserId;
                web::json::value each_StartedAt; ToJsonUtilT(StartedAt, each_StartedAt); output[U("StartedAt")] = each_StartedAt;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
                web::json::value each_TaskIdentifier; ToJsonUtilO(TaskIdentifier, each_TaskIdentifier); output[U("TaskIdentifier")] = each_TaskIdentifier;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[U("TaskInstanceId")] = each_TaskInstanceId;
                web::json::value each_Type; ToJsonUtilE(Type, each_Type); output[U("Type")] = each_Type;
                return output;
            }
        };

        struct GetTaskInstancesResult : public PlayFabResultCommon
        {
            std::list<TaskInstanceBasicSummary> Summaries;

            GetTaskInstancesResult() :
                PlayFabResultCommon(),
                Summaries()
            {}

            GetTaskInstancesResult(const GetTaskInstancesResult& src) :
                PlayFabResultCommon(),
                Summaries(src.Summaries)
            {}

            ~GetTaskInstancesResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Summaries")], Summaries);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Summaries; ToJsonUtilO(Summaries, each_Summaries); output[U("Summaries")] = each_Summaries;
                return output;
            }
        };

        struct GetTasksRequest : public PlayFabRequestCommon
        {
            Boxed<NameIdentifier> Identifier;

            GetTasksRequest() :
                PlayFabRequestCommon(),
                Identifier()
            {}

            GetTasksRequest(const GetTasksRequest& src) :
                PlayFabRequestCommon(),
                Identifier(src.Identifier)
            {}

            ~GetTasksRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Identifier")], Identifier);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output[U("Identifier")] = each_Identifier;
                return output;
            }
        };

        struct ScheduledTask : public PlayFabBaseModel
        {
            std::string Description;
            bool IsActive;
            Boxed<time_t> LastRunTime;
            std::string Name;
            Boxed<time_t> NextRunTime;
            web::json::value Parameter;
            std::string Schedule;
            std::string TaskId;
            Boxed<ScheduledTaskType> Type;

            ScheduledTask() :
                PlayFabBaseModel(),
                Description(),
                IsActive(),
                LastRunTime(),
                Name(),
                NextRunTime(),
                Parameter(),
                Schedule(),
                TaskId(),
                Type()
            {}

            ScheduledTask(const ScheduledTask& src) :
                PlayFabBaseModel(),
                Description(src.Description),
                IsActive(src.IsActive),
                LastRunTime(src.LastRunTime),
                Name(src.Name),
                NextRunTime(src.NextRunTime),
                Parameter(src.Parameter),
                Schedule(src.Schedule),
                TaskId(src.TaskId),
                Type(src.Type)
            {}

            ~ScheduledTask() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Description")], Description);
                FromJsonUtilP(input[U("IsActive")], IsActive);
                FromJsonUtilT(input[U("LastRunTime")], LastRunTime);
                FromJsonUtilS(input[U("Name")], Name);
                FromJsonUtilT(input[U("NextRunTime")], NextRunTime);
                Parameter = input[U("Parameter")];
                FromJsonUtilS(input[U("Schedule")], Schedule);
                FromJsonUtilS(input[U("TaskId")], TaskId);
                FromJsonUtilE(input[U("Type")], Type);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[U("Description")] = each_Description;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[U("IsActive")] = each_IsActive;
                web::json::value each_LastRunTime; ToJsonUtilT(LastRunTime, each_LastRunTime); output[U("LastRunTime")] = each_LastRunTime;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                web::json::value each_NextRunTime; ToJsonUtilT(NextRunTime, each_NextRunTime); output[U("NextRunTime")] = each_NextRunTime;
                output[U("Parameter")] = Parameter;
                web::json::value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output[U("Schedule")] = each_Schedule;
                web::json::value each_TaskId; ToJsonUtilS(TaskId, each_TaskId); output[U("TaskId")] = each_TaskId;
                web::json::value each_Type; ToJsonUtilE(Type, each_Type); output[U("Type")] = each_Type;
                return output;
            }
        };

        struct GetTasksResult : public PlayFabResultCommon
        {
            std::list<ScheduledTask> Tasks;

            GetTasksResult() :
                PlayFabResultCommon(),
                Tasks()
            {}

            GetTasksResult(const GetTasksResult& src) :
                PlayFabResultCommon(),
                Tasks(src.Tasks)
            {}

            ~GetTasksResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Tasks")], Tasks);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Tasks; ToJsonUtilO(Tasks, each_Tasks); output[U("Tasks")] = each_Tasks;
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

        struct IncrementLimitedEditionItemAvailabilityRequest : public PlayFabRequestCommon
        {
            Int32 Amount;
            std::string CatalogVersion;
            std::string ItemId;

            IncrementLimitedEditionItemAvailabilityRequest() :
                PlayFabRequestCommon(),
                Amount(),
                CatalogVersion(),
                ItemId()
            {}

            IncrementLimitedEditionItemAvailabilityRequest(const IncrementLimitedEditionItemAvailabilityRequest& src) :
                PlayFabRequestCommon(),
                Amount(src.Amount),
                CatalogVersion(src.CatalogVersion),
                ItemId(src.ItemId)
            {}

            ~IncrementLimitedEditionItemAvailabilityRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Amount")], Amount);
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilS(input[U("ItemId")], ItemId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Amount; ToJsonUtilP(Amount, each_Amount); output[U("Amount")] = each_Amount;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_ItemId; ToJsonUtilS(ItemId, each_ItemId); output[U("ItemId")] = each_ItemId;
                return output;
            }
        };

        struct IncrementLimitedEditionItemAvailabilityResult : public PlayFabResultCommon
        {

            IncrementLimitedEditionItemAvailabilityResult() :
                PlayFabResultCommon()
            {}

            IncrementLimitedEditionItemAvailabilityResult(const IncrementLimitedEditionItemAvailabilityResult& src) :
                PlayFabResultCommon()
            {}

            ~IncrementLimitedEditionItemAvailabilityResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct IncrementPlayerStatisticVersionRequest : public PlayFabRequestCommon
        {
            std::string StatisticName;

            IncrementPlayerStatisticVersionRequest() :
                PlayFabRequestCommon(),
                StatisticName()
            {}

            IncrementPlayerStatisticVersionRequest(const IncrementPlayerStatisticVersionRequest& src) :
                PlayFabRequestCommon(),
                StatisticName(src.StatisticName)
            {}

            ~IncrementPlayerStatisticVersionRequest() { }

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

        struct IncrementPlayerStatisticVersionResult : public PlayFabResultCommon
        {
            Boxed<PlayerStatisticVersion> StatisticVersion;

            IncrementPlayerStatisticVersionResult() :
                PlayFabResultCommon(),
                StatisticVersion()
            {}

            IncrementPlayerStatisticVersionResult(const IncrementPlayerStatisticVersionResult& src) :
                PlayFabResultCommon(),
                StatisticVersion(src.StatisticVersion)
            {}

            ~IncrementPlayerStatisticVersionResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("StatisticVersion")], StatisticVersion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_StatisticVersion; ToJsonUtilO(StatisticVersion, each_StatisticVersion); output[U("StatisticVersion")] = each_StatisticVersion;
                return output;
            }
        };

        struct ListBuildsRequest : public PlayFabRequestCommon
        {

            ListBuildsRequest() :
                PlayFabRequestCommon()
            {}

            ListBuildsRequest(const ListBuildsRequest& src) :
                PlayFabRequestCommon()
            {}

            ~ListBuildsRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ListBuildsResult : public PlayFabResultCommon
        {
            std::list<GetServerBuildInfoResult> Builds;

            ListBuildsResult() :
                PlayFabResultCommon(),
                Builds()
            {}

            ListBuildsResult(const ListBuildsResult& src) :
                PlayFabResultCommon(),
                Builds(src.Builds)
            {}

            ~ListBuildsResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Builds")], Builds);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Builds; ToJsonUtilO(Builds, each_Builds); output[U("Builds")] = each_Builds;
                return output;
            }
        };

        struct ListVirtualCurrencyTypesRequest : public PlayFabRequestCommon
        {

            ListVirtualCurrencyTypesRequest() :
                PlayFabRequestCommon()
            {}

            ListVirtualCurrencyTypesRequest(const ListVirtualCurrencyTypesRequest& src) :
                PlayFabRequestCommon()
            {}

            ~ListVirtualCurrencyTypesRequest() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ListVirtualCurrencyTypesResult : public PlayFabResultCommon
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            ListVirtualCurrencyTypesResult() :
                PlayFabResultCommon(),
                VirtualCurrencies()
            {}

            ListVirtualCurrencyTypesResult(const ListVirtualCurrencyTypesResult& src) :
                PlayFabResultCommon(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            ~ListVirtualCurrencyTypesResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("VirtualCurrencies")], VirtualCurrencies);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_VirtualCurrencies; ToJsonUtilO(VirtualCurrencies, each_VirtualCurrencies); output[U("VirtualCurrencies")] = each_VirtualCurrencies;
                return output;
            }
        };

        struct LookupUserAccountInfoRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string PlayFabId;
            std::string TitleDisplayName;
            std::string Username;

            LookupUserAccountInfoRequest() :
                PlayFabRequestCommon(),
                Email(),
                PlayFabId(),
                TitleDisplayName(),
                Username()
            {}

            LookupUserAccountInfoRequest(const LookupUserAccountInfoRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                PlayFabId(src.PlayFabId),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username)
            {}

            ~LookupUserAccountInfoRequest() { }

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

        struct LookupUserAccountInfoResult : public PlayFabResultCommon
        {
            Boxed<UserAccountInfo> UserInfo;

            LookupUserAccountInfoResult() :
                PlayFabResultCommon(),
                UserInfo()
            {}

            LookupUserAccountInfoResult(const LookupUserAccountInfoResult& src) :
                PlayFabResultCommon(),
                UserInfo(src.UserInfo)
            {}

            ~LookupUserAccountInfoResult() { }

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

        struct ModifyMatchmakerGameModesRequest : public PlayFabRequestCommon
        {
            std::string BuildVersion;
            std::list<GameModeInfo> GameModes;

            ModifyMatchmakerGameModesRequest() :
                PlayFabRequestCommon(),
                BuildVersion(),
                GameModes()
            {}

            ModifyMatchmakerGameModesRequest(const ModifyMatchmakerGameModesRequest& src) :
                PlayFabRequestCommon(),
                BuildVersion(src.BuildVersion),
                GameModes(src.GameModes)
            {}

            ~ModifyMatchmakerGameModesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildVersion")], BuildVersion);
                FromJsonUtilO(input[U("GameModes")], GameModes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildVersion; ToJsonUtilS(BuildVersion, each_BuildVersion); output[U("BuildVersion")] = each_BuildVersion;
                web::json::value each_GameModes; ToJsonUtilO(GameModes, each_GameModes); output[U("GameModes")] = each_GameModes;
                return output;
            }
        };

        struct ModifyMatchmakerGameModesResult : public PlayFabResultCommon
        {

            ModifyMatchmakerGameModesResult() :
                PlayFabResultCommon()
            {}

            ModifyMatchmakerGameModesResult(const ModifyMatchmakerGameModesResult& src) :
                PlayFabResultCommon()
            {}

            ~ModifyMatchmakerGameModesResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ModifyServerBuildRequest : public PlayFabRequestCommon
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<time_t> Timestamp;

            ModifyServerBuildRequest() :
                PlayFabRequestCommon(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                ExecutablePath(),
                MaxGamesPerHost(),
                MinFreeGameSlots(),
                Timestamp()
            {}

            ModifyServerBuildRequest(const ModifyServerBuildRequest& src) :
                PlayFabRequestCommon(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Timestamp(src.Timestamp)
            {}

            ~ModifyServerBuildRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("ActiveRegions")], ActiveRegions);
                FromJsonUtilS(input[U("BuildId")], BuildId);
                FromJsonUtilS(input[U("CommandLineTemplate")], CommandLineTemplate);
                FromJsonUtilS(input[U("Comment")], Comment);
                FromJsonUtilS(input[U("ExecutablePath")], ExecutablePath);
                FromJsonUtilP(input[U("MaxGamesPerHost")], MaxGamesPerHost);
                FromJsonUtilP(input[U("MinFreeGameSlots")], MinFreeGameSlots);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output[U("ActiveRegions")] = each_ActiveRegions;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[U("BuildId")] = each_BuildId;
                web::json::value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output[U("CommandLineTemplate")] = each_CommandLineTemplate;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[U("Comment")] = each_Comment;
                web::json::value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output[U("ExecutablePath")] = each_ExecutablePath;
                web::json::value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output[U("MaxGamesPerHost")] = each_MaxGamesPerHost;
                web::json::value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output[U("MinFreeGameSlots")] = each_MinFreeGameSlots;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
                return output;
            }
        };

        struct ModifyServerBuildResult : public PlayFabResultCommon
        {
            std::list<Region> ActiveRegions;
            std::string BuildId;
            std::string CommandLineTemplate;
            std::string Comment;
            std::string ExecutablePath;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            Boxed<GameBuildStatus> Status;
            time_t Timestamp;
            std::string TitleId;

            ModifyServerBuildResult() :
                PlayFabResultCommon(),
                ActiveRegions(),
                BuildId(),
                CommandLineTemplate(),
                Comment(),
                ExecutablePath(),
                MaxGamesPerHost(),
                MinFreeGameSlots(),
                Status(),
                Timestamp(),
                TitleId()
            {}

            ModifyServerBuildResult(const ModifyServerBuildResult& src) :
                PlayFabResultCommon(),
                ActiveRegions(src.ActiveRegions),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                Comment(src.Comment),
                ExecutablePath(src.ExecutablePath),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Status(src.Status),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId)
            {}

            ~ModifyServerBuildResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("ActiveRegions")], ActiveRegions);
                FromJsonUtilS(input[U("BuildId")], BuildId);
                FromJsonUtilS(input[U("CommandLineTemplate")], CommandLineTemplate);
                FromJsonUtilS(input[U("Comment")], Comment);
                FromJsonUtilS(input[U("ExecutablePath")], ExecutablePath);
                FromJsonUtilP(input[U("MaxGamesPerHost")], MaxGamesPerHost);
                FromJsonUtilP(input[U("MinFreeGameSlots")], MinFreeGameSlots);
                FromJsonUtilE(input[U("Status")], Status);
                FromJsonUtilT(input[U("Timestamp")], Timestamp);
                FromJsonUtilS(input[U("TitleId")], TitleId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ActiveRegions; ToJsonUtilE(ActiveRegions, each_ActiveRegions); output[U("ActiveRegions")] = each_ActiveRegions;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[U("BuildId")] = each_BuildId;
                web::json::value each_CommandLineTemplate; ToJsonUtilS(CommandLineTemplate, each_CommandLineTemplate); output[U("CommandLineTemplate")] = each_CommandLineTemplate;
                web::json::value each_Comment; ToJsonUtilS(Comment, each_Comment); output[U("Comment")] = each_Comment;
                web::json::value each_ExecutablePath; ToJsonUtilS(ExecutablePath, each_ExecutablePath); output[U("ExecutablePath")] = each_ExecutablePath;
                web::json::value each_MaxGamesPerHost; ToJsonUtilP(MaxGamesPerHost, each_MaxGamesPerHost); output[U("MaxGamesPerHost")] = each_MaxGamesPerHost;
                web::json::value each_MinFreeGameSlots; ToJsonUtilP(MinFreeGameSlots, each_MinFreeGameSlots); output[U("MinFreeGameSlots")] = each_MinFreeGameSlots;
                web::json::value each_Status; ToJsonUtilE(Status, each_Status); output[U("Status")] = each_Status;
                web::json::value each_Timestamp; ToJsonUtilT(Timestamp, each_Timestamp); output[U("Timestamp")] = each_Timestamp;
                web::json::value each_TitleId; ToJsonUtilS(TitleId, each_TitleId); output[U("TitleId")] = each_TitleId;
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

        struct RandomResultTable : public PlayFabBaseModel
        {
            std::list<ResultTableNode> Nodes;
            std::string TableId;

            RandomResultTable() :
                PlayFabBaseModel(),
                Nodes(),
                TableId()
            {}

            RandomResultTable(const RandomResultTable& src) :
                PlayFabBaseModel(),
                Nodes(src.Nodes),
                TableId(src.TableId)
            {}

            ~RandomResultTable() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Nodes")], Nodes);
                FromJsonUtilS(input[U("TableId")], TableId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Nodes; ToJsonUtilO(Nodes, each_Nodes); output[U("Nodes")] = each_Nodes;
                web::json::value each_TableId; ToJsonUtilS(TableId, each_TableId); output[U("TableId")] = each_TableId;
                return output;
            }
        };

        struct RefundPurchaseRequest : public PlayFabRequestCommon
        {
            std::string OrderId;
            std::string PlayFabId;
            std::string Reason;

            RefundPurchaseRequest() :
                PlayFabRequestCommon(),
                OrderId(),
                PlayFabId(),
                Reason()
            {}

            RefundPurchaseRequest(const RefundPurchaseRequest& src) :
                PlayFabRequestCommon(),
                OrderId(src.OrderId),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            ~RefundPurchaseRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("OrderId")], OrderId);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("Reason")], Reason);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[U("OrderId")] = each_OrderId;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Reason; ToJsonUtilS(Reason, each_Reason); output[U("Reason")] = each_Reason;
                return output;
            }
        };

        struct RefundPurchaseResponse : public PlayFabResultCommon
        {
            std::string PurchaseStatus;

            RefundPurchaseResponse() :
                PlayFabResultCommon(),
                PurchaseStatus()
            {}

            RefundPurchaseResponse(const RefundPurchaseResponse& src) :
                PlayFabResultCommon(),
                PurchaseStatus(src.PurchaseStatus)
            {}

            ~RefundPurchaseResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PurchaseStatus")], PurchaseStatus);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PurchaseStatus; ToJsonUtilS(PurchaseStatus, each_PurchaseStatus); output[U("PurchaseStatus")] = each_PurchaseStatus;
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

        struct RemoveServerBuildRequest : public PlayFabRequestCommon
        {
            std::string BuildId;

            RemoveServerBuildRequest() :
                PlayFabRequestCommon(),
                BuildId()
            {}

            RemoveServerBuildRequest(const RemoveServerBuildRequest& src) :
                PlayFabRequestCommon(),
                BuildId(src.BuildId)
            {}

            ~RemoveServerBuildRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("BuildId")], BuildId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_BuildId; ToJsonUtilS(BuildId, each_BuildId); output[U("BuildId")] = each_BuildId;
                return output;
            }
        };

        struct RemoveServerBuildResult : public PlayFabResultCommon
        {

            RemoveServerBuildResult() :
                PlayFabResultCommon()
            {}

            RemoveServerBuildResult(const RemoveServerBuildResult& src) :
                PlayFabResultCommon()
            {}

            ~RemoveServerBuildResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct RemoveVirtualCurrencyTypesRequest : public PlayFabRequestCommon
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            RemoveVirtualCurrencyTypesRequest() :
                PlayFabRequestCommon(),
                VirtualCurrencies()
            {}

            RemoveVirtualCurrencyTypesRequest(const RemoveVirtualCurrencyTypesRequest& src) :
                PlayFabRequestCommon(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            ~RemoveVirtualCurrencyTypesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("VirtualCurrencies")], VirtualCurrencies);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_VirtualCurrencies; ToJsonUtilO(VirtualCurrencies, each_VirtualCurrencies); output[U("VirtualCurrencies")] = each_VirtualCurrencies;
                return output;
            }
        };

        struct ResetCharacterStatisticsRequest : public PlayFabRequestCommon
        {
            std::string CharacterId;
            std::string PlayFabId;

            ResetCharacterStatisticsRequest() :
                PlayFabRequestCommon(),
                CharacterId(),
                PlayFabId()
            {}

            ResetCharacterStatisticsRequest(const ResetCharacterStatisticsRequest& src) :
                PlayFabRequestCommon(),
                CharacterId(src.CharacterId),
                PlayFabId(src.PlayFabId)
            {}

            ~ResetCharacterStatisticsRequest() { }

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

        struct ResetCharacterStatisticsResult : public PlayFabResultCommon
        {

            ResetCharacterStatisticsResult() :
                PlayFabResultCommon()
            {}

            ResetCharacterStatisticsResult(const ResetCharacterStatisticsResult& src) :
                PlayFabResultCommon()
            {}

            ~ResetCharacterStatisticsResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ResetPasswordRequest : public PlayFabRequestCommon
        {
            std::string Password;
            std::string Token;

            ResetPasswordRequest() :
                PlayFabRequestCommon(),
                Password(),
                Token()
            {}

            ResetPasswordRequest(const ResetPasswordRequest& src) :
                PlayFabRequestCommon(),
                Password(src.Password),
                Token(src.Token)
            {}

            ~ResetPasswordRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Password")], Password);
                FromJsonUtilS(input[U("Token")], Token);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Password; ToJsonUtilS(Password, each_Password); output[U("Password")] = each_Password;
                web::json::value each_Token; ToJsonUtilS(Token, each_Token); output[U("Token")] = each_Token;
                return output;
            }
        };

        struct ResetPasswordResult : public PlayFabResultCommon
        {

            ResetPasswordResult() :
                PlayFabResultCommon()
            {}

            ResetPasswordResult(const ResetPasswordResult& src) :
                PlayFabResultCommon()
            {}

            ~ResetPasswordResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ResetUserStatisticsRequest : public PlayFabRequestCommon
        {
            std::string PlayFabId;

            ResetUserStatisticsRequest() :
                PlayFabRequestCommon(),
                PlayFabId()
            {}

            ResetUserStatisticsRequest(const ResetUserStatisticsRequest& src) :
                PlayFabRequestCommon(),
                PlayFabId(src.PlayFabId)
            {}

            ~ResetUserStatisticsRequest() { }

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

        struct ResetUserStatisticsResult : public PlayFabResultCommon
        {

            ResetUserStatisticsResult() :
                PlayFabResultCommon()
            {}

            ResetUserStatisticsResult(const ResetUserStatisticsResult& src) :
                PlayFabResultCommon()
            {}

            ~ResetUserStatisticsResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct ResolvePurchaseDisputeRequest : public PlayFabRequestCommon
        {
            std::string OrderId;
            ResolutionOutcome Outcome;
            std::string PlayFabId;
            std::string Reason;

            ResolvePurchaseDisputeRequest() :
                PlayFabRequestCommon(),
                OrderId(),
                Outcome(),
                PlayFabId(),
                Reason()
            {}

            ResolvePurchaseDisputeRequest(const ResolvePurchaseDisputeRequest& src) :
                PlayFabRequestCommon(),
                OrderId(src.OrderId),
                Outcome(src.Outcome),
                PlayFabId(src.PlayFabId),
                Reason(src.Reason)
            {}

            ~ResolvePurchaseDisputeRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("OrderId")], OrderId);
                FromJsonEnum(input[U("Outcome")], Outcome);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("Reason")], Reason);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OrderId; ToJsonUtilS(OrderId, each_OrderId); output[U("OrderId")] = each_OrderId;
                web::json::value each_Outcome; ToJsonEnum(Outcome, each_Outcome); output[U("Outcome")] = each_Outcome;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_Reason; ToJsonUtilS(Reason, each_Reason); output[U("Reason")] = each_Reason;
                return output;
            }
        };

        struct ResolvePurchaseDisputeResponse : public PlayFabResultCommon
        {
            std::string PurchaseStatus;

            ResolvePurchaseDisputeResponse() :
                PlayFabResultCommon(),
                PurchaseStatus()
            {}

            ResolvePurchaseDisputeResponse(const ResolvePurchaseDisputeResponse& src) :
                PlayFabResultCommon(),
                PurchaseStatus(src.PurchaseStatus)
            {}

            ~ResolvePurchaseDisputeResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PurchaseStatus")], PurchaseStatus);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PurchaseStatus; ToJsonUtilS(PurchaseStatus, each_PurchaseStatus); output[U("PurchaseStatus")] = each_PurchaseStatus;
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

        struct RunTaskRequest : public PlayFabRequestCommon
        {
            Boxed<NameIdentifier> Identifier;

            RunTaskRequest() :
                PlayFabRequestCommon(),
                Identifier()
            {}

            RunTaskRequest(const RunTaskRequest& src) :
                PlayFabRequestCommon(),
                Identifier(src.Identifier)
            {}

            ~RunTaskRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Identifier")], Identifier);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output[U("Identifier")] = each_Identifier;
                return output;
            }
        };

        struct RunTaskResult : public PlayFabResultCommon
        {
            std::string TaskInstanceId;

            RunTaskResult() :
                PlayFabResultCommon(),
                TaskInstanceId()
            {}

            RunTaskResult(const RunTaskResult& src) :
                PlayFabResultCommon(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            ~RunTaskResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("TaskInstanceId")], TaskInstanceId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_TaskInstanceId; ToJsonUtilS(TaskInstanceId, each_TaskInstanceId); output[U("TaskInstanceId")] = each_TaskInstanceId;
                return output;
            }
        };

        struct SendAccountRecoveryEmailRequest : public PlayFabRequestCommon
        {
            std::string Email;
            std::string EmailTemplateId;

            SendAccountRecoveryEmailRequest() :
                PlayFabRequestCommon(),
                Email(),
                EmailTemplateId()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabRequestCommon(),
                Email(src.Email),
                EmailTemplateId(src.EmailTemplateId)
            {}

            ~SendAccountRecoveryEmailRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Email")], Email);
                FromJsonUtilS(input[U("EmailTemplateId")], EmailTemplateId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Email; ToJsonUtilS(Email, each_Email); output[U("Email")] = each_Email;
                web::json::value each_EmailTemplateId; ToJsonUtilS(EmailTemplateId, each_EmailTemplateId); output[U("EmailTemplateId")] = each_EmailTemplateId;
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

        struct SetPublishedRevisionRequest : public PlayFabRequestCommon
        {
            Int32 Revision;
            Int32 Version;

            SetPublishedRevisionRequest() :
                PlayFabRequestCommon(),
                Revision(),
                Version()
            {}

            SetPublishedRevisionRequest(const SetPublishedRevisionRequest& src) :
                PlayFabRequestCommon(),
                Revision(src.Revision),
                Version(src.Version)
            {}

            ~SetPublishedRevisionRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Revision")], Revision);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[U("Revision")] = each_Revision;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct SetPublishedRevisionResult : public PlayFabResultCommon
        {

            SetPublishedRevisionResult() :
                PlayFabResultCommon()
            {}

            SetPublishedRevisionResult(const SetPublishedRevisionResult& src) :
                PlayFabResultCommon()
            {}

            ~SetPublishedRevisionResult() { }

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

        struct SetupPushNotificationRequest : public PlayFabRequestCommon
        {
            std::string Credential;
            std::string Key;
            std::string Name;
            bool OverwriteOldARN;
            PushSetupPlatform Platform;

            SetupPushNotificationRequest() :
                PlayFabRequestCommon(),
                Credential(),
                Key(),
                Name(),
                OverwriteOldARN(),
                Platform()
            {}

            SetupPushNotificationRequest(const SetupPushNotificationRequest& src) :
                PlayFabRequestCommon(),
                Credential(src.Credential),
                Key(src.Key),
                Name(src.Name),
                OverwriteOldARN(src.OverwriteOldARN),
                Platform(src.Platform)
            {}

            ~SetupPushNotificationRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Credential")], Credential);
                FromJsonUtilS(input[U("Key")], Key);
                FromJsonUtilS(input[U("Name")], Name);
                FromJsonUtilP(input[U("OverwriteOldARN")], OverwriteOldARN);
                FromJsonEnum(input[U("Platform")], Platform);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Credential; ToJsonUtilS(Credential, each_Credential); output[U("Credential")] = each_Credential;
                web::json::value each_Key; ToJsonUtilS(Key, each_Key); output[U("Key")] = each_Key;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                web::json::value each_OverwriteOldARN; ToJsonUtilP(OverwriteOldARN, each_OverwriteOldARN); output[U("OverwriteOldARN")] = each_OverwriteOldARN;
                web::json::value each_Platform; ToJsonEnum(Platform, each_Platform); output[U("Platform")] = each_Platform;
                return output;
            }
        };

        struct SetupPushNotificationResult : public PlayFabResultCommon
        {
            std::string ARN;

            SetupPushNotificationResult() :
                PlayFabResultCommon(),
                ARN()
            {}

            SetupPushNotificationResult(const SetupPushNotificationResult& src) :
                PlayFabResultCommon(),
                ARN(src.ARN)
            {}

            ~SetupPushNotificationResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("ARN")], ARN);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_ARN; ToJsonUtilS(ARN, each_ARN); output[U("ARN")] = each_ARN;
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

        struct UpdateCatalogItemsRequest : public PlayFabRequestCommon
        {
            std::list<CatalogItem> Catalog;
            std::string CatalogVersion;
            Boxed<bool> SetAsDefaultCatalog;

            UpdateCatalogItemsRequest() :
                PlayFabRequestCommon(),
                Catalog(),
                CatalogVersion(),
                SetAsDefaultCatalog()
            {}

            UpdateCatalogItemsRequest(const UpdateCatalogItemsRequest& src) :
                PlayFabRequestCommon(),
                Catalog(src.Catalog),
                CatalogVersion(src.CatalogVersion),
                SetAsDefaultCatalog(src.SetAsDefaultCatalog)
            {}

            ~UpdateCatalogItemsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Catalog")], Catalog);
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilP(input[U("SetAsDefaultCatalog")], SetAsDefaultCatalog);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Catalog; ToJsonUtilO(Catalog, each_Catalog); output[U("Catalog")] = each_Catalog;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_SetAsDefaultCatalog; ToJsonUtilP(SetAsDefaultCatalog, each_SetAsDefaultCatalog); output[U("SetAsDefaultCatalog")] = each_SetAsDefaultCatalog;
                return output;
            }
        };

        struct UpdateCatalogItemsResult : public PlayFabResultCommon
        {

            UpdateCatalogItemsResult() :
                PlayFabResultCommon()
            {}

            UpdateCatalogItemsResult(const UpdateCatalogItemsResult& src) :
                PlayFabResultCommon()
            {}

            ~UpdateCatalogItemsResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdateCloudScriptRequest : public PlayFabRequestCommon
        {
            std::string DeveloperPlayFabId;
            std::list<CloudScriptFile> Files;
            bool Publish;

            UpdateCloudScriptRequest() :
                PlayFabRequestCommon(),
                DeveloperPlayFabId(),
                Files(),
                Publish()
            {}

            UpdateCloudScriptRequest(const UpdateCloudScriptRequest& src) :
                PlayFabRequestCommon(),
                DeveloperPlayFabId(src.DeveloperPlayFabId),
                Files(src.Files),
                Publish(src.Publish)
            {}

            ~UpdateCloudScriptRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DeveloperPlayFabId")], DeveloperPlayFabId);
                FromJsonUtilO(input[U("Files")], Files);
                FromJsonUtilP(input[U("Publish")], Publish);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DeveloperPlayFabId; ToJsonUtilS(DeveloperPlayFabId, each_DeveloperPlayFabId); output[U("DeveloperPlayFabId")] = each_DeveloperPlayFabId;
                web::json::value each_Files; ToJsonUtilO(Files, each_Files); output[U("Files")] = each_Files;
                web::json::value each_Publish; ToJsonUtilP(Publish, each_Publish); output[U("Publish")] = each_Publish;
                return output;
            }
        };

        struct UpdateCloudScriptResult : public PlayFabResultCommon
        {
            Int32 Revision;
            Int32 Version;

            UpdateCloudScriptResult() :
                PlayFabResultCommon(),
                Revision(),
                Version()
            {}

            UpdateCloudScriptResult(const UpdateCloudScriptResult& src) :
                PlayFabResultCommon(),
                Revision(src.Revision),
                Version(src.Version)
            {}

            ~UpdateCloudScriptResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Revision")], Revision);
                FromJsonUtilP(input[U("Version")], Version);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Revision; ToJsonUtilP(Revision, each_Revision); output[U("Revision")] = each_Revision;
                web::json::value each_Version; ToJsonUtilP(Version, each_Version); output[U("Version")] = each_Version;
                return output;
            }
        };

        struct UpdatePlayerSharedSecretRequest : public PlayFabRequestCommon
        {
            bool Disabled;
            std::string FriendlyName;
            std::string SecretKey;

            UpdatePlayerSharedSecretRequest() :
                PlayFabRequestCommon(),
                Disabled(),
                FriendlyName(),
                SecretKey()
            {}

            UpdatePlayerSharedSecretRequest(const UpdatePlayerSharedSecretRequest& src) :
                PlayFabRequestCommon(),
                Disabled(src.Disabled),
                FriendlyName(src.FriendlyName),
                SecretKey(src.SecretKey)
            {}

            ~UpdatePlayerSharedSecretRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Disabled")], Disabled);
                FromJsonUtilS(input[U("FriendlyName")], FriendlyName);
                FromJsonUtilS(input[U("SecretKey")], SecretKey);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Disabled; ToJsonUtilP(Disabled, each_Disabled); output[U("Disabled")] = each_Disabled;
                web::json::value each_FriendlyName; ToJsonUtilS(FriendlyName, each_FriendlyName); output[U("FriendlyName")] = each_FriendlyName;
                web::json::value each_SecretKey; ToJsonUtilS(SecretKey, each_SecretKey); output[U("SecretKey")] = each_SecretKey;
                return output;
            }
        };

        struct UpdatePlayerSharedSecretResult : public PlayFabResultCommon
        {

            UpdatePlayerSharedSecretResult() :
                PlayFabResultCommon()
            {}

            UpdatePlayerSharedSecretResult(const UpdatePlayerSharedSecretResult& src) :
                PlayFabResultCommon()
            {}

            ~UpdatePlayerSharedSecretResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdatePlayerStatisticDefinitionRequest : public PlayFabRequestCommon
        {
            Boxed<StatisticAggregationMethod> AggregationMethod;
            std::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;

            UpdatePlayerStatisticDefinitionRequest() :
                PlayFabRequestCommon(),
                AggregationMethod(),
                StatisticName(),
                VersionChangeInterval()
            {}

            UpdatePlayerStatisticDefinitionRequest(const UpdatePlayerStatisticDefinitionRequest& src) :
                PlayFabRequestCommon(),
                AggregationMethod(src.AggregationMethod),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval)
            {}

            ~UpdatePlayerStatisticDefinitionRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilE(input[U("AggregationMethod")], AggregationMethod);
                FromJsonUtilS(input[U("StatisticName")], StatisticName);
                FromJsonUtilE(input[U("VersionChangeInterval")], VersionChangeInterval);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AggregationMethod; ToJsonUtilE(AggregationMethod, each_AggregationMethod); output[U("AggregationMethod")] = each_AggregationMethod;
                web::json::value each_StatisticName; ToJsonUtilS(StatisticName, each_StatisticName); output[U("StatisticName")] = each_StatisticName;
                web::json::value each_VersionChangeInterval; ToJsonUtilE(VersionChangeInterval, each_VersionChangeInterval); output[U("VersionChangeInterval")] = each_VersionChangeInterval;
                return output;
            }
        };

        struct UpdatePlayerStatisticDefinitionResult : public PlayFabResultCommon
        {
            Boxed<PlayerStatisticDefinition> Statistic;

            UpdatePlayerStatisticDefinitionResult() :
                PlayFabResultCommon(),
                Statistic()
            {}

            UpdatePlayerStatisticDefinitionResult(const UpdatePlayerStatisticDefinitionResult& src) :
                PlayFabResultCommon(),
                Statistic(src.Statistic)
            {}

            ~UpdatePlayerStatisticDefinitionResult() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Statistic")], Statistic);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Statistic; ToJsonUtilO(Statistic, each_Statistic); output[U("Statistic")] = each_Statistic;
                return output;
            }
        };

        struct UpdatePolicyRequest : public PlayFabRequestCommon
        {
            bool OverwritePolicy;
            std::string PolicyName;
            std::list<PermissionStatement> Statements;

            UpdatePolicyRequest() :
                PlayFabRequestCommon(),
                OverwritePolicy(),
                PolicyName(),
                Statements()
            {}

            UpdatePolicyRequest(const UpdatePolicyRequest& src) :
                PlayFabRequestCommon(),
                OverwritePolicy(src.OverwritePolicy),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            ~UpdatePolicyRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("OverwritePolicy")], OverwritePolicy);
                FromJsonUtilS(input[U("PolicyName")], PolicyName);
                FromJsonUtilO(input[U("Statements")], Statements);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_OverwritePolicy; ToJsonUtilP(OverwritePolicy, each_OverwritePolicy); output[U("OverwritePolicy")] = each_OverwritePolicy;
                web::json::value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output[U("PolicyName")] = each_PolicyName;
                web::json::value each_Statements; ToJsonUtilO(Statements, each_Statements); output[U("Statements")] = each_Statements;
                return output;
            }
        };

        struct UpdatePolicyResponse : public PlayFabResultCommon
        {
            std::string PolicyName;
            std::list<PermissionStatement> Statements;

            UpdatePolicyResponse() :
                PlayFabResultCommon(),
                PolicyName(),
                Statements()
            {}

            UpdatePolicyResponse(const UpdatePolicyResponse& src) :
                PlayFabResultCommon(),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            ~UpdatePolicyResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("PolicyName")], PolicyName);
                FromJsonUtilO(input[U("Statements")], Statements);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_PolicyName; ToJsonUtilS(PolicyName, each_PolicyName); output[U("PolicyName")] = each_PolicyName;
                web::json::value each_Statements; ToJsonUtilO(Statements, each_Statements); output[U("Statements")] = each_Statements;
                return output;
            }
        };

        struct UpdateRandomResultTablesRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            std::list<RandomResultTable> Tables;

            UpdateRandomResultTablesRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                Tables()
            {}

            UpdateRandomResultTablesRequest(const UpdateRandomResultTablesRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                Tables(src.Tables)
            {}

            ~UpdateRandomResultTablesRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilO(input[U("Tables")], Tables);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_Tables; ToJsonUtilO(Tables, each_Tables); output[U("Tables")] = each_Tables;
                return output;
            }
        };

        struct UpdateRandomResultTablesResult : public PlayFabResultCommon
        {

            UpdateRandomResultTablesResult() :
                PlayFabResultCommon()
            {}

            UpdateRandomResultTablesResult(const UpdateRandomResultTablesResult& src) :
                PlayFabResultCommon()
            {}

            ~UpdateRandomResultTablesResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdateStoreItemsRequest : public PlayFabRequestCommon
        {
            std::string CatalogVersion;
            Boxed<StoreMarketingModel> MarketingData;
            std::list<StoreItem> Store;
            std::string StoreId;

            UpdateStoreItemsRequest() :
                PlayFabRequestCommon(),
                CatalogVersion(),
                MarketingData(),
                Store(),
                StoreId()
            {}

            UpdateStoreItemsRequest(const UpdateStoreItemsRequest& src) :
                PlayFabRequestCommon(),
                CatalogVersion(src.CatalogVersion),
                MarketingData(src.MarketingData),
                Store(src.Store),
                StoreId(src.StoreId)
            {}

            ~UpdateStoreItemsRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("CatalogVersion")], CatalogVersion);
                FromJsonUtilO(input[U("MarketingData")], MarketingData);
                FromJsonUtilO(input[U("Store")], Store);
                FromJsonUtilS(input[U("StoreId")], StoreId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_CatalogVersion; ToJsonUtilS(CatalogVersion, each_CatalogVersion); output[U("CatalogVersion")] = each_CatalogVersion;
                web::json::value each_MarketingData; ToJsonUtilO(MarketingData, each_MarketingData); output[U("MarketingData")] = each_MarketingData;
                web::json::value each_Store; ToJsonUtilO(Store, each_Store); output[U("Store")] = each_Store;
                web::json::value each_StoreId; ToJsonUtilS(StoreId, each_StoreId); output[U("StoreId")] = each_StoreId;
                return output;
            }
        };

        struct UpdateStoreItemsResult : public PlayFabResultCommon
        {

            UpdateStoreItemsResult() :
                PlayFabResultCommon()
            {}

            UpdateStoreItemsResult(const UpdateStoreItemsResult& src) :
                PlayFabResultCommon()
            {}

            ~UpdateStoreItemsResult() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct UpdateTaskRequest : public PlayFabRequestCommon
        {
            std::string Description;
            Boxed<NameIdentifier> Identifier;
            bool IsActive;
            std::string Name;
            web::json::value Parameter;
            std::string Schedule;
            ScheduledTaskType Type;

            UpdateTaskRequest() :
                PlayFabRequestCommon(),
                Description(),
                Identifier(),
                IsActive(),
                Name(),
                Parameter(),
                Schedule(),
                Type()
            {}

            UpdateTaskRequest(const UpdateTaskRequest& src) :
                PlayFabRequestCommon(),
                Description(src.Description),
                Identifier(src.Identifier),
                IsActive(src.IsActive),
                Name(src.Name),
                Parameter(src.Parameter),
                Schedule(src.Schedule),
                Type(src.Type)
            {}

            ~UpdateTaskRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Description")], Description);
                FromJsonUtilO(input[U("Identifier")], Identifier);
                FromJsonUtilP(input[U("IsActive")], IsActive);
                FromJsonUtilS(input[U("Name")], Name);
                Parameter = input[U("Parameter")];
                FromJsonUtilS(input[U("Schedule")], Schedule);
                FromJsonEnum(input[U("Type")], Type);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Description; ToJsonUtilS(Description, each_Description); output[U("Description")] = each_Description;
                web::json::value each_Identifier; ToJsonUtilO(Identifier, each_Identifier); output[U("Identifier")] = each_Identifier;
                web::json::value each_IsActive; ToJsonUtilP(IsActive, each_IsActive); output[U("IsActive")] = each_IsActive;
                web::json::value each_Name; ToJsonUtilS(Name, each_Name); output[U("Name")] = each_Name;
                output[U("Parameter")] = Parameter;
                web::json::value each_Schedule; ToJsonUtilS(Schedule, each_Schedule); output[U("Schedule")] = each_Schedule;
                web::json::value each_Type; ToJsonEnum(Type, each_Type); output[U("Type")] = each_Type;
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

        struct UpdateUserTitleDisplayNameRequest : public PlayFabRequestCommon
        {
            std::string DisplayName;
            std::string PlayFabId;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabRequestCommon(),
                DisplayName(),
                PlayFabId()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabRequestCommon(),
                DisplayName(src.DisplayName),
                PlayFabId(src.PlayFabId)
            {}

            ~UpdateUserTitleDisplayNameRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("DisplayName")], DisplayName);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_DisplayName; ToJsonUtilS(DisplayName, each_DisplayName); output[U("DisplayName")] = each_DisplayName;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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

    }
}

#endif
