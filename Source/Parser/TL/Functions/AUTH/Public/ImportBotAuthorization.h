#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/Authorization.h"

//begin namespace block
namespace AUTH
{
class ImportBotAuthorization : public TLBaseObject
{
public:
	ImportBotAuthorization();
	ImportBotAuthorization(int32 flags, int32 api_id, FString api_hash, FString bot_auth_token);

	~ImportBotAuthorization();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getflags() const
	{
		 return this->flags;
	}

	int32 GetApiId() const
	{
		 return this->api_id;
	}

	FString GetApiHash() const
	{
		 return this->api_hash;
	}

	FString GetBotAuthToken() const
	{
		 return this->bot_auth_token;
	}

	AUTH::Authorization* GetResult() const
	{
		 return this->result;
	}

private:
	int32 flags;
	 int32 api_id;
	 FString api_hash;
	 FString bot_auth_token;
	AUTH::Authorization* result;
};
} //end namespace block
