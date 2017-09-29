#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class Authorization : public TLBaseObject
{
public:
	Authorization();
	Authorization(unsigned long long hash, int32 flags, FString device_model, FString platform, FString system_version, int32 api_id, FString app_name, FString app_version, int32 date_created, int32 date_active, FString ip, FString country, FString region);

	~Authorization();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Gethash() const
	{
		 return this->hash;
	}

	int32 Getflags() const
	{
		 return this->flags;
	}

	FString GetDeviceModel() const
	{
		 return this->device_model;
	}

	FString Getplatform() const
	{
		 return this->platform;
	}

	FString GetSystemVersion() const
	{
		 return this->system_version;
	}

	int32 GetApiId() const
	{
		 return this->api_id;
	}

	FString GetAppName() const
	{
		 return this->app_name;
	}

	FString GetAppVersion() const
	{
		 return this->app_version;
	}

	int32 GetDateCreated() const
	{
		 return this->date_created;
	}

	int32 GetDateActive() const
	{
		 return this->date_active;
	}

	FString Getip() const
	{
		 return this->ip;
	}

	FString Getcountry() const
	{
		 return this->country;
	}

	FString Getregion() const
	{
		 return this->region;
	}

private:
	unsigned long long hash;
	 int32 flags;
	 FString device_model;
	 FString platform;
	 FString system_version;
	 int32 api_id;
	 FString app_name;
	 FString app_version;
	 int32 date_created;
	 int32 date_active;
	 FString ip;
	 FString country;
	 FString region;
};
} //end namespace block
