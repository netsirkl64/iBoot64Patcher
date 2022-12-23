//
//  vmem.hpp
//  liboffsetfinder64
//
//  Created by tihmstar on 28.09.19.
//  Copyright © 2019 tihmstar. All rights reserved.
//

#ifndef vmem_hpp
#define vmem_hpp

#include <libinsn/vsegment.hpp>

namespace tihmstar{
    namespace libinsn{

        class vmem{
            uint32_t _segNum;
            std::vector<vsegment> _segments;
            
            insn myop_plus(int i, uint32_t segNum);
            insn myop_minus(int i, uint32_t segNum);
            
        public:
            vmem(const std::vector<vsegment> segments, int perm = vsegment::kVMPROTEXEC);
            vmem(const vmem& copy, libinsn::loc_t pos = 0, int perm = vsegment::kVMPROTEXEC);

            vsegment seg(loc_t pos);
            
            uint64_t deref(loc_t pos);
            loc_t memmem(const void *little, size_t little_len, loc_t startLoc = 0);
            loc_t memstr(const char *little);
            bool isInRange(loc_t pos) noexcept;

            /*--segment functions but for vmem--*/
            //iterator operator
            insn operator+(int i);
            insn operator-(int i);
            insn operator++();
            insn operator--();
            vmem &operator+=(int i);
            vmem &operator-=(int i);
            vmem &operator=(loc_t p);
            
            void nextSeg();
            void prevSeg();

            //segment info functions
            int curPerm() const;
            vsegment curSeg();
            const vsegment curSeg() const;
            const vsegment segmentForLoc(loc_t loc);
            const void *memoryForLoc(loc_t loc);

            
            //deref operator
            uint64_t pc();
            uint32_t value(loc_t p); //arbitrary pos
            uint64_t doublevalue(loc_t p); //arbitrary pos
            uint32_t value(); //curpos
            uint64_t doublevalue(); //curpos
            
            //insn operator
            insn getinsn();
            insn operator()();
            operator loc_t() const;
        };
        
    };
};
#endif /* vmem_hpp */
