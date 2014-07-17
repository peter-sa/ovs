/*
 * Copyright (c) 2014 Nicira, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PACKET_DPIF_H
#define PACKET_DPIF_H 1

#include "ofpbuf.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* A packet received from a netdev and passed to a dpif. */

struct dpif_packet {
    struct ofpbuf ofpbuf;       /* Packet data. */
    uint32_t dp_hash;           /* Packet hash. */
};

struct dpif_packet *dpif_packet_new_with_headroom(size_t size,
                                                  size_t headroom);

struct dpif_packet *dpif_packet_clone_from_ofpbuf(const struct ofpbuf *b);

struct dpif_packet *dpif_packet_clone(struct dpif_packet *p);

static inline void dpif_packet_delete(struct dpif_packet *p)
{
    struct ofpbuf *ofp = &p->ofpbuf;

    ofpbuf_delete(ofp);
}

#ifdef  __cplusplus
}
#endif

#endif /* packet-dpif.h */
