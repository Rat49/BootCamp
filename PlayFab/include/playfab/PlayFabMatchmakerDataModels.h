#pragma once

#ifdef ENABLE_PLAYFABSERVER_API

#include "playfab/PlayFabBaseModel.h"

namespace PlayFab
{
    namespace MatchmakerModels
    {
        // Matchmaker Enums
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

        // Matchmaker Classes
        struct AuthUserRequest : public PlayFabRequestCommon
        {
            std::string AuthorizationTicket;

            AuthUserRequest() :
                PlayFabRequestCommon(),
                AuthorizationTicket()
            {}

            AuthUserRequest(const AuthUserRequest& src) :
                PlayFabRequestCommon(),
                AuthorizationTicket(src.AuthorizationTicket)
            {}

            ~AuthUserRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("AuthorizationTicket")], AuthorizationTicket);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_AuthorizationTicket; ToJsonUtilS(AuthorizationTicket, each_AuthorizationTicket); output[U("AuthorizationTicket")] = each_AuthorizationTicket;
                return output;
            }
        };

        struct AuthUserResponse : public PlayFabResultCommon
        {
            bool Authorized;
            std::string PlayFabId;

            AuthUserResponse() :
                PlayFabResultCommon(),
                Authorized(),
                PlayFabId()
            {}

            AuthUserResponse(const AuthUserResponse& src) :
                PlayFabResultCommon(),
                Authorized(src.Authorized),
                PlayFabId(src.PlayFabId)
            {}

            ~AuthUserResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("Authorized")], Authorized);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Authorized; ToJsonUtilP(Authorized, each_Authorized); output[U("Authorized")] = each_Authorized;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
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

        struct PlayerJoinedRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;
            std::string PlayFabId;

            PlayerJoinedRequest() :
                PlayFabRequestCommon(),
                LobbyId(),
                PlayFabId()
            {}

            PlayerJoinedRequest(const PlayerJoinedRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId),
                PlayFabId(src.PlayFabId)
            {}

            ~PlayerJoinedRequest() { }

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

        struct PlayerJoinedResponse : public PlayFabResultCommon
        {

            PlayerJoinedResponse() :
                PlayFabResultCommon()
            {}

            PlayerJoinedResponse(const PlayerJoinedResponse& src) :
                PlayFabResultCommon()
            {}

            ~PlayerJoinedResponse() { }

            void FromJson(web::json::value& input) override
            {
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                return output;
            }
        };

        struct PlayerLeftRequest : public PlayFabRequestCommon
        {
            std::string LobbyId;
            std::string PlayFabId;

            PlayerLeftRequest() :
                PlayFabRequestCommon(),
                LobbyId(),
                PlayFabId()
            {}

            PlayerLeftRequest(const PlayerLeftRequest& src) :
                PlayFabRequestCommon(),
                LobbyId(src.LobbyId),
                PlayFabId(src.PlayFabId)
            {}

            ~PlayerLeftRequest() { }

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

        struct PlayerLeftResponse : public PlayFabResultCommon
        {

            PlayerLeftResponse() :
                PlayFabResultCommon()
            {}

            PlayerLeftResponse(const PlayerLeftResponse& src) :
                PlayFabResultCommon()
            {}

            ~PlayerLeftResponse() { }

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

        struct StartGameRequest : public PlayFabRequestCommon
        {
            std::string Build;
            std::string CustomCommandLineData;
            std::string ExternalMatchmakerEventEndpoint;
            std::string GameMode;
            Region pfRegion;

            StartGameRequest() :
                PlayFabRequestCommon(),
                Build(),
                CustomCommandLineData(),
                ExternalMatchmakerEventEndpoint(),
                GameMode(),
                pfRegion()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabRequestCommon(),
                Build(src.Build),
                CustomCommandLineData(src.CustomCommandLineData),
                ExternalMatchmakerEventEndpoint(src.ExternalMatchmakerEventEndpoint),
                GameMode(src.GameMode),
                pfRegion(src.pfRegion)
            {}

            ~StartGameRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("Build")], Build);
                FromJsonUtilS(input[U("CustomCommandLineData")], CustomCommandLineData);
                FromJsonUtilS(input[U("ExternalMatchmakerEventEndpoint")], ExternalMatchmakerEventEndpoint);
                FromJsonUtilS(input[U("GameMode")], GameMode);
                FromJsonEnum(input[U("pfRegion")], pfRegion);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Build; ToJsonUtilS(Build, each_Build); output[U("Build")] = each_Build;
                web::json::value each_CustomCommandLineData; ToJsonUtilS(CustomCommandLineData, each_CustomCommandLineData); output[U("CustomCommandLineData")] = each_CustomCommandLineData;
                web::json::value each_ExternalMatchmakerEventEndpoint; ToJsonUtilS(ExternalMatchmakerEventEndpoint, each_ExternalMatchmakerEventEndpoint); output[U("ExternalMatchmakerEventEndpoint")] = each_ExternalMatchmakerEventEndpoint;
                web::json::value each_GameMode; ToJsonUtilS(GameMode, each_GameMode); output[U("GameMode")] = each_GameMode;
                web::json::value each_pfRegion; ToJsonEnum(pfRegion, each_pfRegion); output[U("Region")] = each_pfRegion;
                return output;
            }
        };

        struct StartGameResponse : public PlayFabResultCommon
        {
            std::string GameID;
            std::string ServerHostname;
            std::string ServerIPV6Address;
            Uint32 ServerPort;

            StartGameResponse() :
                PlayFabResultCommon(),
                GameID(),
                ServerHostname(),
                ServerIPV6Address(),
                ServerPort()
            {}

            StartGameResponse(const StartGameResponse& src) :
                PlayFabResultCommon(),
                GameID(src.GameID),
                ServerHostname(src.ServerHostname),
                ServerIPV6Address(src.ServerIPV6Address),
                ServerPort(src.ServerPort)
            {}

            ~StartGameResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilS(input[U("GameID")], GameID);
                FromJsonUtilS(input[U("ServerHostname")], ServerHostname);
                FromJsonUtilS(input[U("ServerIPV6Address")], ServerIPV6Address);
                FromJsonUtilP(input[U("ServerPort")], ServerPort);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_GameID; ToJsonUtilS(GameID, each_GameID); output[U("GameID")] = each_GameID;
                web::json::value each_ServerHostname; ToJsonUtilS(ServerHostname, each_ServerHostname); output[U("ServerHostname")] = each_ServerHostname;
                web::json::value each_ServerIPV6Address; ToJsonUtilS(ServerIPV6Address, each_ServerIPV6Address); output[U("ServerIPV6Address")] = each_ServerIPV6Address;
                web::json::value each_ServerPort; ToJsonUtilP(ServerPort, each_ServerPort); output[U("ServerPort")] = each_ServerPort;
                return output;
            }
        };

        struct UserInfoRequest : public PlayFabRequestCommon
        {
            Int32 MinCatalogVersion;
            std::string PlayFabId;

            UserInfoRequest() :
                PlayFabRequestCommon(),
                MinCatalogVersion(),
                PlayFabId()
            {}

            UserInfoRequest(const UserInfoRequest& src) :
                PlayFabRequestCommon(),
                MinCatalogVersion(src.MinCatalogVersion),
                PlayFabId(src.PlayFabId)
            {}

            ~UserInfoRequest() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilP(input[U("MinCatalogVersion")], MinCatalogVersion);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_MinCatalogVersion; ToJsonUtilP(MinCatalogVersion, each_MinCatalogVersion); output[U("MinCatalogVersion")] = each_MinCatalogVersion;
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

        struct UserInfoResponse : public PlayFabResultCommon
        {
            std::list<ItemInstance> Inventory;
            bool IsDeveloper;
            std::string PlayFabId;
            std::string SteamId;
            std::string TitleDisplayName;
            std::string Username;
            std::map<std::string, Int32> VirtualCurrency;
            std::map<std::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            UserInfoResponse() :
                PlayFabResultCommon(),
                Inventory(),
                IsDeveloper(),
                PlayFabId(),
                SteamId(),
                TitleDisplayName(),
                Username(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            UserInfoResponse(const UserInfoResponse& src) :
                PlayFabResultCommon(),
                Inventory(src.Inventory),
                IsDeveloper(src.IsDeveloper),
                PlayFabId(src.PlayFabId),
                SteamId(src.SteamId),
                TitleDisplayName(src.TitleDisplayName),
                Username(src.Username),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            ~UserInfoResponse() { }

            void FromJson(web::json::value& input) override
            {
                FromJsonUtilO(input[U("Inventory")], Inventory);
                FromJsonUtilP(input[U("IsDeveloper")], IsDeveloper);
                FromJsonUtilS(input[U("PlayFabId")], PlayFabId);
                FromJsonUtilS(input[U("SteamId")], SteamId);
                FromJsonUtilS(input[U("TitleDisplayName")], TitleDisplayName);
                FromJsonUtilS(input[U("Username")], Username);
                FromJsonUtilP(input[U("VirtualCurrency")], VirtualCurrency);
                FromJsonUtilO(input[U("VirtualCurrencyRechargeTimes")], VirtualCurrencyRechargeTimes);
            }

            web::json::value ToJson() const override
            {
                web::json::value output;
                web::json::value each_Inventory; ToJsonUtilO(Inventory, each_Inventory); output[U("Inventory")] = each_Inventory;
                web::json::value each_IsDeveloper; ToJsonUtilP(IsDeveloper, each_IsDeveloper); output[U("IsDeveloper")] = each_IsDeveloper;
                web::json::value each_PlayFabId; ToJsonUtilS(PlayFabId, each_PlayFabId); output[U("PlayFabId")] = each_PlayFabId;
                web::json::value each_SteamId; ToJsonUtilS(SteamId, each_SteamId); output[U("SteamId")] = each_SteamId;
                web::json::value each_TitleDisplayName; ToJsonUtilS(TitleDisplayName, each_TitleDisplayName); output[U("TitleDisplayName")] = each_TitleDisplayName;
                web::json::value each_Username; ToJsonUtilS(Username, each_Username); output[U("Username")] = each_Username;
                web::json::value each_VirtualCurrency; ToJsonUtilP(VirtualCurrency, each_VirtualCurrency); output[U("VirtualCurrency")] = each_VirtualCurrency;
                web::json::value each_VirtualCurrencyRechargeTimes; ToJsonUtilO(VirtualCurrencyRechargeTimes, each_VirtualCurrencyRechargeTimes); output[U("VirtualCurrencyRechargeTimes")] = each_VirtualCurrencyRechargeTimes;
                return output;
            }
        };

    }
}

#endif
