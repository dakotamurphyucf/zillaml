/*----------------------------------------------------------------------------
 *  Copyright (c) 2019-2020 António Nuno Monteiro
 *  Copyright (c) 2019-2020 Dakota Murphy
 * 
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *  this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright
 *  notice, this list of conditions and the following disclaimer in the
 *  documentation and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its
 *  contributors may be used to endorse or promote products derived from this
 *  software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/

type descriptor = [ | `Ssl_not_available];

open Async;

module Io:
  Gluten_async_intf.IO with
    type socket = descriptor and type addr = Socket.Address.Inet.t = {
  type socket = descriptor;

  type addr = Socket.Address.Inet.t;

  let read = (_, _bigstring, ~off as _, ~len as _) =>
    failwith("Ssl not available");

  let writev = (_, _iovecs) => failwith("Ssl not available");

  let shutdown_send = _ => failwith("Ssl not available");

  let shutdown_receive = _ => failwith("Ssl not available");

  let close = _ => failwith("Ssl not available");
};

let make_default_client = (~alpn_protocols as _=?, _socket) =>
  Core.failwith("Ssl not available");

[@ocaml.warning "-21"]
let make_server = (~alpn_protocols as _=?, ~certfile as _, ~keyfile as _) => {
  failwith("Ssl not available");
  _socket => Core.failwith("Ssl not available");
};
