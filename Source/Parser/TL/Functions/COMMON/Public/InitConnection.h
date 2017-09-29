#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InitConnection : public TLBaseObject
{
public:
	InitConnection();
	InitConnection(int32 api_id, FString device_model, FString system_version, FString app_version, FString system_lang_code, FString lang_pack, FString lang_code, TLBaseObject* query);

	~InitConnection();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetApiId() const
	{
		 return this->api_id;
	}

	FString GetDeviceModel() const
	{
		 return this->device_model;
	}

	FString GetSystemVersion() const
	{
		 return this->system_version;
	}

	FString GetAppVersion() const
	{
		 return this->app_version;
	}

	FString GetSystemLangCode() const
	{
		 return this->system_lang_code;
	}

	FString GetLangPack() const
	{
		 return this->lang_pack;
	}

	FString GetLangCode() const
	{
		 return this->lang_code;
	}

	TLBaseObject*  Getquery() const
	{
		 return this->query;
	}

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	int32 api_id;
	 FString device_model;
	 FString system_version;
	 FString app_version;
	 FString system_lang_code;
	 FString lang_pack;
	 FString lang_code;
	 TLBaseObject* query;
	TLBaseObject* result;
};
} //end namespace block
