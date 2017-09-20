#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/FileLocation.h"

//begin namespace block
namespace COMMON
{
class FileLocationUnavailable : public TLBaseObject
{
public:
	FileLocationUnavailable();
	FileLocationUnavailable(unsigned long long volume_id, int32 local_id, unsigned long long secret);

	~FileLocationUnavailable();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long volume_id;
	 int32 local_id;
	 unsigned long long secret;
};
} //end namespace block
