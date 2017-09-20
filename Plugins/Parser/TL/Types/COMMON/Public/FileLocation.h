#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class FileLocation : public TLBaseObject
{
public:
	FileLocation();
	FileLocation(int32 dc_id, unsigned long long volume_id, int32 local_id, unsigned long long secret);

	~FileLocation();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 dc_id;
	 unsigned long long volume_id;
	 int32 local_id;
	 unsigned long long secret;
};
} //end namespace block
