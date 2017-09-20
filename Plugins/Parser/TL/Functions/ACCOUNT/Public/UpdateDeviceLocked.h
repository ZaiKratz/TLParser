#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class UpdateDeviceLocked : public TLBaseObject
{
public:
	UpdateDeviceLocked();
	UpdateDeviceLocked(int32 period);

	~UpdateDeviceLocked();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 period;
	bool result;
};
} //end namespace block
