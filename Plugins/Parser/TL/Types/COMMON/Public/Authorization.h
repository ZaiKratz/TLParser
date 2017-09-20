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
